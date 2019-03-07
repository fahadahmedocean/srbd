#include <bits/stdc++.h>
using namespace std;

const int maxx= 1001 ;      // number of nodes
int mat[maxx][maxx] ;     // adjacency list to store graph
bool vis[maxx];
int par[maxx],node;               // stores parent of each node according to bfs traversal

int Qu[maxx*maxx], frnt = 0, rear = -1;
//int level[maxx], parent[maxx];
//int flug=1;
int cflug;

int isEmpty()
{
    if(frnt> rear)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear == node-1)
        return 1;
    else
        return 0;
}

void enQu(int data)
{
    if(isFull())
        return;
    else
    {
        rear++;
        Qu[rear] = data;
        return;
    }
}

int deQu()
{
    int data;
    if(isEmpty())
        return -1;
    else
    {
        data = Qu[frnt];
        frnt++;
        return data;
    }
}



bool cycle_check()
{
    par[1] = 0;            // start bfs from any node I have started from 1
    Qu[maxx*maxx]= {};
    enQu(1);

    while(!isEmpty())
    {
        int u = deQu();

        for(int i = 0 ; i<node ; i++)
        {
            int v = mat[u][i];
            if(par[v]==u)
                continue;
            else if(vis[v]==1)
            {

                return true;            // there is a node v that is not parent of this node u so there is a cycle
            }
            par[v] = u;              // set u as parent of v
            vis[v] = 1;
            enQu(v);              // push v in queue
        }
    }
    return false;
}
int main()
{
    int edge;     // n- nodes   m-edges
    cin>>node>>edge;
    // nodes numbered from 1 to n
    for(int i = 0 ; i<edge ; i++)
    {
        int u, v;
        cin>>u>>v;
        mat[u][v]=1;
        mat[v][u]=1;

    }
    if(cycle_check())
    {
        cout<<"Cycle present"<<endl;
//        while (par[cflug]!= 0)
//        {
//            cout<< par[cflug]<<" ";
//            cflug = par[cflug];
//        }
        // return 0;
    }
    else
    {
        cout<<"Cycle not present"<<endl;
        return 0;
    }


//        for (int k = 1; k <= node; k++)
//            cout<<par[k]<<" ";
//        cout<<endl;

}
