#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
bool dp[11][11];
void flood_fill(int x, int y, int xmax, int ymax)
{
    dp[x][y] = true;

    if(y>1 and arr[x][y-1]==1 and dp[x][y-1]==false)
    {
        flood_fill(x,y-1,xmax,ymax);
    }

    if(y<ymax and arr[x][y+1]==1 and dp[x][y+1]==false)
    {
        flood_fill(x,y+1,xmax,ymax);
    }

    if(x>1 and arr[x-1][y]==1 and dp[x-1][y]==false)
    {
        flood_fill(x-1,y,xmax,ymax);
    }

    if(x<xmax and arr[x+1][y]==1 and dp[x+1][y]==false)
    {
        flood_fill(x+1,y,xmax,ymax);
    }
}
int main()
{

    int r, c;
    cin >> r >> c;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            dp[i][j] = false;
            cin >> arr[i][j];
        }
    }
    if(arr[1][1]==1 and dp[1][1]==false)
    {
        flood_fill(1,1,r,c);
    }
    if(dp[r][c])
        cout << "Yes" << endl;
    else
        cout << "No" <<endl;

    return 0;
}
