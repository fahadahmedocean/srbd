//
//
//#include<stdio.h>
//#define maxx 30
//
//long graph[maxx][maxx];
//int visit[maxx];
//int t,n;
//
//void dfs(int u)
//{
//    int i;
//    visit[u]=1;
//    for(i=0; i<n; i++)
//    {
//        if(graph[u][i]==1  && !visit[i] )
//        {
//            dfs(i);
//        }
//    }
//}
//
//
//
//int main()
//{
//    char str[6];
//    int t;
//    int a, b;
//    scanf("%d",&t);
//    getchar();
//    getchar();
//
//    while(t--)
//    {
//        graph[maxx][maxx]= {0};
//        visit[maxx]= {0};
//
//        gets(str);
//        n=str[0] - 'A'+1;
//
//
//        while(gets(str) )
//        {
//            if(str[0]=='\0')
//                break;
//            a = str[0] - 'A';
//            b = str[1] - 'A';
//            // cout<<"a "<<a<<" b "<<b<<endl;
//            graph[a][b]=1;
//            graph[b][a]=1;
//        }
//
//        int u;
//        int cnt = 0;
//        for(u=0; u<n; u++)
//        {
//            if(!visit[u])
//            {
//                cnt++;
//                dfs(u);
//
//            }
//
//        }
//        printf("%d\n",cnt);
//        if(t)
//            printf("\n");
//    }
//
//    return 0;
//}
//
//

#include<bits/stdc++.h>
#include<queue>


using namespace std;



vector<int>graph[50001];

int color[50001];

int t,nodes,edges,k,u;

void visit_dfs(int u)
{
    int i,v;
    color[u]=1;
    for(i=0;i<graph[u].size();i++)
    {
        v=graph[u][i];
        if(color[v]==0)
        {
            visit_dfs(v);
        }
    }
    color[u] = 2;
}



int main()
{
        char str[3];
        int t,n;
        int a , b;
        scanf("%d",&t);
        scanf("\n");
         while(t--)
         {
            int xz = 0;
            gets(str);
            n=str[0] - 'A';
            memset(graph,NULL,sizeof(graph));
            memset(color,0,sizeof(color));
            while(gets(str) && str[0])
            {
                a = str[0] - 'A';
                b = str[1] - 'A';
                graph[a].push_back(b);
                graph[b].push_back(a);
            }

        int u ,v, j;

     for(u=0;u<=n;u++)
     {
            if(color[u]==0)
            {
               visit_dfs(u);
               xz++;
            }

    }
    printf("%d\n",xz);
    if(t)
    printf("\n");
    }

    return 0;
}
