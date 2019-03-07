#include<stdio.h>
int books[10000];
int abst(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    int n,m,i,j,k,l;
    while (scanf("%d",&n)==1)
    {
        int bi=0,bj=0,dif=1000000;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&books[i]);
        }
        scanf("%d",&m);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                if (books[i]+books[j]==m)
                {
                    int dif2=abst(books[i]-books[j]);
                    if (dif>dif2)
                    {
                        dif=dif2;
                        bi=books[i];
                        bj=books[j];
                    }
                }
        }
        if(bi<=bj)
        printf("Peter should buy books whose prices are %d and %d.\n\n",bi,bj);
        else
            printf("Peter should buy books whose prices are %d and %d.\n\n",bj,bi);


    }
    return 0;


}
