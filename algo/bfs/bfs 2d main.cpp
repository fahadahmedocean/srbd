#include<bits/stdc++.h>
using namespace std;
#define maxx 10

int n;
int grid[maxx][maxx], visited[maxx][maxx],level[maxx][maxx];

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};

int frnt=0,rear=-1;

struct point
{
    int x;
    int y;
};
struct point que[maxx*maxx], path[maxx][maxx];

int isEmpty()
{
    if(frnt>rear)
        return 1;
    else
        return 0;

}
int isFull()
{
    if(rear== (n*n)-1)
        return 1;
    else
        return 0;
}

void enque(point data)
{
    if(isFull())
        return;
    else
    {
        rear++;
        que[rear] = data;
        return;
    }
}
point dque()
{
    point data;
    data.x=-1;
    data.y=-1;

    if(isEmpty())
        return data;
    else
    {
        data = que[frnt];
        frnt++;
        return data;
    }
}



void bfs2d(point src, point des)
{
    visited[n][n]= {0};
    level[n][n]= {};
    path[maxx][maxx]= {0};

    int i;
    point u;

    enque(src);
    visited[src.x][src.y]=1;
    level[src.x][src.y]=0;

    //path[src.x][src.y]=;

    while(!isEmpty())
    {
        u = dque();
        //printf ("\n deque    [%d,%d] \n ", u.x, u.y);

        for(i=0; i<4; i++)
        {
            int tx=u.x+fx[i];
            int ty=u.y+fy[i];
            //cout<<tx<<"  ty "<<ty<<endl;

            if(tx>=0 && tx<=n && ty>=0 && ty<=n && visited[tx][ty]==0&& grid[tx][ty]!=0) //1 means on
            {
                visited[tx][ty]=1;
                level[tx][ty]=level[u.x][u.y]+1;

                //cout<<tx<<"  ty "<<ty<<endl;
                path [tx][ty]=u;

                point newpnt;
                newpnt.x=tx;
                newpnt.y=ty;
                enque(newpnt);
                // printf ("\n             en      [%d,%d] \n ", newpnt.x, newpnt.y);

            }
        }

    }

}

int main()
{
    cin>>n;
    int i,j;
    int sc_x,sc_y,des_x,des_y;

    for(i=0; i<n; i++)
    {

        for(j=0; j<n; j++)
        {
            cin>>grid[i][j];

            if(grid[i][j]==2)
            {
                sc_x=i;
                sc_y=j;
            }
            if(grid[i][j]==3)
            {
                des_x=i;
                des_y=j;
            }
        }
    }

    point src, des;
    src.x=sc_x;
    src.y=sc_y;

    des.x=des_x;
    des.y=des_y;



    bfs2d(src,des);
    //bfs2d(0,0);


    cout << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;
    cout << endl;
    cout << " shortest distence : "<< level[des_x][des_y]<<endl;


    cout << "destina tion point ["<<des_x+1<<"," <<des_y+1<< "] ";


    return 0;

}
