#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int limit = 1000;
int length = 12; // NOTE: Change the static array length with this too!!
int *randomArrayGenerator() {
  srand(time(0));
  static int array[12]; // NOTE: Static Array!
  for (int i = 0; i < length; i++)
    array[i] = rand() % limit;
  return array;
}

void printArray(int array[]) {
  cout << "Array : ( ";
  for (int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << ")" << endl;
}

// Functions!!
void selectionSort(int *array);

int main() {
  int *array = randomArrayGenerator();
  printArray(array);

  // Start Process!!
  selectionSort(array);
  cout << "Sorted ";
  printArray(array);

  return 0;
}

void selectionSort(int array[]) {
  for (int i = 0; i < (length - 1); i++) {
    int l_i = i;
    for (int j = i + 1; j < length; j++) {
      if (array[l_i] > array[j]) {
        l_i = j;
      }
    }
    swap(array[i], array[l_i]);
  }
}