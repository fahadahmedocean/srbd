#include<stdio.h>

int connections, adjMat[31][31], level[31], present[1005];
int queueElement[31], frontElement = 0, rear = -1;

int isEmpty()
{
    if(frontElement>rear)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == 29)
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

int bfs(int source, int ttl)
{
    int u, countNodes = 0 ;
    for(int i=1; i<=30; i++)
    {
        level[i] = -1;
    }
    enqueueElement(source);
    level[source] = 0;
    while(!isEmpty())
    {
        u = dequeueElement();
        for(int i = 1; i <= 30 ; i ++)
        {
            if(adjMat[u][i] == 1 && level[i] == -1)
            {
                level[i] = level[u] + 1;

                if (level[i] > ttl)
                    countNodes++;
                enqueueElement(i);
            }
        }
    }
    return countNodes;
}

void init()
{
    for (int i = 1; i <= 31; i++)
    {
        for (int j = 1; j <= 31; j++)
        {
            adjMat[i][j]=0;
        }
        queueElement[i] = -1;
        level[i] = -1;
       present[i]=0;

    }
}
int main()
{
     //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);


    int caseNo=1;
    while(scanf("%d",&connections)==1)
    {
        frontElement = 0, rear = -1;
        init();
        if(connections == 0)
            break;


        int nodename1, nodename2;
        int cnt = 1;

        for(int i = 0 ; i< connections ; i++)
        {
            scanf("%d%d",&nodename1,&nodename2);
            //printf("ss\n");

            if(!present[nodename1])
            {
                present[nodename1] = cnt++;
            }
 //printf("ss 2\n");
            if(!present[nodename2])
            {
                present[nodename2] = cnt++;
            }
  // printf("ss 3\n");
            adjMat[present[nodename1]][present[nodename2]] = 1 ;
            adjMat[present[nodename2]][present[nodename1]] = 1;
    //printf("ss 4\n");
        }

        int source, ttl;
        while(scanf("%d %d",&source,&ttl)==2)
        {

            int numOfNodes;
            if(source == 0 && ttl == 0)
                break;
            numOfNodes = bfs(present[source],ttl);

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseNo++ , numOfNodes, source , ttl);
            //for(int i = 1; i <= connections ;i++)
            frontElement = 0, rear =-1;
            for(int i=1 ; i <= connections ; i++)
            {
                queueElement[i]=-1;
            }
        }

    }
    return 0;
}
