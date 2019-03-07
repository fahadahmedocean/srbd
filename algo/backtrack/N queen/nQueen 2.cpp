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
