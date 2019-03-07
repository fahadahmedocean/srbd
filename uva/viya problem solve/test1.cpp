#include<iostream>
using namespace std;
char str[100];
char temp[100];
int visit[100]= {0};


void permute(int pos, int len)
{
    if(pos>=len)
    {
        temp[pos]='\0';
        cout << "-->" << temp << '\n';
        return;
    }

    int seen[100]={0};
    for(int i=0; i<len; i++)
    {
        if(visit[i]==0  && seen[str[i]-'a']==0)
        {
            visit[i]=1;
            seen[str[i]-'a']=1;
            temp[pos]=str[i];
            permute(pos+1,len);
            visit[i]=0;
        }
    }
}
int main()
{
    cin>> str;
    int sz=0;
    while(str[sz]!='\0')
        sz++;
    permute(0,sz);

}

