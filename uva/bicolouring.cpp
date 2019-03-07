#include<bits/stdc++.h>
using namespace std;

#define sz 210

int nodes,adjMat[sz][sz];
int queueElement[sz], frontElement = 0, rearElement = -1,na[sz];
int level[sz], parent[sz];

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
    for(i=0; i<nodes; i++)
    {
        level[i] = -1;
    }
    enqueueElement(SourceVertex);
    level[SourceVertex] = 0;
    parent[SourceVertex] = 0;
    while(!isEmpty())
    {
        u = dequeueElement();
        for(i=0; i<nodes; i++)
        {
            if(adjMat[u][i] == 1 && level[i] == -1)
            {
                level[i] = level[u] + 1;
                parent[i] = u ;
                enqueueElement(i);
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int edges, SourceVertex;
    cin >> edges;

    frontElement = 0, rearElement = -1;

    int n1, n2;
    for (int i = 0; i<edges; i++)
    {
        cin >> n1 >> n2;
        adjMat[n1][n2] = 1;
        adjMat[n2][n1] = 1;
        na[n1]=1;
        na[n2]=1;

    }
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << adjMat[i][j] << " ";

        }
        cout << endl;
    }

    cout << "Enter the starting vertex: ";
    cin >> SourceVertex;

    breadthFirstSearch(SourceVertex);
    for (int i = 0; i < nodes; i++)
        cout<<level[i]<<" ";
    cout<<endl;

    int des;

    //cout<<"Enter the child node to see it's parent nodes : ";
    cin >> des;
    while (parent[des]!= 0)
    {
        cout<< parent[des]<<" ";
        des = parent[des];
    }
    cout<<endl;


    for(int i=0; i<sz; i++)
        for(int j=0; j<sz; j++)
            adjMat[i][j] = 0;


    return 0;

}
