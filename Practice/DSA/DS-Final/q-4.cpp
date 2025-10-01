#include <bits/stdc++.h>

using namespace std;

class NODE
{
public:
    int value;
    NODE *next;
};
NODE *Head = NULL;
NODE *Last = NULL;

void print(NODE *h)
{
    while (h != NULL)
    {
        cout << h->value << endl;
        h = h->next;
    }
}

void removeFromMiddle(NODE *start, int targetValue)
{
    NODE* next = start->next;
    while(next->value != targetValue && next != NULL) {
        NODE* temp = next;
        start = next;
        next = next->next;
    }

    if(next->value == targetValue && next->next != NULL) { // Added the second condition just so the last element doesn't get removed!
        NODE* temp = next->next;
        start->next = temp;
    }
}

int main()
{

    NODE *n1 = new NODE();
    Head = n1;
    n1->value = 71;

    NODE *n2 = new NODE();
    n2->value = 1;
    n1->next = n2;

    NODE *n3 = new NODE();
    n3->value = 12;
    n2->next = n3;

    NODE *n4 = new NODE();
    n4->value = 52;
    n3->next = n4;

    print(Head);

    removeFromMiddle(Head, 12);
    cout << "After Removal: " << endl;
    print(Head);
}