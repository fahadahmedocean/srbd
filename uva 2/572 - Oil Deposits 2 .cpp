//  572 Oil Deposits
#include<bits/stdc++.h>
using namespace std;

int m,n,counter;
char a[101][101];
int visited[101][101];


int valid(int r,int c)
{
    if(r>=0&&r<m&&c>=0&&c<n)
        return true;
    return false;
}
void floodfill(int r,int c)
{

    visited[r][c]=1;
    if(valid(r+1,c)&&a[r+1][c]=='@'&&!visited[r+1][c])
        floodfill(r+1,c);
    if(valid(r-1,c)&&a[r-1][c]=='@'&&!visited[r-1][c])
        floodfill(r-1,c);
    if(valid(r,c+1)&&a[r][c+1]=='@'&&!visited[r][c+1])
        floodfill(r,c+1);
    if(valid(r,c-1)&&a[r][c-1]=='@'&&!visited[r][c-1])
        floodfill(r,c-1);

    if(valid(r-1,c-1)&&a[r-1][c-1]=='@'&&!visited[r-1][c-1])
        floodfill(r-1,c-1);
    if(valid(r-1,c+1)&&a[r-1][c+1]=='@'&&!visited[r-1][c+1])
        floodfill(r-1,c+1);
    if(valid(r+1,c-1)&&a[r+1][c-1]=='@'&&!visited[r+1][c-1])
        floodfill(r+1,c-1);
    if(valid(r+1,c+1)&&a[r+1][c+1]=='@'&&!visited[r+1][c+1])
        floodfill(r+1,c+1);
}

int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0)
            break;
        getchar();
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%c",&a[i][j]);
            }
            getchar();
        }
        memset(visited,0,sizeof(visited));
        counter=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(!visited[i][j]&&a[i][j]=='@')
                {
                    counter++;

                    floodfill(i,j);
                }
            }
        }
        cout<<counter<<endl;
    }
}
