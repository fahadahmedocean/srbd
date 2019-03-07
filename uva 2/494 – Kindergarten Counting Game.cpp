#include <stdio.h>
#define SIZE 99
#define NUM 128

int main()
{
    char S[SIZE], CH[NUM], c;
    int s, F, C;
    for(s = 0; s < NUM; s++)
        CH[s] = s > 64 && s < 91 || s > 96 && s < 123;

    while(gets(S) != NULL)
    {
        F = C = s = 0;
        while((c = S[s++]) != '\0')
        {
            if(CH[c])
                F = 1;
            else if(F)
            {
                C++;
                F = 0;
            }
        }
        printf("%d\n", C);
    }
    return 0;
}
