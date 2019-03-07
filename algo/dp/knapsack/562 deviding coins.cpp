#include<stdio.h>
#define maxx 101
#define dp_size 50002

int m,coin[maxx], binary[maxx];
int total;
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
        coin[mm]= {};
        binary[mm]= {};
    }
    total=0;
}


int  solve(int i,int sum1)
{
    int sum2;
    int left, right;

    if(dp[i][sum1]!=-1)
        return dp[i][sum1];
    if(i==m)
    {
        sum2=total-sum1;
        //printf("%d  \n",abs(sum1-sum2));
        return dp[i][sum1]=abs(sum1-sum2);
    }
    binary[i]=0;
    left=solve(i+1,sum1);
    // optimization 1 start
    if(!left)
        return 0;
    if(sum1+coin[i]<=total/2)
        right=solve(i+1, sum1+coin[i]);
    else
        return left;

    // binary[i]=1;
    //right=solve(i+1, sum1+coin[i]);

    // // optimization 1 end
    if(left<right)
        return dp[i][sum1]=left;
    else
        return dp[i][sum1]=right;
}
void solvecase()
{
    int k;
    for(k=0; k<m; k++)
    {
        total=total+coin[k];
    }

    printf("%d\n",solve(0,0));
}
void read()
{
    int  p;
    scanf("%d",&m);
    for(p=0; p<m; p++)
        scanf("%d",&coin[p]);

}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        initdp();
        read();

        solvecase();

    }
    return 0;
}
