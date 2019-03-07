#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int dp[MAX][MAX];

// Return the length of LIP in 2D matrix
int LIP(int dp[][MAX], int mat[][MAX], int n, int m, int x, int y)
{
    // If value not calculated yet.
    if (dp[x][y] < 0)
    {
        int result = 0;

        // If reach bottom left cell, return 1.
        if (x == n-1 && y == m-1)
            return dp[x][y] = 1;

        // If reach the corner of the matrix.
        if (x == n-1 || y == m-1)
            result = 1;

        // If value greater than below cell.
        if (mat[x][y] < mat[x+1][y])
            result = 1 + LIP(dp, mat, n, m, x+1, y);

        // If value greater than left cell.
        if (mat[x][y] < mat[x][y+1])
            result = max(result, 1 + LIP(dp, mat, n, m, x, y+1));

        dp[x][y] = result;
    }



    return dp[x][y];
}

// Wrapper function
int wrapper(int mat[][MAX], int n, int m)
{

    memset(dp, -1, sizeof dp);

    return LIP(dp, mat, n, m, 0, 0);
}

// Driven Program
int main()
{
    int mat[][MAX] =
    {
        { 1, 2, 3, 4 },
        { 2, 2, 3, 4 },
        { 3, 2, 3, 4 },
        { 4, 5, 6, 7 },
    };
    int n = 4, m = 4;
    cout << wrapper(mat, n, m) << endl;

    for(int i=0; i<MAX; i++)
    {
        for(int k=0; k<MAX; k++)
            if(dp[i][k]!=-1)
            cout<<dp[i][k]<<" ";
        //cout<<endl;
    }

    return 0;
}
