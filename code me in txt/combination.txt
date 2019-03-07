#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool use[11];
char ch[11],ans[11];
int len;

void perm(int cur)
{
    if (cur == len)
    {
        ans[cur]='\0';
        puts(ans);
        return;
    }
    else
    {
        char last='\0';
        for(int i=0; i<len; i++)
        {
            if ((!use[i])&&(ch[i] != last))
            {
                last=ch[i];
                use[i]=1;
                ans[cur]=ch[i];
                perm(cur+1);
                use[i]=0;
            }
        }
    }
}


int main()
{
    int n;
    char tmp;
    while(scanf("%d",&n)==1)
    {
        gets(ch);
        for(int i=0; i<n; i++)
        {
            gets(ch);
            len=strlen(ch);
            sort(ch,ch+len);
            memset(use,0,sizeof(use));
            perm(0);
            printf("\n");
        }
    }
    return 0;
}
