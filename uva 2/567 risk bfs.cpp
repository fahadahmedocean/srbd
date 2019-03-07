#include<bits/stdc++.h>
#define maxx 20
using namespace std;

int  adjMat[maxx][maxx], level[maxx];
int queueElement[maxx], frontElement = 0, rear = -1;

int isEmpty()
{
    if(frontElement>rear)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == 19)
        return 1;
    else
        return 0;
}

void enqueueElement(int data)
{
    if(isFull())
        return;
    else
    {
        rear++;
        queueElement[rear] = data;
        return;
    }

}

int dequeueElement()
{
    int data;
    if(isEmpty())
        return -1;
    else
    {
        data = queueElement[frontElement];
        frontElement++;
        return data;
    }
}

void bfs(int source,int destination)
{
    for(int i=1 ; i <= maxx ; i++)
    {
        level[i]=-1;
    }

    int  u;

    enqueueElement(source);
    level[source] = 0;

    while(!isEmpty())
    {
        u = dequeueElement();
        for(int i=1 ; i <= 20 ; i++)
        {
            if(adjMat[u][i] == 1 && level[i] == -1)
            {
                level[i] = level[u] + 1;
                enqueueElement(i);
            }
        }
    }

    cout<<setw(2)<<source<<" to "<<setw(2)<<destination<<":"<<setw(2)<<level[destination]<<endl;

}

void init()
{
    for (int i = 1; i <= maxx; i++)
    {
        for (int j = 1; j <= maxx; j++)
        {
            adjMat[i][j]=0;
            //adjMat[j][i];
        }
        queueElement[i] = -1;
        level[i] = -1;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int edges,i,j,k ;
    int testNum = 1;
    while(scanf("%d", &edges)!=EOF)
    {
        init();
        for(k = 0; k <edges; k++)
        {
            int nodename;
            cin>>nodename;
            adjMat[1][nodename] = 1;
            adjMat[nodename][1] = 1;
        }
        //frontElement = 0, rear = -1;
        for(i = 2 ; i<=19 ; i++)
        {
            scanf("%d", &edges);
            for(k = 0; k <edges; k++)
            {
                int nodename;
                cin>>nodename;
                adjMat[i][nodename] = 1;
                adjMat[nodename][i] = 1;
            }
        }

        int testCase ;
        cin>>testCase;
        cout<<"Test Set #"<< testNum++ <<endl;
        while(testCase--)
        {

            int source, destination;

            cin>>source>>destination;
            bfs(source,destination);

            frontElement = 0, rear = -1;
            for(int i=0 ; i <= maxx ; i++)
            {
                queueElement[i]=-1;
            }


        }
        cout<<endl;
    }
    return 0;
}
