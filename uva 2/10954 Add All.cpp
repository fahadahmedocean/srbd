#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n==0) return 0;
        priority_queue<int > pq;
        while (n--)
        {
            int a;
            scanf("%d",&a);
            pq.push(-1*a);
        }
        long long int cost=0;
        while (pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int c=a+b;
            cost+=c;
            pq.push(c);
        }
        printf("%lld\n",-1*cost);
    }
    return 0;
}
