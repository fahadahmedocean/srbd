#include <bits/stdc++.h>

using namespace std;

typedef signed long long ull;

vector<ull>g[100005];

ull vis[100005]= {0},rectree[100005]= {0},ans=1,node=1;

void dfs(ull s)

{

    vis[s]=1;

    for(ull i=0; i<g[s].size(); i++)

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

    ull n,m;

    cin>>n>>m;

    for(ull i=0; i<m; i++)

    {

        ull x,y;

        cin>>x>>y;

        g[x].push_back(y);

    }

    for(ull i=1; i<=n; i++)

    {

        rectree[i]=1;

        if(vis[i]==0)

            dfs(i);

        if(ans==0)

        {

            break;

        }

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

        for(ull i=1; i<=n; i++)

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
