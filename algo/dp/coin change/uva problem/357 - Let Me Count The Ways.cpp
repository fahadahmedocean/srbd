#include<bits/stdc++.h>
using namespace std;
long long int nway[30003]={};
int main()
{

    int coin[]= {50,25,10,5,1};
  //  memset(nway,0,sizeof(nway));

    nway[0]=1;
    for(int i=0; i<5; i++)
    {
        for(int j=1; j<30003; j++)
        {
            if(j>=coin[i])
            {
                nway[j]=nway[j]+nway[j-coin[i]];
            }
        }
    }


    int d;
    while(cin>>d)
    {

        if(nway[d]==1)
            printf("There is only %lld way to produce %d cents change.\n",nway[d],d);
        else
            printf("There are %lld ways to produce %d cents change.\n",nway[d],d);
    }

    return 0;
}
