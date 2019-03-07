#include<bits/stdc++.h>
using namespace std;
#define maxx 7491

int coin[]= {50,25,10,5,1};
int make;
int dp[maxx][maxx];

int call(int i,int amount)
{
    if(i>=5)   //All coins have been taken
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];

    int ret1=0,ret2=0;

    if(amount-coin[i]>=0)
        ret1=call(i,amount-coin[i]);

    ret2=call(i+1,amount);

    return dp[i][amount]=ret1+ret2; // return koto vabe banano jabe

}
int main()
{
    // freopen("in","r",stdin);
    memset(dp,-1,sizeof(dp));
    while(cin>>make)
    {
        cout<<call(0,make)<<endl;
    }
    return 0;
}
