#include <stdio.h>

#define MAX 100+10

int G[MAX][MAX], color[MAX], ans[MAX];
int n, k, maxval;

void Creat_Graph()
{
    int i = 0, a = 0, b = 0;
    scanf("%d%d",&n,&k);
    for (i = 0; i <k; i++)
    {
        scanf("%d%d",&a,&b);
        G[a][b] = 1;
        G[b][a] = 1;
    }
}

int judge(int cur)
{
    for (int i = 1; i <= n; i++)
    {
        if (G[i][cur] && color[i])
            return 0;
    }
    return 1;
}

void dfs(int cur)
{
    int i = 0, j = 0;
    if (cur > n)
    {
        int count = 0;
        for(i = 1; i <= n; i++)
            if (color[i])
                count++;
        if (count > maxval)
        {
            maxval = count;
            for (i = 1, j = 0; i <= n; i++)
                if (color[i])
                    ans[j++] = i;
        }
        return;
    }
    else
    {
        color[cur] = 0;
        dfs(cur+1);
        color[cur] = 1;
        if (judge(cur))
            dfs(cur+1);
        color[cur] = 0;
    }
}

int main()
{

    int t = 0, i = 0;
    scanf("%d",&t);
    while (t--)
    {
        G[MAX][MAX]={0}, color[MAX]={0}, ans[MAX]={0};
        maxval = 0;

        Creat_Graph();
        dfs(1);

        printf("%d\n",maxval);

        for (i = 0; i <maxval; i++)
        {
            if (i != maxval - 1)
                 printf("%d ",ans[i]);
            else
                printf("%d",ans[i]);
        }
        printf("\n");
    }
}
