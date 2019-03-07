#include <bits/stdc++.h>
using namespace std;

int g[1005][1005]= {};
int vis[1005]= {0},rectree[1005]= {0},ans=1,node=1,n;

void dfs(int s)
{
    vis[s]=1;
    for(int i=0; i<n; i++)
    {
        if(rectree[g[s][i]]==1 && ans==1)
        {
            ans=0;
            node=g[s][i];
            return;
        }

        if(vis[g[s][i]]==0)
        {
            rectree[g[s][i]]=1;
            dfs(g[s][i]);
            if(ans==1)
                rectree[g[s][i]]=0;
        }
    }
}

int main()
{
    int m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
    }

    for(int i=1; i<=n; i++)
    {
        rectree[i]=1;
        if(vis[i]==0)
            dfs(i);
        if(ans==0)
            break;
        rectree[i]=0;
    }

    if(ans==0)
    {
        cout<<"CYCLE\n";
        memset(vis,0,sizeof(vis));
        memset(rectree,0,sizeof(rectree));
        ans=1;
        rectree[node]=1;

        dfs(node);
        for(int i=1; i<=n; i++)
        {
            if(rectree[i]==1)
                cout<<i<<" ";
        }
        cout<<node<<endl;
    }

    else
        cout<<"NO CYCLE\n";

    return 0;

}
