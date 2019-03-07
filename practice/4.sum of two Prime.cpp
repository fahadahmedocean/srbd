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
    int i,input;
    cout<< "enter n for prime no.\n";
    cin>>input;
    int temp=input-2;
    if(status[temp]==0)
        cout<<input<<" can be expressed as sum of two Prime Numbers\n ";
    else
        cout<<"not possible\n";
    return 0;
}

