#include<bits/stdc++.h>
using namespace std;
int main()
{

    int way[7490]={};
    int coin[5] = {50,25,10,5,1};


    way[0]=1;

    for(int i=0; i<5; i++)
    {
        for(int j=1; j<7490; j++)
        {
            if(j>=coin[i])
            {
                way[j]=way[j]+way[j-coin[i]]; // using dynamic approach
            }
        }
    }


    int d;
    while(cin>>d)
        cout<<way[d]<<endl;

    return 0;
}
