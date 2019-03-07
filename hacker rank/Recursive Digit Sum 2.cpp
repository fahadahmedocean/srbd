#include<bits/stdc++.h>
using namespace std;

int recfunc(long long int data)
{
    if(data%10==data)
        return data;

    int tem_sum=0;
    while(data!=0)
    {
        tem_sum+=data%10;
        data=data/10;
    }
    return recfunc(tem_sum);

}

int main()
{
    int d,n;
    while(cin>>d>>n)
    {
        int sum=0;
        while(d!=0)
        {
            sum=sum+(d%10);
            d=d/10;
        }
        //cout<<sum;
        long  long int data=sum*n;
        int ans2=recfunc(data);
        cout<<ans2<<endl;

    }
    return 0;
}
