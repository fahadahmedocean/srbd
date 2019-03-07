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
    int data=input;
    if(status[input]!=0)
    {
        cout<<" input number is not prime ";
        return 0;
    }
    int  flug=77;

    while(input)
    {
        int deg=input%10;
        if(status[deg]!=0)
            flug=1;
        input/=10;
    }

    if(flug==77)
        printf("Number %d is prime and its digits are also prime\n", data);
    if(flug==1)
        printf("Number %d is prime but its digits are not prime.\n", data);

    return 0;
}

