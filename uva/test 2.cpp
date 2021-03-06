#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int n=9;
int value[mx];//= {-100000,5,0,9,2,7,3,4};
int dp[mx],dir[mx];

int longest(int u)
{
    if(dp[u]!=-1)
        return dp[u];
    int maxi=0;
    for(int v=u+1; v<=n; v++) //১ম শর্ত,v>u
    {
        if(value[v]>value[u]) //২য় শর্ত, value[v]>value[u]
        {
            if(longest(v)>maxi) //সর্বোচ্চ মানটা নিবো
            {
                maxi=longest(v);
                dir[u]=v;

            }
        }
    }
    dp[u]=1+maxi; //১ যোগ হবে কারণ u নম্বর নোডটাও পাথের মধ্যে আছে
    return dp[u];
}

void solution(int start)
{
    while(dir[start]!=-1)
    {
        printf("index %d value %d\n",start,value[start]);
        start=dir[start];

    }
     printf("index %d value %d\n",start,value[start]);
}


int main()
{
    for(int a=0; a<=n; a++)
        cin>>value[a];
    for(int a=1; a<=n; a++)
        cout<<value[a]<<"  ";
    cout<<endl;

    //READ("in");
    for(int a=0; a<=mx; a++)
    {
        dp[a]= -1;
        dir[a]= -1;
    }

    int LIS=0,start;
    for(int i=1; i<=n; i++)
    {
        // printf("longest path from: %d\n",longest(i));
        if(longest(i)>LIS)
        {
            LIS=longest(i);
            start=i;
        }
    }
    printf("LIS = %d Starting point index %d\n\n",LIS,start);

    solution(start);
    return 0;
}


/*
 -1000 5 0 9 2 7 3 4

 -1000 2 6 3 4 1 2 9 5 8

*/
