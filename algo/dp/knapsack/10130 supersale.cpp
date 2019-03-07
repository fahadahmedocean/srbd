#include<stdio.h>
#define maxx 1001
#define dp_size 31

int N,p[maxx],w[maxx];
int ans,mw;

int  dp[maxx][dp_size];

int abs(int n)
{
    if (n<0)
        return -n;
    return n;
}
void initdp()
{
    for(int mm=0; mm<maxx; mm++)
    {
        for(int nn=0; nn<dp_size; nn++)
            dp[mm][nn]=-1;
        p[mm]= {};
        w[mm]= {};
    }
    ans=0;
}


int  solve(int i,int cap)
{

    int left, right;
    if(dp[i][cap]!=-1)
        return dp[i][cap];
    if(i==N)
        return dp[i][cap];

    left=solve(i+1,cap);
    if(cap>=w[i])
        right=p[i]+solve(i+1, cap-w[i]);
    else
        right=0;
    if(left>right)
        return dp[i][cap]=left;
    else
        return dp[i][cap]=right;
}
void solvecase()
{
    int g;
    scanf("%d",&g);
    for(int q=0; q<g; q++)
    {
        scanf("%d",&mw);
        ans+=solve(0,mw);
    }
}
void read()
{
    int  pp;
    scanf("%d",&N);
    for(pp=0; pp<N; pp++)
        scanf("%d%d",&p[pp],&w[pp]);

}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        initdp();
        read();
        solvecase();
        printf("%d\n",ans);

    }
    return 0;
}

