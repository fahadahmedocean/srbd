#include <bits/stdc++.h>
using namespace std;

int len;
int visit[100];

char str[123];
char tmp[123];

void go(int pos)
{
    if(pos >= len)
    {
        tmp[pos] = '\0';
        cout << "-->" << tmp << '\n';
        return ;
    }

    for(int i = 0; i < len; i++)
    {
        if(visit[i] == 0)
        {
            visit[i] = 1;
            tmp[pos] = str[i];
            go(pos + 1);
            visit[i] = 0;
        }
    }
}

int main()
{
    cin >> str;
    len = strlen(str);
    go(0);
}

