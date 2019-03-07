#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int rds(long long int P)
{

    if(P/10==0)
        return P;

    long long int temp=P,sum=0;
    while(P!=0)
    {
        int P1=P%10;
        sum=sum+P1;
        P=P/10;
    }

    return rds(sum);

}
int main()
{
    long int d;
    int P,ans,n;
    scanf("%ld %d",&d,&n);
    double temp=d,sum=0;
    while(d!=0)
    {
        int P1=d%10;
        sum=sum+P1;
        d=d/10;
    }

    sum=sum*n;
    ans=rds(sum);
    printf("%d",ans);
    return 0;

}
