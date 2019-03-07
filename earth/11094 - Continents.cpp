#include <stdio.h>
#include <string.h>

int n, m, i, j, ans, sum;
char mapp[21][21], used[21][21], land;

void dfs(int x, int y)
{
    if(y < 0)
        y = m-1;
    if(y >= m)
        y = 0;
    if(x < 0 || x >= n)
        return ;
    if(used[x][y] != 0 || mapp[x][y] != land)
        return ;
    used[x][y] = 1;
    sum++;
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}

int main()
{
    while(scanf("%d %d", &n, &m) == 2)
    {
        used[21][21]={};

        for(i = 0; i < n; i++)
            scanf("%s", mapp[i]);

        scanf("%d %d", &i, &j);// position
        land = mapp[i][j];

        dfs(i, j);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                sum = 0;
                dfs(i, j);
                if(sum > ans)
                    ans = sum;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
