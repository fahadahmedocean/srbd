#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf printf
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define mp make_pair
#define pb push_back
#define first fr
#define second sc
#define inf (1<<30)-2
#define sz  100

typedef long long int ll;
typedef unsigned long long int ull;



//int xx[] = {0, 1,  0, -1,    -1, 1,  1, -1 };     //4 & 8 move
//int yy[] = {1, 0, -1,  0,     1, 1, -1,-1 };


/*------------------------------------------------------------*/

struct node
{
    int d,m,y,c;
    node () {}
    node (int a,int b,int e,int f)
    {
        d=a;
        m=b;
        y=e;
        c=f;

    }
};
vector<node>vec;

int chk(int year)
{
    if((year%4==0 && year%100!=0)||(year%400==0))
    return 1;
    else return 0;
}

int main()

{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//#endif
int tst,i,j,k,l;
int d,m,y,c;

while(sf1(tst)==1)
{
    if(tst==0)
    return 0;
    vec.clear();
    for(i=0;i<tst;i++)
    {
        scanf("%d %d %d %d",&d,&m,&y,&c);
        vec.pb(node(d,m,y,c));
    }
//    for(i=0;i<tst;i++)
//    {
//       pf("%d %d %d %d\n",vec[i].d,vec[i].m,vec[i].y,vec[i].c);
//
//    }

    int cnt=0;
    ull total=0;
    for(i=1;i<tst;i++)
    {
        int d1,d2,m1,m2,y1,y2;
        d2=vec[i].d;
        d1=vec[i-1].d;
        m2=vec[i].m;
        m1=vec[i-1].m;
        y2=vec[i].y;
        y1=vec[i-1].y;
        if(d1==31 && m1==12 && d2==1 && m2==1 && y2-y1==1)
        {
            cnt++;
            total+=vec[i].c-vec[i-1].c;
        }
        else if(y1==y2)
        {
            if(m1==m2)
            {
                if(d2-d1==1)
                {
                    cnt++;
                    total+=vec[i].c-vec[i-1].c;
                }
            }
            else if(m2-m1==1)
            {
                if(d2==1 && ((m1==1 && d1==31)||(chk(y1)==0 && m1==2 && d1==28) || (m1==3 && d1==31)||
                (m1==4 && d1==30)||(m1==5 && d1==31)||(m1==6 && d1==30)||
                (m1==7 && d1==31)|| (m1==8 && d1==31)||(m1==9 && d1==30)||
                (m1==10 && d1==31)||(m1==11 && d1== 30)|| (chk(y1)==1 && m1==2 && d1==29)))
                {
                    cnt++;
                    total+=vec[i].c-vec[i-1].c;
                }

            }
        }

    }
    pf("%d %llu\n",cnt,total);

}
    return 0;
}
