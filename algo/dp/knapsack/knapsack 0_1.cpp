
// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>


int maxx(int a, int b)
{
    return (a > b)? a : b;
}


int knapSack(int cap, int wt[], int val[], int item)
{
    int i, w;
    int mgrid[item+1][cap+1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= item; i++)
    {
        for (w = 0; w <= cap; w++)
        {
            if (i==0 || w==0)
                mgrid[i][w] = 0;

            else if (wt[i-1] <= w)
                mgrid[i][w] = maxx( val[i-1] + mgrid[i-1][w-wt[i-1]],  mgrid[i-1][w] );

            else
                mgrid[i][w] = mgrid[i-1][w];
        }
    }

    return mgrid[item][cap];
}


int main()
{
    int i, item, val[20], wt[20], cap;

    printf("Enter number of items:");
    scanf("%d", &item);
    //int n = sizeof(val)/sizeof(val[0]);

    printf("Enter value and weight of items:\n");
    for(i = 0; i < item; ++i)
    {
        scanf("%d%d", &val[i], &wt[i]);
    }

    printf("Enter size of knapsack:");
    scanf("%d", &cap);

    printf("%d", knapSack(cap, wt, val, item));
    return 0;
}
//input:
//Enter number of items:3
//Enter value and weight of items:
//100 20
//50 10
//150 30
//Enter size of knapsack:50
////250
//
//3
//100 20
//50 10
//150 30
//50
