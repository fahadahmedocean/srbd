#include<iostream>
#include<stdio.h>

#define maxx 210
using namespace std;

int nodes,adjMat[maxx][maxx];
int queueElement[maxx], frontElement = 0, rearElement = -1;
int color[maxx];
int cntcolor[2];
int N,M, flug;

int maxval(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int isEmpty()
{
    if(frontElement>rearElement)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rearElement == N-1)
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
        rearElement++;
        queueElement[rearElement] = data;

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

bool isbp;

int breadthFirstSearch(int SourceVertex)
{
    cntcolor[0] = 0, cntcolor[1] = 0;
    int u, i;
    enqueueElement(SourceVertex);
    color[SourceVertex] = 0;
    cntcolor[color[SourceVertex]]++;

    while(!isEmpty())
    {
        u = queueElement[frontElement];
        dequeueElement();

        for(i=1; i<=N; i++)
        {
            int v=adjMat[u][i];
            if(v==0)
                continue;
            if (color[i]==-1)
            {
                color[i] = !color[u];
                cntcolor[color[i]]++;
                enqueueElement(i);
            }
            else
            {
                if(color[u]==color[i])
                {
                    isbp = true;
                }
            }
        }
    }
    //cout<<"DONE "<<cntcolor[0]<<' '<<cntcolor[1]<<' '<<maxval(cntcolor[0], cntcolor[1])<<endl;
    return maxval(cntcolor[0], cntcolor[1]);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int tc,edge,j;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &edge);
            while(edge--)
            {
                scanf("%d", &j);
                adjMat[i][j]=1;
                adjMat[j][i]=1;
            }
        }

        for(int i=0; i<=N; i++)
            color[i] = -1;

        int total = 0;
        for(int i=1; i<=N; i++)
        {
            if (color[i] == -1)
            {
                isbp = false;
                int ret = breadthFirstSearch(i);
                if(!isbp){
                    total += ret;
                }
            }
        }

        printf("%d\n", total);

        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                adjMat[i][j] = 0;
            }
            queueElement[i] = 0;
        }
        frontElement = 0, rearElement = -1;
    }
    return 0;
}
