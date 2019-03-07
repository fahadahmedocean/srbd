#include <iostream>
using namespace std;

int n, best, countt;
const int MAX = 20;
int L[MAX];
int cumulative[MAX + 1];
bool used[MAX], best_used[MAX];

void backtrack(int idx, int sum)
{
    if (sum > n)
        return;
    if (sum > best)
    {
        for (int i = 0; i < countt; i++)
        {
            best_used[i] = used[i];
        }
        best = sum;
        if (best == n)
            return;
    }
    if (sum + cumulative[idx + 1] <= best)
        return;
    used[idx] = true;

    backtrack(idx - 1, sum + L[idx]);

    used[idx] = false;
    backtrack(idx - 1, sum);
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        scanf("%d", &countt);

        for (int i = 0; i < countt; i++)
        {
            scanf("%d", L + i);
        }

        cumulative[0] = 0;
        for (int i = 0; i < countt; i++)
        {
            cumulative[i+1] = cumulative[i] + L[i];
            used[i] = false;
        }
        best = 0;
        backtrack(countt - 1, 0);
        for (int i = 0; i < countt; i++)
        {
            if (best_used[i])
                printf("%d ", L[i]);
        }
        printf("sum:%d\n", best);
    }
}
