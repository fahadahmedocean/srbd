//871 countting Cells in a Blob

#include<bits/stdc++.h>
#define maxN 30
#define loop(i, n) for (int i=0; i<n; i++)
using namespace std;

const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m;
char s[maxN][maxN];

int Visit(int x, int y)
{
    if (x<0 || x>=n || y<0 || y>=m || s[x][y]!='1')
        return 0;
    s[x][y] = '0';
    int Count = 1;
    loop (i, 8)
    Count += Visit(x + dx[i], y + dy[i]);
    return Count;
}

main()
{
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    gets(s[0]);
    gets(s[0]);
    while (Case--)
    {
        n = 0;
        while (gets(s[n]) && s[n][0]!='\0')
            n++;
        m = strlen(s[0]);
        int Max = 0;
        loop (i, n)
        loop (j, m)
        if (s[i][j]=='1')
            Max = max(Max, Visit(i, j));
        printf("%d\n", Max);
        if (Case)
            printf("\n");
    }
}
