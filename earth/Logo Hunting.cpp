#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[50][50];

int h=0;
int dx[]= {0,-1,1,0};
int dy[]= {1,0,0,-1};
vector<char> v;
void zerostox(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return;
    }
    else if(a[x][y]!='.')
        return;
    else if(a[x][y]=='.')
        a[x][y]='X';
    else
        return;
    for(int i=0; i<4; i++)
    {
        zerostox(x+dx[i],y+dy[i]);
    }
}
void handle(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return;
    }

    if(a[x][y]=='1')
        a[x][y]='X';
    else if(a[x][y]=='.')
    {
        h++;
        zerostox(x,y);
    }
    else
        return;

    for(int i=0; i<4; i++)
    {
        handle(x+dx[i],y+dy[i]);
    }
}
void process()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            h=0;
            if(a[i][j]=='1')
            {
                handle(i,j);
                if(h==0)
                    v.push_back('F');
                else if(h==1)
                    v.push_back('O');
                else if(h==2)
                    v.push_back('P');
            }
        }
    }

}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    zerostox(0,0);
    process();
    sort(v.begin(),v.end());
    if(v.size()==0)
        cout<<"N";
    else
    {
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i];
        }
    }
    cout<<endl;



}
