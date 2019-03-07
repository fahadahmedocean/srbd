#include <stdio.h>

int main()
{
    int i, j, k, test = 0;
    int n;
    while(scanf("%d", &n) == 1)
    {
        int adjmat[21][21] = {};
        for(i = 1; i <= 19; i++)
        {
            if(i != 1)
                scanf("%d", &n);
            while(n--)
            {
                scanf("%d", &k);
                adjmat[i][k] = 1;
                adjmat[k][i] = 1;
            }
        }



         printf("\n"); printf("\n");
        for(int k = 1; k <= 20; k++)
        {
            for( int i = 1; i <= 20; i++)
            {
                printf("%d  ", adjmat[k][i]);
            }
            printf("\n");
        }




        for(k = 1; k <= 20; k++)
        {
            for(i = 1; i <= 20; i++)
            {
                for(j = 1; j <= 20; j++)
                {
                    if(adjmat[i][j] == 0 || adjmat[i][j] > adjmat[i][k]+adjmat[k][j])
                    {
                        if(adjmat[i][k] && adjmat[k][j])
                            adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                    }
                }
            }
        }
        scanf("%d", &n);
        printf("Test Set #%d\n", ++test);
        while(n--)
        {
            scanf("%d %d", &i, &j);
            printf("%2d to %2d: %d\n", i, j, adjmat[i][j]);
        }
        puts("");
    }
    return 0;
}
