#include<stdio.h>
#define maxx 201

int T, V;
int Street[maxx][maxx], group[maxx];
int ans;
int Q[maxx];
int frnt, rear;

void initqueue()
{    //printf("in it queue \n");
    frnt=0;
    rear=0;
}

int isempty()
{
    return frnt==rear;
}

void push(int n)
{    Q[rear]=n;
    rear++;
}
int pop()
{    frnt++;
    return Q[frnt-1];

}

void initcase()
{
    for( int k = 0; k <V; k++)
    {
        for( int p = 0; p<V; p++)
            Street[k][p]= 0;
        group[k]=0;
    }
}
void readcase()
{
    int E,f, t;
    scanf("%d%d",&V,&E);
    initcase();

    while(E--)
    {
        scanf("%d%d",&f,&t);
        Street[f][t]=1;
        Street[t][f]=1;
    }

}
void modified_bfs()
{    //printf(" case\n");
    int i, x,y,gp_one,gp_two;
    ans =0;
    initqueue();
    for(i=0; i<V; i++)
        if(!group[i])
        {
            push(i);
            group[i]=1;
            gp_one=1;
            gp_two=0;
            while(!isempty())
            {
                x=pop();
                // printf("x : %d\n", x);
                for(y=0; y<V; y++)

                    if(Street[x][y])
                    {
                        if(!group[y])
                        {
                            group[y]=3-group[x];
                            if (group[y]==1)
                                gp_one++;
                            else
                                gp_two++;
                            push(y);
                        }
                        else if (group[x]==group[y])
                        {
                            ans=-1;
                            return ;
                        }
                    }
            }

            // printf("biper: %d\n",isbipar);

            if(1==gp_one+gp_two)
                ans++;

            if (gp_one<gp_two)
                ans=ans+gp_one;

            else
                ans=ans+gp_two;

//                printf("ans: %d  gp_one: %d  gp_two: %d\n",ans, gp_one,gp_two);
//                printf("\n group arr\n");
//                for( int i = 1; i <=N; i++)
//                {
//                    printf("%d  ", group[i]);
//                }
//                printf("\n\n\n");

        }
    // printf(" end  case\n");

}
int main()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc,edge,j,E;
    scanf("%d", &tc);
    while (tc--)
    {

    //       scanf("%d%d", &V,&E);
//        initcase();
//        int n1,n2;
//        while(E--)
//        {
//            scanf("%d", &j);
//            Street[n1][n2]=1;
//            Street[n2][n1]=1;
//
//        }
    readcase();
        modified_bfs();
        printf("%d\n",ans);


    }
    return 0;
}



































