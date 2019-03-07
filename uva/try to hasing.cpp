#include<bits/stdc++.h>
using namespace std;
int hasarr[100];
int main()
{

    int test;
    cin>>test;
    int in=1;
    for(int i=1; i<=test; i++)
    {
        int n1;
        cin>> n1;
        int flug=0;
        for(int k=1; k<=test; k++)
        {
            if(hasarr[k]==n1)
                flug=1;
        }
        if (flug==0)
        {
            hasarr[in]=n1;
            in++;
        }

    }
    for(int k=1; k<=test; k++)
    {
        if(hasarr[k]!=0)
            cout<<k<<" "<<hasarr[k]<<endl;
    }

}
