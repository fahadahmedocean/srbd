#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// A utility function to find min of two integers
int maxx(int x, int y)
{
    return (x > y)? x: y;
}

#define MAXC 1000
char A[MAXC],B[MAXC];
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];


string ans;


void printLCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
    {
        cout<<ans<<endl;
        return;
    }
    if(A[i]==B[j])
    {
        ans+=A[i];
        printLCS(i+1,j+1);
    }
    else
    {
        if (dp[i+1][j]>dp[i][j+1])
            printLCS(i+1,j);
        else
        {
            printLCS(i,j+1);
        }
    }
}


void printAll(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
    {
        cout<<ans<<endl;
        return;
    }
    if(A[i]==B[j])
    {
        ans+=A[i];
        printAll(i+1,j+1);
        ans.erase(ans.end()-1); //Delete last character
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            printAll(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])
            printAll(i,j+1);
        else
        {
            printAll(i+1,j);
            printAll(i,j+1);
        }
    }
}




int calcLCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
        return 0;
    if(visited[i][j])
        return dp[i][j];

    int ans=0;
    if(A[i]==B[j])
        ans=1+calcLCS(i+1,j+1);
    else
    {
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        ans=maxx(val1,val2);
    }
    visited[i][j]=1;
    dp[i][j]=ans;

    //  print_LCS(i,j);
    return dp[i][j];
}
int main()
{
    scanf("%s%s",A,B);
    lenA=strlen(A);
    lenB=strlen(B);
    printf("%d\n",calcLCS(0,0));

    //printLCS(0,0);
    printAll(0,0);

    return 0;

}
