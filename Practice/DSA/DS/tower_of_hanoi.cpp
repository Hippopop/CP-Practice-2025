#include <iostream>
using namespace std;

void towerOfHanoi(int length, char start, char destination, char auxilary) {
  if (length == 1) {
    cout << "Move Disk 1 : From " << start << " To " << destination << "."
         << endl;
    return;
  }
  towerOfHanoi(length - 1, start, auxilary, destination);
  cout << "Move Disk " << length << " : From " << start << " To " << destination
       << "." << endl;
  towerOfHanoi(length - 1, auxilary, destination, start);
}

int main() {
  // STEP COUNT -> (2^n - 1)
  towerOfHanoi(5, 'A', 'C', 'B');
  return 0;
}