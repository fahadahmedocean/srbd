//directed longest  path  uva 10000

#include <stdio.h>
#define maxx 101

int main()
{
    int n, src, Case = 0, x, y, i, j;

    while(scanf("%d", &n) == 1 && n)
    {
        scanf("%d", &src);

        int mat[maxx][maxx] ;//= {
//            1, 0, 0, 0,
//            1, 1, 1, 0,
//            1, 0, 1, 0,
//            1, 1, 1, 1
//
//        };
        while(scanf("%d %d", &x, &y) == 2)
        {
            if(x == 0 && y == 0)
                break;
            mat[x][y] = 1;
            // mat[y][x] = 1;
        }

        int Queue[10000], idx = -1;
        int visited[maxx] = {}, level[maxx] = {}, tr;

        Queue[++idx] = src, visited[src] = 1;
        for(i = 0; i <= idx; i++)
        {
            tr = Queue[i];
            visited[tr] = 0;

            for(j = 1; j <= n; j++)
            {
                if(mat[tr][j] != 0 && level[tr]+1 > level[j])
                {
                    level[j] = level[tr]+1;
                    if(visited[j] == 0)
                    {
                        Queue[++idx] = j;
                        visited[j] = 1;
                    }
                }
            }
        }

//        for(int kk=0; kk<=n; kk++)
//            printf("%d  ",level[kk]);

        int length = 0, endp = src;
        for(i = 1; i <= n; i++)
        {
            if(level[i] > length)
            {
                length = level[i];
                endp = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++Case, src, length, endp);
    }
    return 0;
}
