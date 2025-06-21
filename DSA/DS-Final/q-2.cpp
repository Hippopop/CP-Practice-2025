#include<bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
     int arr[5] = {22,22,41,1,1},n=5,j,i;

     cout<<"Orginal Array"<<endl;

     printArray(arr,5);

     selection_sort(arr,5);
     
     cout<<"Sorted Array"<<endl;
     printArray(arr,5);

}