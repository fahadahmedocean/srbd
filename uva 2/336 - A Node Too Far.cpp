#include<bits/stdc++.h>

using namespace std;
map< int, int > visited;

void BFS(int scr, map< int, vector< int > >adjmap)
{
    queue< int >q;
    q.push(scr);
    visited[scr] = 0;
    while(!q.empty())
    {q.pop();
        int top = q.front();
        for(int i=0; i<adjmap[top].size(); i++)
        {
            int n = adjmap[top][i];
            if(!visited.count(n))
            {
                visited[n] = visited[top] + 1;
                q.push(n);
            }
        }

    }
}



int main()
{
    int edge, cases=0;
    while(scanf("%d",&edge)==1 )
    {
        if (edge==0)
            break;
        map< int,vector< int > >adjmap;

        for(int i=0; i<edge; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            adjmap[n1].push_back(n2);
            adjmap[n2].push_back(n1);
        }


        int ttl, source;
        while(scanf("%d %d", &source, &ttl)==2)
        {
            if(source==0 && ttl==0)
                break;


            visited.clear();
            BFS(source,adjmap);

            int count=0;
            map< int, int>::iterator it;
            for(it=visited.begin(); it!=visited.end(); ++it)
            {

                if((*it).second>ttl)
                {
                    ++count;
                }
            }

            count = count + adjmap.size()-visited.size();

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,count, source, ttl);
        }
    }
    return 0;
}
