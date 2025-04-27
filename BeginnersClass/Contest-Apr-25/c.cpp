#include <iostream>
#include <map>
#include <set>

using namespace std;

map<long long int, set<long long int>> history;

static const string endW = "\n";
void solution() {
  long long int m, n;
  cin >> n >> m;
  long long int arr[n];
  set<long long int> unique;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    unique.insert(arr[i]);
  }
  history[0] = unique;

  for (int i = 0; i < m; i++) {
    long long int pos;
    cin >> pos;
    set<long long int> u;
    for (int i = pos - 1; i < n; i++) {
      if (history.count(i) > 0) {
        u.merge(history[i]);
        cout << "Prev(" << i + 1 << ") : " << history[i].size() << endW;
        break;
      }
      u.insert(arr[i]);
    }

    cout << "Pos: " << pos << " || Size: " << u.size() << endW;

    history[pos - 1] = u;
    cout << u.size() << endW;
  }
};

int main() {
  solution();
  cout << endW;

  return 0;
}