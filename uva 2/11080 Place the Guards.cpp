#include<iostream>
#include<stdio.h>

#define maxx 210
using namespace std;

int nodes,adjMat[maxx][maxx];
int queueElement[maxx], frontElement = 0, rearElement = -1;
int color[maxx], flug;

int isEmpty()
{
    if(frontElement> rearElement)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rearElement == nodes-1)
        return 1;
    else
        return 0;
}

void enqueueElement(int data)
{
    if(isFull())
        return;
    else
    {
        rearElement++;
        queueElement[rearElement] = data;
        return;
    }
}

int dequeueElement()
{
    int data;
    if(isEmpty())
        return -1;
    else
    {
        data = queueElement[frontElement];
        frontElement++;
        return data;
    }
}

int breadthFirstSearch(int SourceVertex)
{

    int u, i;


//    for(i=0; i<nodes; i++)
//    {
//        color[i] =-1;
//    }

    enqueueElement(SourceVertex);
    color[SourceVertex] = 1;

    while(!isEmpty())
    {
        u = queueElement[frontElement];
        dequeueElement();
        //cout<<"Deq "<<u<<endl;

        for(i=0; i<nodes; i++)
        {
            int v=adjMat[u][i];
            //cout<<i<<' '<<v<<endl;
            if(v==0)
                continue;
            if (color[i]==-1)
            {
                if(color[u]==1)
                    color[i]=2;
                else if  (color[u]==2)
                    color[i]=1;
                //cout<<"EnQ "<<i<<endl;
                enqueueElement(i);
            }
            else
            {
                if (color[u]==color[i])
                {
                    flug=99;
                    return 0;
                }
            }

        }
    }
    return 1;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    int test;
    cin>> test;

    int edges, SourceVertex;
    while(test--)

    {
        cin >> nodes>>edges;
        frontElement = 0, rearElement = -1;

        int n1, n2;

        for (int i = 0; i<edges; i++)
        {
            cin >> n1 >> n2;
            adjMat[n1][n2] = 1;
            adjMat[n2][n1] = 1;
        }

//        for (int i = 1; i <= nodes; i++)
//        {
//            for (int j = 1; j <= nodes; j++)
//            {
//                cout << adjMat[i][j] << " ";
//
//            }
//            cout << endl;
//        }


        for(int i=0; i<=nodes; i++)
            color[i] = -1;

        flug=1;

        for(int i=0; i<=nodes; i++)
            if (color[i] == -1)
                breadthFirstSearch(i);


//        cout<<"bb\n";
//        cout<<"color \n\n";
//        for(int i=0; i<nodes; i++)
//        {
//            cout<<color[i]<<"  ";
//        }
//        cout<<endl;


        if(flug==1)
        {
            int cnt1=0,cnt2=0;
            for(int i=0; i<nodes; i++)
            {
                if(color[i]==1)
                    cnt1++;
                if(color[i]==2)
                    cnt2++;
            }
            // cout<<cnt1<<"   cnt2:  "<<cnt2<<endl;
            if(cnt1==cnt2)
                cout<<cnt1<<endl;
            if(cnt1<cnt2 )
                cout<<cnt1<<endl;
            if(cnt1>cnt2 )
                cout<<cnt2<<endl;

        }

        else
            printf("-1\n");


        for(int i=0; i<maxx; i++)
        {
            for(int j=0; j<maxx; j++)
            {
                adjMat[i][j] = 0;
            }
        }


    }
    return 0;

}
