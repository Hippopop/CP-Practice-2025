#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const string endW = "\n";
void solution()
{
    string date;
    cin >> date;
    int month = stoi(date.substr(5, 7));
    int day = stoi(date.substr(8, 10));

    if (month > 4)
    {
        cout << "TBD";
        return;
    }

    if (month < 4)
    {
        cout << "Heisei";
        return;
    }

    if (day >= 30)
    {
        cout << "Heisei";
        return;
    }

    cout << "TBD";
    return;
};

int main()
{
    solution();
    cout << endW;

    return 0;
}