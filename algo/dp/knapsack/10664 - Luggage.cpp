#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int total,N,ans;
void solve(int i, int sum)
{
    if(sum==total)
    {
        ans=1;
        return ;

    }
    if(i==N)
        return ;
    solve(i+1,sum);
    solve(i+1, sum+arr[i]);
}

int main()
{
    int test;
    char ch;
    cin>>test;

    while(test--)
    {
        ans=0;
        N=0;
        total =0;
        while(2==scanf("%d%c",&arr[N],&ch))
        {
            total+=arr[N];
            N++;
            if(ch!=' ')
                break;
        }
        //cout<<total<< "  "<<total%2<<endl;

        if (total%2)
        {
           cout<<"NO\n";
           continue;
        }
        else
        {
            total/= 2;
            solve(0,0);
            if(ans)
                cout<<"YES\n";

            else
                cout<<"NO\n";


        }


    }

    return 0;
}
