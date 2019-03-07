#include<stdio.h>
int main()
{
    char S1[200], S2[200];
    printf("Enter S1 = ");
    gets(S1);
    printf("Enter S2 = ");
    gets(S2);
    printf("\nBefore Swapping\nS1 = %s S2 = %s\n",S1,S2);
    int i = 0;
    while(S1[i] != '\0' || S2[i] != '\0')
    {
        S1[i] = S1[i] + S2[i];
        S2[i] = S1[i] - S2[i];
        S1[i] = S1[i] - S2[i];
        i++;
    }
    printf("\nAfter Swapping\nS1 = %s S2 = %s\n",S1,S2);
    return 0;
}
