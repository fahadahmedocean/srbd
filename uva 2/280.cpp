#include<stdio.h>

#define ll long long
int node;
int graph[102][102];
int visited[102];

void clear(int node)
{
    for (int i = 0; i <= node; i++)
        visited[i] = 0;
}
void init_Graph()
{
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 102; j++)
            graph[i][j] = 0;
}
void dfs(int n)
{
    for (int i = 1; i <= node; i++)
    {
        if (graph[n][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i);
        }
    }
    return;
}
int main()
{
// READ;
    while (scanf("%d", &node) == 1 && node != 0)
    {
        int start, n, q, s;
        init_Graph();
        while (scanf("%d", &start) == 1 && start != 0)
        {
            while (scanf("%d", &n) && n != 0)
            {
                graph[start][n] = 1;
            }
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d", &s);
            int ans = 0;
            clear(node);
            dfs(s);

            for (int i = 1; i <= node; i++)
                if (visited[i] == 0)
                    ans++;
            printf("%d", ans);

            for (int i = 1; i <= node; i++)
                if (visited[i] == 0)
                    printf(" %d", i);
            puts("");
        }
    }
    return 0;
}
