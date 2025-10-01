#include <iostream>

using namespace std;

void printArray(int array[], int length) {
  cout << "Array : ( ";
  for (int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << ")" << endl;
}

const int max_size = 1000;

int main() {
  int m;
  cin >> m;

  int size = 0;
  int array[max_size];

  for (int i = 0; i < m; i++) {
    char o;
    cin >> o;
    if (o == 'I') {
      int y, p;
      cin >> y >> p;

      if (p >= 0 && p <= size) {
        for (int j = size; j > p; j--) {
          array[j] = array[j - 1];
        }
        array[p] = y;
        size++;
      } else {
        array[size++] = y;
      }
    } else if (o == 'D') {
      int p;
      cin >> p;
      if (p >= 0 && p < size) {
        for (int j = p; j < size - 1; j++) {
          array[j] = array[j + 1];
        }
        size--;
      }
    }
  }

  int query;
  cin >> query;
  for (int i = 0; i < query; i++) {
    int item;
    cin >> item;
    bool found = false;
    for (int j = 0; j < size; j++) {
      if (array[j] == item) {
        found = true;
        break;
      }
    }
    cout << (found ? "YES" : "NO") << "\n";
  }

  return 0;
}
