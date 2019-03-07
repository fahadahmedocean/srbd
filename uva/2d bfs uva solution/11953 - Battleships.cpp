#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define maxx 101

int grid[maxx][maxx],level[maxx][maxx],visit[maxx][maxx];
char mat[maxx][maxx];
int frnt, rear;
int n;

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};

struct point
{
    int x;
    int y;
};

point Qu[maxx*maxx];
int isEmpty()
{
    if(frnt>rear)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear==(n*n)-1)
        return 1;
    else
        return 0;
}
void enQ( point data)
{
    if(isFull())
        return;
    else
    {
        rear++;
        Qu[rear]=data;
        return;
    }
}
point deQ()
{
    point dqdata;
    dqdata.x=-1;
    dqdata.y=-1;
    if(isEmpty())
        return dqdata;
    else
    {
        dqdata=Qu[frnt];
        frnt++;
        return dqdata;
    }
}

void bfs(point src)
{
    int i;
    point u;
    enQ(src);
    //cout<<"enq   "<<"src :"<<src.x<<src.y<<endl;
    visit[src.x][src.y]=1;

    while(!isEmpty())
    {
//        for(int j=0; j<n; j++)
//            cout<<Qu[j].x<<","<<Qu[j].x<<"   ";
//        cout<<endl;
        u=deQ();
//        cout<<"deQ:  "<<u.x<<u.y<<endl;
//
//        cout<<"visit"<<endl;
//        cout<<endl;
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//                cout<<grid[i][j];
//            cout<<endl;
//        }

        for(i=0; i<4; i++)
        {
            int tx=u.x+fx[i];
            int ty=u.y+fy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<n && visit[tx][ty]!=1 && (grid[tx][ty]==1||grid[tx][ty]==2))
            {
                visit[tx][ty]=1;
                grid[tx][ty]==0;

                level[tx][ty]=level[u.x][u.y]+1;

                point newEnQData;
                newEnQData.x=tx;
                newEnQData.y=ty;

                enQ(newEnQData);

            }
        }
    }

}


void init()
{
    for(int i=0; i<maxx; i++)
    {
        for(int j=0; j<maxx; j++)
        {
            grid[i][j]= 0;
            level[i][j]=0;
            visit[i][j]=0;
        }
    }

    for(int i=0; i<maxx*maxx; i++)
    {
        Qu[i].x=0;
        Qu[i].y=0;
    }
    frnt=0;
    rear=-1;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        init();
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                //puts(mat[i][j]);
                cin>>mat[i][j];
                //scanf("%s",&mat[i][j]);
                if(mat[i][j]=='.')
                    grid[i][j]=0;
                else if (mat[i][j]=='x')
                    grid[i][j]=2;
                else
                    grid[i][j]=1;

            }
        }

//        cout<<endl;
//        cout<<endl;
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//                cout<<mat[i][j];
//            cout<<endl;
//        }

//        cout<<endl;
//        cout<<endl;
//
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//                cout<<grid[i][j];
//            cout<<endl;
//        }

        point src;
        int ans=0;
        for(int p=0; p<n; p++)
        {
            for(int q=0; q<n; q++)
            {
                if((grid[p][q]==2) && visit[p][q]!=1)
                {
                    ans++;
                    src.x=p;
                    src.y=q;
                    // cout<<"src :"<<src.x<<src.y<<endl;
                    bfs(src);
                }
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;

}
