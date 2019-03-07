#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
#define maxx 27


int grid[maxx][maxx], level[maxx][maxx],visit[maxx][maxx];
int frnt,rear;
int ans;

int dx[]= {1,1,-1,-1,2,2,-2,-2};
int dy[]= {2,-2,2,-2,1,-1,1,-1};

struct point
{
    int x;
    int y;
} ;

struct point Qu[maxx*maxx];

int isEmpty()
{
    if(frnt>rear)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear==(ans*ans)-1)
        return 1;
    else
        return 0;
}

void enQ(point data)
{
    if (isFull())
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
    point data;
    data.x=-1;
    data.y=-1;

    if(isEmpty())
        return data;
    else
    {
        data = Qu[frnt];
        frnt++;
        return data;
    }
}

void bfs(point src)
{
    int i;
    point u;
    enQ(src);
    visit[src.x][src.y]=1;
    while(!isEmpty())
    {
        u=deQ();
        for(i=0; i<8; i++)
        {
            int tx=u.x+dx[i];
            int ty=u.y+dy[i];

            if(tx>=0 && ty>=0 && tx<ans &&  ty<ans && visit[tx][ty]!=1 && grid[tx][ty]==1)
            {
                visit[tx][ty]=1;
                level[tx][ty]=level[u.x][u.y]+1;
                point newpnt;
                newpnt.x=tx;
                newpnt.y=ty;
                enQ(newpnt);
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
    //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    char node;
    char ver[3];
    scanf("%d",&test);
    getchar();
    //getchar();


    for(int t=1; t<=test; t++)
    {
                init();
        gets(ver);
        int ans=ver[0]-'A'+1;
        //printf("%d\n",ans);

        while(gets(ver))
        {
             if(ver[0]=='\0')
                break;
            int sx = ver[0] - 'A';
            int sy = ver[1] - 'A';

           // cout<<"sx:  "<<sx<<sy<<endl;
            grid[sx][sy]=1;
            grid[sy][sx]=1;

        }
        point src, des;
        src.x=0;
        src.y=0;
        int conect=0;

        for(int p=0; p<ans; p++)
        {
            for(int q=0; q<ans; q++)
            {
                if((grid[p][q]==1) && visit[p][q]!=1)
                {
                    conect++;
                    src.x=p;
                    src.y=q;
                    // cout<<"src :"<<src.x<<src.y<<endl;
                    bfs(src);
                }
            }
        }
        int finalans=ans-conect;
        cout<<"ANS  : "<<finalans<<endl;


        init();
    }

    return 0;
}
