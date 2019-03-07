#include<stdio.h>
#define maxx 8
#define n 8

int grid[maxx][maxx], level[maxx][maxx],visit[maxx][maxx];
int frnt,rear;

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
    if (rear==(n*n)-1)
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

void bfs(point src, point des)
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

            if(tx>=0 && ty>=0 && tx<n &&  ty<n && visit[tx][ty]!=1)
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
    for (int i = 0; i < maxx; i++)
    {
        for (int j = 0; j <maxx; j++)
        {
            level[i][j]= 0;
            visit[i][j]=0;
        }
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

    char str1[3], str2[3];
    point src, des;
    init();
    while(scanf("%s%s",&str1,&str2)==2)
    {
        int sx = str1[0] - 97;
        int sy = str1[1] - '0';
        int dx = str2[0] - 97;
        int dy = str2[1] - '0';

        sy--;
        dy--;

        src.x=sx;
        src.y=sy;
        des.x=dx;
        des.y=dy;

        if (src.x==des.x && src.y==des.y)
        {
            printf("To get from %s to %s takes 0 knight moves.\n",str1,str2);
            //cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<"0"<<" knight moves."<<endl;
            continue;
        }

        bfs(src,des);
        printf("To get from %s to %s takes %d knight moves.\n",str1,str2,level[dx][dy]);
        //cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<level[dx][dy]<<" knight moves."<<endl;

        init();
    }
    return 0;
}
