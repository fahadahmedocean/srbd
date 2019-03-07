#include<bits/stdc++.h>
using namespace std;

int par[105];

struct side
{
    int from,to;
};

int findset(int r)
{
    if(par[r] == r)
        return r;
    return par[r] = findset(par[r]);
}
void setunion(int a, int b)
{
    int u = findset(a);
    int v = findset(b);

    if(u == v)
        printf("They are already friends\n");
    else
        par[u] = v;
}
int main()
{
    side get;
    int u,v,n,a,b,i,j,arr[100] ;
    vector<side> vec;

    scanf("%d",&n);
    for(i = 1; i <= 100; i++)
    {
        par[i] = i;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        get.from =  a;
        get.to   =  b;
        vec.push_back(get);
    }///vector basically pryojon pore na

    for(i = 0; i < n; i++)
    {
        u = vec[i].from;
        v = vec[i].to;
        setunion(u,v);
    }

    for(i = 1; i <= 10; i++)
        printf("Parent of %d is %d\n", i, par[i]);
    cout << endl;
    for(i = 1; i <= 10; i++)
        printf("Set of %d is %d\n", i, findset(i)); //call findset for 10 elements
    cout << endl;
    for(i = 1; i <= 10; i++)
        printf("Parent of %d is %d\n", i, par[i]);

    return 0;
}
