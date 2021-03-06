#include<bits/stdc++.h>
using namespace std;

const int N = 100031;
int n, m;
long long t[N];
long long sum[N];

int check(long long thold)
{
    int done = 0;
    int res = 0;
    while (done < n)
    {
        int cur = done;
        while (cur + 1 <= n &&sum[cur + 1] - sum[done] <= thold)
            ++cur;
        if (cur == done)
            return 1e9;
        res++;
        done = cur;
    }
    return res;
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + t[i];
    }

    long long l, r;

    l = 1;
    r = 1e17;

    while (l < r)
    {
        long long mid = l + r;
        mid /= 2;

        if (check(mid) <= m)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
