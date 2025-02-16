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
void countingSort(int array[], int min, int max);

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
  countingSort(array, min, max);
  cout << "Sorted ";
  printArray(array);
  cout << endl << endl << endl;

  return 0;
}

void countingSort(int array[], int min, int max) {
  int store[max + 1];
  for (int i = 0; i <= max; i++)
    store[i] = 0;

  for (int i = 0; i < length; i++)
    store[array[i]]++;

  int index = 0;
  for (int i = 0; i <= max; i++) {
    int val = store[i];
    for (int j = 0; j < val; j++) {
      array[index] = i;
      index++;
    }
  }
}