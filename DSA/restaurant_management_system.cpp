#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct MenuItem {
  int id;
  string name;
  double price;
};

struct OrderedItem {
  int itemId;
  int quantity;
};

struct OrderNode {
  int orderId;
  string customerName;
  vector<OrderedItem> orderedItems;
  int tableId;
  int memberCount;
  OrderNode *next;
};

struct Table {
  int id;
  int capacity;
  bool isOccupied;
};

// Global state encapsulated
vector<MenuItem> menu;
OrderNode *orderHead = nullptr;
vector<OrderNode *> orderHistory;
// stack<int> orderStack;
// queue<int> orderQueue;
vector<vector<pair<int, int>>> tableGraph;
map<int, Table> tables;
int orderCounter = 1001;
string systemMessage;
double totalRevenue = 0;
int completedOrders = 0;

map<int, stack<int>> inventoryStock;
int nextItemId = 1;

// Forward declarations
void displayStatusGrid();
void displayMenu();
void initMenuItems();
void initTables();
void showTableStatus();
int linearSearchMenu(int id);
void bubbleSortMenuByPrice(vector<MenuItem> &menu);
void insertionSortMenuByPriceDescending(vector<MenuItem> &menu);
int allocateTable(int members);
void freeTable(int tableId);
void addOrder(const string &name, const vector<OrderedItem> &items,
              int members);
void deleteOrder(int orderId);
void listOrders();
void generateBillPrompt();
void primMST(int V);
void clearScreen();

void viewInventory() {
  cout << "\n--- INVENTORY STATUS ---\n";
  for (auto &item : menu) {
    cout << "ID:" << item.id << " | " << item.name << " | $" << item.price
         << " | Stock:" << inventoryStock[item.id].size() << "\n";
  }
  cout << "------------------------\n";
}

void restockInventory() {
  displayMenu();
  cout << "Enter meal serial to restock: ";
  int serial, qty;
  cin >> serial;
  if (serial < 1 || serial > (int)menu.size()) {
    cout << "Invalid serial.\n";
    return;
  }
  cout << "Quantity to add: ";
  cin >> qty;
  int id = menu[serial - 1].id;
  for (int i = 0; i < qty; ++i)
    inventoryStock[id].push(1);
  cout << "Restocked " << qty << " units of " << menu[serial - 1].name << ".\n";
}

void initInventory() {
  for (const auto &item : menu) {
    auto &stk = inventoryStock[item.id];
    for (int i = 0; i < 50; ++i) {
      stk.push(1);
    }
  }
}

void addNewInventoryItem() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter new meal name: ";
  string name;
  getline(cin, name);
  cout << "Enter price: ";
  double price;
  cin >> price;
  cout << "Enter initial stock quantity: ";
  int qty;
  cin >> qty;
  int id = nextItemId++;
  menu.push_back({id, name, price});
  for (int i = 0; i < qty; ++i)
    inventoryStock[id].push(1);
  cout << "Added " << name << " (ID " << id << ") with " << qty << " units.\n";
}

// Admin authentication and actions
void adminPanel() {
  const string USER = "admin";
  const string PASS = "admin123";
  cout << "Enter admin username: ";
  string u;
  cin >> u;
  cout << "Enter password: ";
  string p;
  cin >> p;
  if (u != USER || p != PASS) {
    systemMessage = "Access Denied!";
    return;
  }
  int choice;
  do {
    clearScreen();
    cout << "\n=== ADMIN PANEL ===\n";
    cout << "1. View Inventory\n";
    cout << "2. Restock Item\n";
    cout << "3. Add New Menu+Stock\n";
    cout << "4. Logout Admin Panel\n";
    cout << "Choice: ";
    cin >> choice;
    clearScreen();
    switch (choice) {
    case 1:
      viewInventory();
      break;
    case 2:
      restockInventory();
      break;
    case 3:
      addNewInventoryItem();
      break;
    case 4:
      systemMessage = "Exited admin panel.";
      break;
    default:
      cout << "Invalid choice.\n";
    }
    if (choice != 4) {
      cout << "\nPress Enter to return to admin menu...";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
    }
  } while (choice != 4);
}

