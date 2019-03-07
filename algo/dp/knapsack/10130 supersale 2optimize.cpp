#include<stdio.h>
#define maxx 1001
#define dp_size 1001

int N,p[maxx],W[maxx];
int ans,mw[1001];
int g;
int  dp[maxx][dp_size];


void solvecase()
{
    int i,maxw,w;
    ans=0;
    maxw=mw[1];
    for(i=2; i<=g; i++)
        if(mw[i]>maxw)
            maxw=mw[i];

    for(i=0; i<=N; i++)
        dp[i][0]=0;


    for(w=0; w<=maxw; w++)
        dp[0][w]=0;


    for(i=1; i<=N; i++)
    {

        for(w=1; w<=maxw; w++)
        {
            dp[i][w]=dp[i-1][w];

            if((w >=W[i]) && p[i]+dp[i-1][w-W[i]]> dp[i][w])
                dp[i][w]= p[i]+dp[i-1][w-W[i]];
        }
    }

    ans=0;
    for(i=1; i<=g; i++)
        ans+=dp[N][mw[i]];


}
void read()
{
    int  pp;
    scanf("%d",&N);
    for(pp=1; pp<=N; pp++)
        scanf("%d%d",&p[pp],&W[pp]);

    scanf("%d",&g);
    for(int q=1; q<=g; q++)
    {
        scanf("%d",&mw[q]);

    }

}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        //initdp();
        read();
        solvecase();
        printf("%d\n",ans);

    }
    return 0;
}

