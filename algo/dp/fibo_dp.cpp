#include<stdio.h>

#define MAX 100

int dp[MAX];

/* Function to initialize NIL values in dp table */
void initialize()
{
    int i;
    for (i = 0; i < MAX; i++)
        dp[i] = -1;
}

/* function for nth Fibonacci number */
int fib(int n)
{
    if (n==0)
        return 0;
    if (n==1)
        return 1;

    if (dp[n] != -1)
        return dp[n];
    else
    {

        dp[n] = fib(n-1) + fib(n-2);
        return dp[n];
    }


}

int main ()
{
    int n = 40;
    initialize();
    fib(40);
    printf("Fibonacci number is %d ", dp[3]);
    return 0;
}
