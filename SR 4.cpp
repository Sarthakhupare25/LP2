#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isSafe(int **arr, int n, int x, int y)
{
    // for column
    for (int i = 0; i < n; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }

    // for left diagonal
    int row = x;
    int col = y;
    while (row >= 0 and col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // for right diagonal
    row = x;
    col = y;
    while (row >= 0 and col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void nQeen(int **arr, int n, int col)
{
    if (col >= n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, n, col, i))
        {
            arr[col][i] = 1;
            nQeen(arr, n, col + 1);
            arr[col][i] = 0;
        }
    }
}
int main()
{
    cout << "Enter the size of the grid : " << endl;
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    nQeen(arr, n, 0);
    bool flag = true;
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No Possible Solution for value : " << n << endl;
    }

    return 0;
}