#include<stdio.h>
#define maxx 201

int M, N;
int enemy [maxx][maxx], group[maxx];
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
            enemy[k][p]= 0;
        group[k]=0;
    }

}
void readcase()
{
    int i, j, t;

    scanf("%d", &N);

    initcase();

    for(int i=1; i<=N; i++)
    {
        //printf("enter t \n");
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d", &j);
            enemy[i][j]=1;
            enemy[j][i]=1;

        }
    }
}

int solvecase()

{
    //printf("solve case\n");
    int i, x,y,isbipar,one,two;
    ans =0;
    initqueue();

    for(i=1; i<=N; i++)
        if(!group[i])
        {
            isbipar=1;
            push(i);

            group[i]=1;
            one=1;
            two=0;
            while(!isempty())
            {
                x=pop();
                // printf("x : %d\n", x);
                for(y=1; y<=N; y++)

                    if(enemy[x][y])
                    {
                        if(!group[y])
                        {
                            group[y]=3-group[x];
                            if (group[y]==1)
                                one++;
                            else
                                two++;
                            push(y);
                        }
                        else if (group[x]==group[y])
                            isbipar=0;
                    }
            }

            // printf("biper: %d\n",isbipar);

            if(isbipar)
            {
                if (one>two)
                    ans=ans+one;

                else
                    ans=ans+two;


//                printf("ans: %d  one: %d  two: %d\n",ans, one,two);
//                printf("\n color arr\n");
//                for( int i = 1; i <=N; i++)
//                {
//                    printf("%d  ", group[i]);
//                }
//                printf("\n\n\n");


            }

        }
    // printf(" end solve case\n");

}
void printcase()
{
    //printf(" void printcase");
    printf("%d\n",ans);
}



int main()

{
         freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    scanf("%d", &M);

    while (M--)
    {
        readcase();
        solvecase();
        printcase();


    }
    return 0;
}
