#include<iostream>
using namespace std;

bool check=false;

void print(int board[10][10],int n)
{
    check=true;
    int i=0,j=0;
    cout<<"[";
    while(j<n)
    {
        i=0;
        while(i<n)
        {
            if(board[i][j]==1)
                cout<<i+1<<" ";
            i++;
        }
        j++;
    }
    cout<<"] ";
}
bool safe(int board[10][10],int col,int row,int n)
{
    if(board[row][col]==1)
        return false;

    int i,j;
    for(i=0; i<col; i++)
        if(board[row][i])
            return false;

    for(i=row,j=col; i>=0&&j>=0; i--,j--)
        if(board[i][j])
            return false;

    for(i=row,j=col; i<n&&j>=0; i++,j--)
        if(board[i][j])
            return false;

    return true;
}
void solve(int board[10][10],int col,int n)
{
    if(col>=n)
    {
        print(board,n);
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(safe(board,col,i,n))
        {
            board[i][col]=1;
            solve(board,col+1,n);
            board[i][col]=0;
        }
    }
}
int main()
{
    int t,n,board[10][10];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board[i][j]=0;

        check=false;
        solve(board,0,n);
        if(check==false)
            cout<<-1;
        cout<<endl;
    }
    return 0;
}









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















#include<iostream>
#include <stdio.h>
using namespace std;


int fx,fy,line;

void print(int board[10][10],int n)
{
    printf("%2d      ",line++);
    for(int c=0; c<n; c++)
    {
        for(int r=0; r<n; r++)
            if(board[r][c]==1)
                printf("%d ", r + 1);
    }

    cout<<endl;
}



bool safe(int board[10][10],int col,int row,int n)
{
    if(board[row][col]==1)
        return false;

    int i,j;

    for(i=0; i<col; i++)
        if(board[row][i])
            return false;

    //right diagnol upper
    for(i=row,j=col; i>=0&&j>=0; i--,j--)
        if(board[i][j])
            return false;

    //left diagnol
    for(i=row,j=col; i<n&&j>=0; i++,j--)
        if(board[i][j])
            return false;

    return true;
}
void nQueen(int board[10][10],int col,int n)
{
    if(col>=n)
    {
        if (board[fx-1][fy-1]==1)
            print(board,n);
        return;
    }

    for(int i=0; i<n; i++)

    {
        if(board[i][col]!=1)
            if(safe(board,col,i,n))
            {
                board[i][col]=1;
                nQueen(board,col+1,n);

                board[i][col]=0;
            }
    }
}
int main()
{
    int t,n=8,board[10][10];
    cin>>t;
    while(t--)
    {

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board[i][j]=0;

        cin>>fx>>fy;


        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        line=1;
        nQueen(board,0,n);
        if(t)
            printf("\n");

    }
    return 0;
}
