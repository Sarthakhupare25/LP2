#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    cout << "Enter the number of Elements : ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection_Sort(arr, n);
    return 0;
}