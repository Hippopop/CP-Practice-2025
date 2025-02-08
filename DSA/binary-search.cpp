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
bool binarySearch(int array[], int target, int left, int right);

int main() {
  int *array = randomArrayGenerator();
  printArray(array);

  // Start Process!!
  selectionSort(array);
  printArray(array);

  int target = (rand() % 2) ? (rand() % limit) : array[rand() % length];
  cout << "The result of searching " << target << " is: "
       << (binarySearch(array, target, 0, length - 1) ? "Found!" : "Not Found!")
       << endl;

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

// NOTE: Requires the array to be sorted first!!
bool binarySearch(int array[], int target, int left, int right) {
  if (left > right)
    return false;

  int mid = (left + right) / 2;
  int midValue = array[mid];
  if (midValue == target)
    return true;

  if (midValue > target)
    return binarySearch(array, target, left, mid - 1);
  else
    return binarySearch(array, target, mid + 1, right);
}