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
void insertionSort(int array[]);

int main() {
  int *array = randomArrayGenerator();
  printArray(array);

  // Start Process!!
  int min = array[0], max = array[0];
  for (int x = 0; x < length; x++) {
    if (array[x] > max)
      max = array[x];
    if (array[x] < min)
      min = array[x];
  }
  insertionSort(array);
  cout << "Sorted ";
  printArray(array);

  cout << endl << endl << endl;
  return 0;
}

void insertionSort(int array[]) {
  for (int step = 1; step < length; step++) {
    int key = array[step];
    int j = step - 1;
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}