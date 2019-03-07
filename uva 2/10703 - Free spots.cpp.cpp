#include <stdio.h>

int main()
{
    int W, H, N;
    while (scanf("%d%d%d", &W, &H, &N) && W)
    {
        bool spot[501][501] = {};
        while (N--)
        {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x2 < x1)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            if (y2 < y1)
            {
                int temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for (int x = x1; x <= x2; x++)
            {
                for (int y = y1; y <= y2; y++)
                {
                    spot[x][y] = true;
                }
            }
        }
        int empty = 0;
        for (int x = 1; x <= W; x++)
        {
            for (int y = 1; y <= H; y++)
            {
                empty += !spot[x][y];
            }
        }
        if (!empty)
        {
            puts("There is no empty spots.");
        }
        else if (empty == 1)
        {
            puts("There is one empty spot.");
        }
        else
        {
            printf("There are %d empty spots.\n", empty);
        }
    }
    return 0;
}