// Utility functions
void clearScreen() { system("clear"); }

// Display status grid with manual spacing and safe padding
void displayStatusGrid() {
  int pendingOrders = 0, seatsTaken = 0;
  for (OrderNode *temp = orderHead; temp; temp = temp->next) {
    ++pendingOrders;
    seatsTaken += temp->memberCount;
  }
  int totalSeats = 0, seatsOccupied = 0;
  for (auto &kv : tables) {
    totalSeats += kv.second.capacity;
    if (kv.second.isOccupied)
      seatsOccupied += kv.second.capacity;
  }
  int availableSeats = totalSeats - seatsOccupied;

  cout << "==================== RM-SYSTEM ====================\n\n";
  cout << "==================== DASHBOARD ====================\n";
  cout << "Pending Orders: " << pendingOrders << string(12, ' ')
       << "Seats Taken: " << seatsTaken << "\n";
  cout << "Completed Orders: " << completedOrders << string(10, ' ')
       << "Available Seats: " << availableSeats << "\n";
  cout << "\t\tTotal Revenue: $" << fixed << setprecision(2) << totalRevenue
       << string(11, ' ') << "\n\n";
  cout << "===================================================\n";

  vector<pair<string, string>> opts = {
      {"1.Show Menu", "2.Place Order"},
      {"3.Show Orders", "4.Cancel Order"},
      {"5.Sort Menu (Ascending)", "6.Sort Menu (Descending)"},
      {"7.Optimize Layout", "8.Show Tables"},
      {"9.Search Item", "10.Generate Bill"},
      {"11.Admin Panel", "0.Exit\n\n"},
  };
  const size_t colWidth = 26; // safe fixed width
  for (auto &row : opts) {
    size_t pad =
        (row.first.length() < colWidth) ? (colWidth - row.first.length()) : 4;
    cout << row.first << string(pad, ' ') << row.second << "\n";
  }

  cout << "Select an option (0-10): ";
}

void displayMenu() {
  cout << "--- MENU ---\n";
  for (int i = 0; i < (int)menu.size(); ++i) {
    cout << i + 1 << ". " << menu[i].name << " - $" << menu[i].price << "\n";
  }
  cout << endl;
}

int linearSearchMenu(int id) {
  for (int i = 0; i < (int)menu.size(); ++i)
    if (menu[i].id == id)
      return i;
  return -1;
}

