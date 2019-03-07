#include<stdio.h>

#define maxx 100
int n,a[maxx],s[maxx];
void readcase()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&s[i]);
}

void printcase()
{
    int i;
    for(i=0; i<n; i++)
        if(a[i]==1)
            printf("%d",s[i]);
    printf("\n");
}
void solvecase(int i)
{
    if(i==n)
    {
        printcase();
        return;
    }
    a[i]=0;
    solvecase(i+1);
    a[i]=1;
    solvecase(i+1);

}

int main()
{
    readcase();
    solvecase(0);
}
