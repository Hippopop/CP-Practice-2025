#include <iostream>
#include <set>

using namespace std;

static const string endW = "\n";
void solution()
{
    long long int n;
    cin >> n;

    set<long long int> store;
    bool isEven = (n % 2) == 0;
    for (int i = isEven ? 2 : 3; i < ((n / 2) + 1); i += 2)
    {
        if (n % i == 0)
        {
            store.insert(i);
            store.insert(n / i);
        }
    }

    cout << store.size() + 2;
};

int main()
{
    long long int _;
    cin >> _;
    while (_--)
    {
        solution();
        cout << endW;
    }

    return 0;
}