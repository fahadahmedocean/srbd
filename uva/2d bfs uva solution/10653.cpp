#include<stdio.h>
//using namespace std;
#define maxx 1005

int grid[maxx][maxx],visit[maxx][maxx],level[maxx][maxx];
int frnt, rear,n,m;
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
    if (rear==(n*m)-1)
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
    point dQdata;
    dQdata.x=-1;
    dQdata.y=-1;

    if(isEmpty())
        return dQdata;
    else
    {
        dQdata=Qu[frnt];
        frnt++;
        return dQdata;
    }
}

void bfs(point src, point des)
{
    int i;
    point u;
    enQ(src);
    visit[src.x][src.y]=1;
    while(!isEmpty())
    {
        u=deQ();
        for(i=0; i<4; i++)
        {
            int tx=u.x+fx[i];
            int ty=u.y+fy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<m && visit[tx][ty]!=1 && grid[tx][ty]==0)// if 1 thats not allow
            {
                visit[tx][ty]=1;
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
            grid[i][j]= 1;
            level[i][j]=0;
            visit[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            grid[i][j]= 0;

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
    int t,r,no,bomb;
    while(scanf("%d%d",&n,&m)==2)
    {

        if (n==0 && m==0)
            break;

        init();

        scanf("%d",&t);
        for(int i=0; i<t; i++)
        {
            scanf("%d%d",&r,&no);
            while(no--)
            {
                scanf("%d",&bomb);
                grid[r][bomb]=1; // 1 means block
            }
        }
        int sx,sy;
        scanf("%d%d",&sx,&sy);

        int dx,dy;
        scanf("%d%d",&dx,&dy);

//        cout<<endl;
//        cout<<endl;
//        for(int i=0; i<=n; i++)
//        {
//            for(int j=0; j<=m; j++)
//                cout<<grid[i][j]<<" ";
//            cout<<endl;
//        }
        point src, des;
        src.x=sx;
        src.y=sy;
        des.x=dx;
        des.y=dy;

        bfs(src,des);
        printf("%d\n",level[dx][dy]);

    }
    return 0;

}
