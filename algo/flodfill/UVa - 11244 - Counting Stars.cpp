//11244 Counting Stars

#include <bits/stdc++.h>
#define S 103
using namespace std;

int n, m, f;
int xdir[] = {0, 1, 0, -1, 1, -1, 1, -1};
int ydir[] = {1, 0, -1, 0, 1, -1, -1, 1};
string globe[S];

int dfs(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || globe[i][j] == '.')
        return 0;
    globe[i][j] = '.';
    f++;
    for(int z = 0; z < 8; z++)
    {
        int px = i+xdir[z];
        int py = j+ydir[z];
        dfs(px, py);
    }
    return f;
}

int main()
{
    while(cin >> n >> m)
    {
        if(!n && !m)
            return 0;
        for(int i = 0; i < n; i++)
            cin >> globe[i];
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                f = 0;
                if(globe[i][j] == '*')
                {
                    ans++;
                    if(dfs(i, j) != 1)
                        ans--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
