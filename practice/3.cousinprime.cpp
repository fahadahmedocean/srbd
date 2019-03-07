//cousin prime: (3, 7), (7, 11), (13, 17), (19, 23), (37, 41), (43, 47), (67, 71), (79, 83), (97, 101)
#include<bits/stdc++.h>
using namespace std;
int status[1100002]= {0};
void siv()
{
    int N=1000000,sq;
    sq=sqrt(N);

    for(int i=4; i<=N; i+=2)
        status[i]=1;

    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i)
                status[j]=1;
        }
    }
    status[1]=1;

}
int main()
{
    siv();
    int i,a,b;
    cout<< "enter a nd b  for check Cousin prime no.\n";
    cin>>a>>b;
    if(status[a]==0 && status[b]==0 && abs(a-b)==4)
        cout<<"Cousin prime \n";
    else
        cout<<"not Cousin prime \n";
    return 0;
}

