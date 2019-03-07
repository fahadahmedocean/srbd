#include<bits/stdc++.h>
using namespace std;
int stak[210],top=-1,visited[210],n,arr[210][210];


void push(int val)
{
    top++;
    stak[top]=val;
}

int pop()
{
    int ver=stak[top];
    top--;
    printf("%d\t",ver);
    return ver;
}

int stakempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}


void dfs(int start_vertex)
{
    push(start_vertex);

    visited[start_vertex]=1;

    while(!stakempty())
    {
        int i;
        int v=pop();
        for(i=1; i<=n; i++)
        {
            if(   !    (! (arr[v][i]))    && !(visited[i])   )
            {
                push(i);
                visited[i]=1;
            }
        }
    }
}


int main()
{

    int i,j,start_vertex,edge;
    scanf("%d",&n);
    cin>>edge;
    int a,b;

    //input adjacent matrix
    for(i=0; i<edge; i++)
    {
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    // starting point
    int cnt=0;
    for(int k=1; k<=n;k++)
    {
        if (visited[k]==0)
        {
            dfs(k);
            cnt++;

        }
    }
    cout<<"\ncnt: "<<cnt<<endl;



    return 0;
}

