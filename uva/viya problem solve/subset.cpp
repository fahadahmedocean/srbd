#include<stdio.h>

#define maxx 100
int n,arr[maxx];

void printcase()
{
    for(int j=0; j<n; j++)
            printf("%d",arr[j]);
    printf("\n");
}
void solvecase(int i)
{
    if(i==n)
    {
        printcase();
        return;
    }
    arr[i]=0;
    solvecase(i+1);
    arr[i]=1;
    solvecase(i+1);

}

int main()
{
    scanf("%d",&n);
    solvecase(0);
}
