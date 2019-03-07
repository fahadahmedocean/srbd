#include <stdio.h>

int main()
{
    int n, m;
    int ok[5001] = {};
    for(n = 1; n <= 5000; n++)
    {
        char used[10] = {};
        m = n;
        while(m)
        {
            if(used[m%10])
                break;
            used[m%10] = 1;
            m /= 10;
        }
        if(m == 0)
            ok[n] = 1;
        ok[n] = ok[n]+ok[n-1];
    }
//    for(int i=0;i<=100;i++)
//      printf("%d ",ok[i]);

    while(scanf("%d %d", &n, &m) == 2)
    {
        printf("%d\n", ok[m]-ok[n-1]);
    }
    return 0;
}
