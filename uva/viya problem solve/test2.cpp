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
