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
void bubbleSort(int *array);

int main() {
  int *array = randomArrayGenerator();
  printArray(array);

  // Start Process!!
  bubbleSort(array);
  cout << "Sorted ";
  printArray(array);
  cout << endl << endl << endl;
  return 0;
}

void bubbleSort(int array[]) {
  for (int j = 0; j < length; j++)
    for (int i = 0; i < (length - 1) - j; i++) {
      if (array[i] > array[i + 1])
        swap(array[i], array[i + 1]);
    }
}