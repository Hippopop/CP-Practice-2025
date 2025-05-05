#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution() {
  long long int m, n;
  cin >> n >> m;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<long long int> history(n, 0);
  unordered_set<long long int> found;
  for (int i = n - 1; i >= 0; i--) {
    found.insert(arr[i]);
    history[i] = found.size();
  }

  while (m--) {
    long long int pos;
    cin >> pos;
    cout << history[pos - 1] << endW;
  }
};

int main() {
  solution();
  cout << endW;

  return 0;
}