#include <stdio.h>

int main()
{
    int n, T = 1;
    scanf("%d\n", &n);
    char s[111111];
    while (n--)
    {
        gets(s);
        int i, v[100] = {}, now = 0;
        for (i = 0; s[i]; i++)
        {
            switch (s[i])
            {
            case '>':
                now = (now + 1) % 100;
                break;
            case '<':
                now = (now + 100 - 1) % 100;
                break;
            case '+':
                v[now] = (v[now] + 1) % 256;
                break;
            case '-':
                v[now] = (v[now] + 256 - 1) % 256;
                break;
            }
        }
        printf("Case %d: ", T++);
        for (i = 0; i < 100; i++)
        {
            printf("%02X%s", v[i], i == 99 ? "\n" : " ");
        }
    }
    return 0;
}
