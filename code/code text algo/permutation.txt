#include<iostream>
using namespace std;

long long int cnt=0,pos;
int visit[100]= {0};

void change(char *a,int i,int j)
{
    int temp = a[j];
    while(j>i)
    {
        a[j] = a[j-1];
        j--;
    }
    a[j] = temp;
}

void revert(char *a,int i,int j)
{
    int temp = a[i];
    while(i<j)
    {
        a[i] = a[i+1];
        i++;
    }
    a[i] = temp;
}

void permute(char *a,int i, int n)
{
    if(i==n)
    {
        cout<<a<<endl;
        return;
    }


    for(int j=i; j<=n; j++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            change(a,i,j);
            permute(a,i+1,n);
            //backtrack
            visit[i]=0;
            revert(a,i,j);

        }
    }

}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        visit[100]= {0};
        char a[50];
        cin>>a;
        int sz=0;
        while(a[sz]!='\0')
        {
            sz++;
        }
        //      cin>>pos;
        permute(a,0,sz-1);
    }
    return 0;
}