void bubbleSortMenuByPrice(vector<MenuItem> &menu) {
  int n = menu.size();
  for (int i = 0; i < n - 1; ++i) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (menu[j].price > menu[j + 1].price) {
        swap(menu[j], menu[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void insertionSortMenuByPriceDescending(vector<MenuItem> &menu) {
  int n = menu.size();
  for (int i = 1; i < n; ++i) {
    MenuItem key = menu[i];
    int j = i - 1;

    // Move items that are cheaper than key one position ahead
    while (j >= 0 && menu[j].price < key.price) {
      menu[j + 1] = menu[j];
      --j;
    }
    menu[j + 1] = key;
  }
}

void initMenuItems() {
  menu = {
      {1, "Kacchi", 300.00}, {2, "Polao", 180.00},   {3, "Dim-Bhat", 120.00},
      {4, "Mojo", 20.00},    {5, "Borhani", 100.00},
  };
  nextItemId = menu.size() + 1;
}

void initTables() {
  for (int i = 1; i <= 5; ++i)
    tables[i] = {i, i * 2, false};
}

void showTableStatus() {
  cout << "--- TABLE STATUS ---\n";
  for (auto &kv : tables) {
    cout << "Table " << kv.second.id << " (Capacity: " << kv.second.capacity
         << ") - " << (kv.second.isOccupied ? "Occupied" : "Available") << "\n";
  }
  cout << endl;
}

int allocateTable(int members) {
  for (auto &kv : tables) {
    if (!kv.second.isOccupied && kv.second.capacity >= members) {
      kv.second.isOccupied = true;
      return kv.first;
    }
  }
  return -1;
}

void freeTable(int tableId) {
  if (tables.count(tableId))
    tables[tableId].isOccupied = false;
}

/* void addOrder(const string &name, const vector<OrderedItem> &items,
              int members) {
  int tableId = allocateTable(members);
  if (tableId == -1) {
    systemMessage =
        "No available table for " + to_string(members) + " members.";
    return;
  }

  OrderNode *node = new OrderNode{
      orderCounter++, name.empty() ? "Anonymous" : name,
      items,          tableId,
      members,        orderHead,
  };
  orderHead = node;
  // orderStack.push(node->orderId);
  // orderQueue.push(node->orderId);
  systemMessage = "Order placed! Table " + to_string(tableId);
} */

void addOrder(const string &name, const vector<OrderedItem> &items, int mem) {
  // inventory check
  for (auto &oi : items)
    if (inventoryStock[oi.itemId].size() < oi.quantity) {
      systemMessage = "Insufficient stock.";
      return;
    }
  // consume
  for (auto &oi : items)
    for (int i = 0; i < oi.quantity; ++i)
      inventoryStock[oi.itemId].pop();
  int tid = allocateTable(mem);
  if (tid == -1) {
    systemMessage = "No table.";
    return;
  }
  auto *nd = new OrderNode{orderCounter++, name, items, tid, mem, orderHead};
  orderHead = nd;
  systemMessage = "Order placed, Table" + to_string(tid);
}

/* void deleteOrder(int orderId) {
  OrderNode *temp = orderHead;
  OrderNode *prev = nullptr;
  while (temp && temp->orderId != orderId) {
    prev = temp;
    temp = temp->next;
  }
  if (!temp) {
    systemMessage = "Order not found.";
    return;
  }
  freeTable(temp->tableId);
  orderHistory.push_back(new OrderNode(*temp));
  if (prev)
    prev->next = temp->next;
  else
    orderHead = temp->next;
  delete temp;

  systemMessage = "Order canceled.";
} */

void deleteOrder(int orderId) {
  OrderNode *temp = orderHead;
  OrderNode *prev = nullptr;
  // Find the order in linked list
  while (temp && temp->orderId != orderId) {
    prev = temp;
    temp = temp->next;
  }
  if (!temp) {
    systemMessage = "Order not found.";
    return;
  }
  // Free the table
  freeTable(temp->tableId);
  // Return items to inventory
  for (auto &oi : temp->orderedItems) {
    for (int i = 0; i < oi.quantity; ++i) {
      inventoryStock[oi.itemId].push(1);
    }
  }
  // Archive order
  orderHistory.push_back(new OrderNode(*temp));
  // Remove from current orders list
  if (prev)
    prev->next = temp->next;
  else
    orderHead = temp->next;
  delete temp;
  systemMessage = "Order canceled and items restocked.";
}

void listOrders() {
  cout << "--- CURRENT ORDERS ---\n";
  for (OrderNode *temp = orderHead; temp; temp = temp->next) {
    cout << "Order ID: " << temp->orderId
         << ", Customer: " << temp->customerName << ", Table: " << temp->tableId
         << ", Members: " << temp->memberCount << "\n";
  }
  cout << "--- ******* ****** ---\n";
  cout << endl;
}

void generateBillPrompt() {
  listOrders();
  cout << "Enter Order ID to bill (0 to cancel): ";
  int id;
  if (!(cin >> id) || id == 0) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
  }
  OrderNode *temp = orderHead;
  while (temp && temp->orderId != id)
    temp = temp->next;
  if (!temp) {
    systemMessage = "Order not found.";
    return;
  }
  double subtotal = 0;
  cout << "--- BILL ---\nCustomer: " << temp->customerName
       << "\nTable: " << temp->tableId << "\nItems:\n";
  for (auto &oi : temp->orderedItems) {
    int idx = linearSearchMenu(oi.itemId);
    if (idx != -1) {
      double price = menu[idx].price * oi.quantity;
      cout << "  " << menu[idx].name << " x" << oi.quantity << " - $" << price
           << "\n";
      subtotal += price;
    }
  }
  double tip;
  cout << "Subtotal: $" << subtotal << "\nTip: $";
  cin >> tip;
  double total = subtotal + tip;
  cout << "Total: $" << total << "\n";
  deleteOrder(id);
  totalRevenue += total;
  ++completedOrders;
  systemMessage = "Order " + to_string(id) + " completed. (Received $" +
                  to_string(total) + ")";
}

void addTableEdge(int u, int v, int w) {
  tableGraph[u].push_back({v, w});
  tableGraph[v].push_back({u, w});
}

void primMST(int V) {
  vector<bool> used(V, false);
  vector<int> key(V, INT_MAX);
  key[0] = 0;
  for (int i = 0; i < V - 1; ++i) {
    int u = -1;
    for (int j = 0; j < V; ++j)
      if (!used[j] && (u < 0 || key[j] < key[u]))
        u = j;
    used[u] = true;
    for (auto &p : tableGraph[u])
      if (!used[p.first] && p.second < key[p.first])
        key[p.first] = p.second;
  }
  systemMessage = "Optimized table layout.";
}

int main() {
  initMenuItems();
  initTables();
  initInventory();
  tableGraph.resize(5);
  addTableEdge(0, 1, 2);
  addTableEdge(1, 2, 3);
  addTableEdge(0, 3, 6);
  addTableEdge(3, 4, 1);

  int choice;
  do {
    clearScreen();
    if (!systemMessage.empty()) {
      cout << "*** " << systemMessage << " ***\n\n";
      systemMessage.clear();
    }
    displayStatusGrid();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
    switch (choice) {
    case 1:
      displayMenu();
      break;
    case 2: {
      string name;
      int members, count;
      cout << "Customer Name (opt): ";
      getline(cin, name);
      cout << "Members: ";
      if (!(cin >> members)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        systemMessage = "Invalid.";
        break;
      }
      displayMenu();
      cout << "How many distinct meals? ";
      if (!(cin >> count) || count <= 0) {
        systemMessage = "Invalid count.";
        break;
      }
      vector<OrderedItem> items;
      for (int i = 0; i < count; ++i) {
        int serial, qty;
        cout << "Enter meal serial: ";
        cin >> serial;
        if (serial < 1 || serial > menu.size()) {
          systemMessage = "Invalid serial.";
          break;
        }
        cout << "Quantity: ";
        cin >> qty;
        if (qty <= 0) {
          systemMessage = "Invalid qty.";
          break;
        }
        items.push_back({menu[serial - 1].id, qty});
      }
      addOrder(name, items, members);
    } break;
    case 3:
      listOrders();
      break;
    case 4: {
      listOrders();
      int id;
      cout << "Order ID to cancel: ";
      cin >> id;
      deleteOrder(id);
    } break;
    case 5: {
      bubbleSortMenuByPrice(menu);
      systemMessage = "Menu sorted by price in ascending order.";
    } break;
    case 6: {
      insertionSortMenuByPriceDescending(menu);
      systemMessage = "Menu sorted by price in descending order.";
    } break;
    case 7:
      primMST(5);
      break;
    case 8:
      showTableStatus();
      break;
    case 9: {
      string query;
      cout << "Enter meal name to search: ";
      getline(cin, query);
      bool found = false;
      for (auto &m : menu) {
        if (m.name == query) {
          systemMessage = "Found: " + m.name + " - $" + to_string(m.price);
          found = true;
          break;
        }
      }
      if (!found)
        systemMessage = "Not found.";
    } break;
    case 10:
      generateBillPrompt();
      break;
    case 11:
      adminPanel();
      break;
    }
    if (choice != 0 && choice != 5 && choice != 6 && choice != 9) {
      cout << "\nPress Enter...";
      cin.get();
    }
  } while (choice != 0);
  return 0;
}
