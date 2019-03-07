#include<stdio.h>
#define maxx 201

int M, N;
int adjmat[maxx][maxx], color[maxx];
int ans;
int Q[maxx];
int frnt, rear;

void initqueue()

{
    //printf("in it queue \n");
    frnt=0;
    rear=0;
}

int isempty()
{
    return frnt==rear;
}
int isfull()
{
    if (rear==N)
        return 1;
    else
        return 0;
}
void push(int element)
{

    Q[rear]=element;
    rear++;

}
int pop()
{

    frnt++;
    return Q[frnt-1];

}

void initcase()
{

    for( int k = 1; k <=N; k++)
    {
        for( int p = 1; p<=N; p++)
            adjmat[k][p]= 0;
        color[k]=0;
    }

}

int modified_bfs()

{
    //printf(" case\n");
    int i, x,y,isbipar,gp_one,gp_two;
    ans =0;
    initqueue();

    for(i=1; i<=N; i++)
        if(!color[i])
        {
            isbipar=1;
            push(i);

            color[i]=1;
            gp_one=1;
            gp_two=0;

            while(!isempty())
            {
                x=pop();
                // printf("x : %d\n", x);
                for(y=1; y<=N; y++)

                    if(adjmat[x][y])
                    {
                        if(!color[y])
                        {
                            color[y]=3-color[x];
                            if (color[y]==1)
                                gp_one++;
                            else
                                gp_two++;
                            push(y);
                        }
                        else if (color[x]==color[y])
                            isbipar=0;
                    }
            }

            // printf("biper: %d\n",isbipar);

            if(isbipar)
            {
                if (gp_one>gp_two)
                    ans=ans+gp_one;

                else
                    ans=ans+gp_two;


//                printf("ans: %d  gp_one: %d  gp_two: %d\n",ans, gp_one,gp_two);
//                printf("\n color arr\n");
//                for( int i = 1; i <=N; i++)
//                {
//                    printf("%d  ", color[i]);
//                }
//                printf("\n\n\n");


            }

        }
    // printf(" end  case\n");

}




int main()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    int tc,edge,j;
    scanf("%d", &tc);
    printf("\n");
    while (tc--)
    {
        initcase();
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &edge);
            while(edge--)
            {
                scanf("%d", &j);
                adjmat[i][j]=1;
                adjmat[j][i]=1;

            }
        }

        modified_bfs();
        printf("%d\n",ans);


    }
    return 0;
}
