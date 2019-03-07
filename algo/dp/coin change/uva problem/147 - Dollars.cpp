#include<bits/stdc++.h>
using namespace std;

const int numCoins = 11;
int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

const int SIZE = 30003;
long long possible[SIZE];

int main()
{
    possible[0] = 1;
     for(int i=0; i<numCoins; i++)
    {
        for(int j=1; j<30003; j++)
        {
            if(j>=coins[i])
            {
                possible[j]=possible[j]+possible[j-coins[i]]; // using dynamic approach
            }
        }
    }

    double num;

    while (scanf("%lf", &num)==1)
    {
        if(num==0.00)
            break;
        printf("%6.2f%17lld\n", num, possible[(int)(num * 100 + 0.5)]);
    }
    return 0;
}
