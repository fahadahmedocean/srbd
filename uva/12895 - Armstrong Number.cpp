#include<stdio.h>
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}


int main()
{
    int i, t, n, ArmN, ArmNumbuer, digit;
    while(scanf("%d",&t)==1)
    {
        for(i=0; i<t; i++)
        {
            scanf("%d", &ArmN);
            ArmNumbuer = ArmN;
            n = 0;
            while(ArmN > 0)
            {
                ArmN /= 10;
                n+=1;
            }
            ArmN = ArmNumbuer;

            while(ArmN > 0)
            {
                digit = ArmN % 10;
                ArmN /= 10;
                ArmNumbuer -= power(digit, n);
            }
            if(ArmNumbuer == 0)
                printf("Armstrong\n");
            else
                printf("Not Armstrong\n");
        }
    }
    return 0;
}
