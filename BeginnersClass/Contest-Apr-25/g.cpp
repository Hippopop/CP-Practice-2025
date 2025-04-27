#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const string endW = "\n";
void solution()
{
    long long int n;
    cin >> n;

    cout << ((n * (n + 1)) / 2);
};

int main()
{
    solution();
    cout << endW;

    return 0;
}