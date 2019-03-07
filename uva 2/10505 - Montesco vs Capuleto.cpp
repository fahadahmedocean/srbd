#include<stdio.h>
#define maxx 210
int adjmax [maxx][maxx], que[maxx], level[maxx],color[maxx];
int frnt=0, rear=-1,nod;

int isempty()
{
    if (frnt>rear)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (rear==nod-1)
        return 1;
    else
        return 0;
}
void enQ(int element)
{
    if(isfull())
        return;
    else
    {
        rear++;
        que[rear]=element;
        return;

    }
}
int deQ()
{
    int dqdata;
    if(isempty())
        return -1;
    else
    {
        dqdata = que[frnt];
        frnt++;
        return dqdata;
    }
}

int BFS(int sv)
{
    int u, i;
//    for(i=1; i<=nod; i++)
//    {
//        color[i] =-1;
//    }
    enQ(sv);
    color[sv] = 1;

    while(!isempty())
    {
        u = que[frnt];
        deQ();
        printf("\n u= %d  ",u);
        for(i=1; i<=nod; i++)

        {
                                    printf("\n color arr");

                                    for( int i = 1; i <=nod; i++)
                                    {
                                        printf("%d  ", color[i]);
                                    }
                                    printf("\n");

            int v=adjmax[u][i];
            if(v==0)
                continue;
            if (color[i]==-1)
            {
                if(color[u]==1)
                    color[i]=2;
                else if  (color[u]==2)
                    color[i]=1;
                //cout<<"EnQ "<<i<<endl;
                enQ(i);
            }
            else
            {
                if (color[u]==color[i])
                {
                    //printf(" return 0\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}


void initial()
{
    for(int i=0; i<maxx; i++)
    {
        for(int j=0; j<maxx; j++)
        {
            adjmax[i][j] = 0;
            que[i]= 0;
        }

        frnt=0, rear=-1;
    }
}

int main()
{
    int tc,N,edge,j;
    int flug,check;
    scanf("%d", &tc);
    printf("\n");

    while (tc--)
    {
        flug=0;
        scanf("%d", &N);
        nod=N;
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &edge);
            while(edge--)
            {
                scanf("%d", &j);
                adjmax[i][j]=1;
                adjmax[j][i]=1;

            }
        }



//        printf("\n");
//        printf("\n");
//        for(int k = 1; k <=nod; k++)
//        {
//            for( int i = 1; i <=nod; i++)
//            {
//                printf("%d  ", adjmax[k][i]);
//            }
//            printf("\n");
//        }


        for(int i=1; i<=nod; i++)
        {
            color[i] =-1;
        }

        for( int i = 1; i <=nod; i++)
        {
            if(color[i]==-1)
              check=  BFS(i);
            if(check==0)
                flug=9;

        }




        printf("\n color arr");
        printf("\n");
        for( int i = 1; i <=nod; i++)
        {
            printf("%d  ", color[i]);
        }
        printf("\n");




        int count1=0,count2=0,countm=0;
        for( int i = 1; i <=nod; i++)
        {
            if(color[i]==1)
                count1++;
            if(color[i]==2)
                count2++;
            if(color[i]==-1)
                countm ++;

        }
        if (flug==9)
            printf("0\n");
        else if (count1>=count2)
            printf("%d\n",count1+countm);
        else
            printf("%d\n",count2+countm);


        initial();



    }
    return 0;
}
