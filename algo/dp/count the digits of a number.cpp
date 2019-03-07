#include<bits/stdc++.h>
using namespace std;
int n;
int i=0,sum;
int disitcount( int n)
{

    if (n==0)
        return sum;
    i++;
    sum=sum+n%10;
    disitcount(n/10);


}


int main()
{
    cin>>n;
    cout<<disitcount(n);
}
