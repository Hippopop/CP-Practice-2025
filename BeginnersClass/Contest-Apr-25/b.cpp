#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution()
{
    long long int n;
    cin >> n;
    if (n & 1 && n != 1)
    {
        cout << "YES" << endW;
        long long int halfTotal = (n * ((n + 1) / 2)) / 2;

        vector<int> delimiter(n + 1, 0);

        long long int currentTotal = 0;
        long long int count = 0;
        for (int i = n; i > 0; i--)
        {
            if ((currentTotal + i) <= halfTotal)
            {
                currentTotal += i;
                delimiter[i] = 1;
                count++;
            }
            if (currentTotal == halfTotal)
                break;
        }

        long long int rest = (n - count);

        cout << count << endW;
        for (int i = n; i > 0 && count; i--)
        {
            if (delimiter[i])
            {
                cout << i << " ";
                count--;
            }
        }

        cout << endW << rest << endW;
        for (int i = 1; (i <= n) && rest; i++)
        {
            if (!delimiter[i])
            {
                cout << i << " ";
                rest--;
            }
        }
    }
    else
        cout << "NO";
};

int main()
{
    solution();
    cout << endW;

    return 0;
}