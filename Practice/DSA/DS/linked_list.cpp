#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

void printLinkedList(Node *head) {
  Node *temp = head;
  cout << "Current List: ";
  while (temp != nullptr) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtBeginning(Node *&head, int value) {
  Node *current = new Node(value);

  if (head == nullptr) {
    head = current;
  } else {
    current->next = head;
    head = current;
    return;
  }
}

void insertAtEnd(Node *&head, int value) {
  Node *current = new Node(value);

  if (head == nullptr) {
    head = current;
  } else {
    Node *point = head;
    while (head->next != nullptr) {
      point = point->next;
    }
    point->next = current;
  }
}

void insertAtPosition(Node *&head, int pos, int val) {
  Node *current = head;
  for (int i = 0; current != nullptr && i < val; i++) {
    current = current->next;
  }

  if (current == nullptr) {
    cout << "Out of bound!" << endl;
    return;
  }

  Node *newNode = new Node(val);
  newNode->next = current->next;
  current->next = newNode;
}

void putBeforeValue(Node *&head, int value, int newValue) {
  Node *newNode = new Node(newValue);
  Node *current = head;

  while (current != nullptr && current->next != nullptr) {
    if (current->next->value == value)
      break;
    current = current->next;
  }

  if (current == nullptr) {
    cout << "Not found!";
    return;
  }

  cout << "Crossed " << 1 << endl;

  if (current->value == value) {
    newNode->next = head;
    head = newNode;
    return;
  }

  cout << "Crossed " << 2 << endl;

  if (current->next->value == value) {
    newNode->next = current->next;
    current->next = newNode;
    return;
  }

  cout << "Crossed " << 3 << endl;

  cout << "Not Found";
}

int main() {
  Node *head = nullptr;
  insertAtEnd(head, 55);
  insertAtEnd(head, 56);
  insertAtEnd(head, 57);
  insertAtEnd(head, 58);
  insertAtBeginning(head, 54);

  // putBeforeValue(head, 57, 123);

  printLinkedList(head);
  return 0;
}