#include<stdio.h>
#define maxx 1001

int arr[maxx];
int visit[maxx];
int N;

void intvisit()
{
    for(int i=0; i<=maxx; i++)
        visit[i]=0;
}

void Print()
{
    int p;
    for(p=0; p<N; p++)
        printf("%d",arr[p]);
    printf("\n");
}

void solve(int i)
{
    int j;
    if(i==N)
    {
        Print();
        return;
    }

    for(j=1; j<=N; j++)
    {
        if(visit[j]==0)
        {
            visit[j]=1;
            arr[i]=j;
            solve(i+1);
            visit[j]=0;// backtrack
        }
    }
}



int main()
{

    scanf("%d",&N);
    solve(0);


}
