// 352 The Seasonal War


#include<bits/stdc++.h>
using namespace std;
#define maxx 201

int n;
char mat[maxx][maxx];
int visit[maxx][maxx];

int fx[]= {-1,-1,-1,0,0,1,1,1};
int fy[]= {-1,0,1,-1,1,-1,0,1};


void floodfill(int r,int c)
{
    visit[r][c]=1;

    for(int i=0; i<8; i++)
    {
        int row=r+fx[i];
        int col=c+fy[i];

        if( ( (row>=0&&row<n) && (col>=0&&col<n) ) && visit[row][col]==0)
        {
            visit[row][col]=1;
            if(mat[row][col]=='1')
                floodfill(row,col);
        }

    }
}


int main()
{
    int cas=1;
    while(scanf("%d",&n)==1)
    {

        for(int i=0; i<maxx; i++)
        {
            for(int j=0; j<maxx; j++)
            {
                mat[i][j]= 0;
                visit[i][j]= 0;
            }
        }


        for(int i=0; i<n; i++)
            cin>>mat[i];

        int cn=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(visit[i][j]==0)
                {
                    //visit[i][j]=1;
                    if(mat[i][j]=='1')
                    {
                        cn++;
                        floodfill(i,j);
                    }

                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cas++,cn);

    }

    return 0;
}


/*


6
100100
001010
000000
110000
111000
010100
8
01100101
01000001
00011000
00000010
11000011
10100010
10000001
01100000


*/

