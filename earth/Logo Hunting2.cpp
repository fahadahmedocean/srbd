#include <bits/stdc++.h>
using namespace std;

int n,m;
int dx[8]={1 ,1 ,0 ,0 ,-1,-1,-1,1 };
int dy[8]={-1,1 ,1 ,-1,-1,0 ,1 ,0 };
string str[51];
string logo[3]={"F","O","P"};
int holes;

void floodFill(int a,int b,char s1,char s2)
{
	if(a>n || a<1 || b>m || b<1)
		return;
	if(str[a][b]!=s1)
		return;
	str[a][b]=s2;
	for(int i=0;i<8;i++)
		floodFill(a+dx[i],b+dy[i],s1,s2);
}

void dfs(int a,int b)
{
	if(a>n || a<1 || b>m || b<1)
		return;
	if(str[a][b]=='1')
	{
		str[a][b]='X';
		for(int i=0;i<8;i++)
			dfs(a+dx[i],b+dy[i]);
	}
	if(str[a][b]=='.')
	{
		holes++;
		floodFill(a,b,'.','E');
	}
}

int main()
{
	int i,j;
	cin>>n>>m;
	string res="";

	for(i=1;i<=n;i++)
		cin>>str[i];
	floodFill(1,1,'.','E');

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(str[i][j]=='1')
			{
				holes=0;
				dfs(i,j);
				res+=logo[holes];
			}
		}
	}
	sort(res.begin(),res.end());

	if(res.size()==0)
		cout<<"N"<<endl;
	else
		cout<<res<<endl;
}
