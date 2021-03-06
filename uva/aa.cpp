#include<iostream>
#include<stdio.h>
using namespace std;

int nodes,adjMat[100][100];
int queueElement[100], frontElement = 0 , rearElement = -1;
int level[100], parent[100],color[100];

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

void breadthFirstSearch(int SourceVertex)
{
    int u, i;
    for(i=1; i<=nodes; i++)
    {
        level[i] = -1;
        color[i] = -1;
    }
    enqueueElement(SourceVertex);
    level[SourceVertex] = 0;
    parent[SourceVertex] = 0;
    color[SourceVertex] = 0;
    while(!isEmpty())
    {
        u = dequeueElement();
        for(i=1; i<=nodes; i++)
        {
            if(adjMat[u][i] == 1 )
            {
                if(color[u]!=color[i])
                {
                    color[i] = 1 - color[u] ;
                }

                else
                {
                    cout<<"NOT BICOLORABLE."<<endl;
                    return;

                }
                if(level[i] == -1)
                {
                    level[i] = level[u] + 1;
                    parent[i] = u ;
                    enqueueElement(i);
                }
            }

        }

    }
     cout<<"BICOLORABLE."<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int edges, SourceVertex;
  // int edges, SourceVertex;
    while(cin >> nodes)

    {
        if (nodes==0)
            break;

        cin>> edges;

    int n1, n2;

    for (int i = 0; i<edges; i++)
    {
        cin >> n1 >> n2;
        adjMat[n1][n2] = 1;
        adjMat[n2][n1] = 1;

    }
//    for (int i = 1; i <= nodes; i++)
//    {
//        for (int j = 1; j <= nodes; j++)
//        {
//            cout << adjMat[i][j] << " ";
//
//        }
//        cout << endl;
//    }

    //cout << "Enter the starting vertex: ";
   // cin >> SourceVertex;

    breadthFirstSearch(1);
//    for (int i = 1; i <= nodes; i++)
//        cout<<level[i]<<" ";
//    cout<<endl;
//
//    int des;
//    cout<<"Enter the child node to see it's parent nodes : ";
//    cin >> des;
//    while (parent[des]!= 0)
//    {
//        cout<< parent[des]<<" ";
//        des = parent[des];
//    }
//    cout<<endl;
    }

    return 0;

}
