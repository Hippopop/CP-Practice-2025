#include <algorithm>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;
static const char endW = '\n';

// <Merge Sort>
template <typename T>
void merge(vector<T> &arr, li left, li mid, li right, bool comp(T a, T b)) {

  li n1 = mid - left + 1;
  li n2 = right - mid;

  vector<T> L, R;
  for (li i = 0; i < n1; i++)
    L.push_back(arr[left + i]);
  for (li j = 0; j < n2; j++)
    R.push_back(arr[mid + 1 + j]);

  li i = 0, j = 0;
  li k = left;
  while (i < n1 && j < n2) {
    if (comp(L[i], R[j])) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

template <typename T>
void mergeSort(vector<T> &items, li left, li right, bool comp(T a, T b)) {
  if (left >= right)
    return;

  li mid = left + (right - left) / 2;
  mergeSort(items, left, mid, comp);
  mergeSort(items, mid + 1, right, comp);
  merge<T>(items, left, mid, right, comp);
}
// </Merge Sort>

class Octopus {

public:
  Octopus(int a, string x) {
    this->a = a;
    this->x = x;
  };
  int a;
  string x;
};

void solution() {
  vector<Octopus> vec = {
      Octopus(99, "a"),
      Octopus(2, "b"),
      Octopus(45, "c"),
      Octopus(4, "d"),
  };

  mergeSort<Octopus>(vec, 0, vec.size() - 1,
                     [](Octopus a, Octopus b) { return a.a > b.a; });
  for (auto i : vec) {
    cout << i.a << " " << i.x << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}