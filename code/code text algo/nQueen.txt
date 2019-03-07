#include <bits/stdc++.h>
using namespace std;

// N x N chessboard
#define N 4

// Function to check if two queens threaten each other or not
bool isSafe(char mat[N][N], int r, int c)
{

    if(mat[r][c]=='Q')
        return false;

    // return false if two queens share the same column
    for (int i = 0; i < r; i++)
        if (mat[i][c] == 'Q')
            return false;

    // return false if two queens share the same \ diagonal
     /* Check upper diagonal on left side */
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 'Q')
            return false;

    // return false if two queens share the same / diagonal

    /* Check lower diagonal on left side */
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if (mat[i][j] == 'Q')
            return false;

    return true;
}

void nQueen(char mat[N][N], int r)
{
    // if N queens are placed successfully, print the solution
    if (r == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return;
    }

    // place Queen at every square in current row r
    // and recurse for each valid movement
    for (int c = 0; c < N; c++)
    {
        // if no two queens threaten each other
        if (isSafe(mat, r, c))
        {
            // place queen on current square
            mat[r][c] = 'Q';

            // recurse for next row
            nQueen(mat, r + 1);

            // backtrack and remove queen from current square
            mat[r][c] = '-';
        }
    }
}

int main()
{

    char mat[N][N];
    //initialize
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            mat[i][j]='-';



    nQueen(mat, 0);

    return 0;
}
