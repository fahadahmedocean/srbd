#include <bits/stdc++.h>

using namespace std;

int nodes,adjMat[100][100];
int queueElement[100], frontElement = 0, rearElement = -1;
int level[100], parent[100];
int flug=1;

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
    }
    enqueueElement(SourceVertex);
    level[SourceVertex] = 0;
    parent[SourceVertex] = 0;

    while(!isEmpty())
    {
        u = dequeueElement();

//        cout<<"u:  "<<u<<"    ";
//        for (int k = 1; k <= nodes; k++)
//            cout<<parent[k]<<" ";
//        cout<<endl;


        for(i=1; i<=nodes; i++)
        {
            if(adjMat[u][i] == 1)
            {

                if(level[i] == -1)
                {
                    level[i] = level[u] + 1;
                    parent[i] = u ;
                    enqueueElement(i);
                }
                else
                {
//                    printf("add %d %d  :%d  \n",u,i,adjMat[u][i]);
//                    cout<<"level i:  "<<level[i]<<endl;
                    int des=u;
                    while (parent[des]!= 0)
                    {
                        //cout<< parent[des]<<" ";
                        des = parent[des];
                    }

                    int des2=i;
                    while (parent[des2]!= 0)
                    {
                        //cout<< parent[des]<<" ";
                        des2 = parent[des2];
                    }
                    if (parent[des]==parent[des2])
                        flug=11;

                }

            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int edges, SourceVertex;
    cin >> nodes >> edges;

    int n1, n2;

    for (int i = 0; i<edges; i++)
    {
        cin >> n1 >> n2;
        adjMat[n1][n2] = 1;
        //adjMat[n2][n1] = 1;

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


    breadthFirstSearch(1);
    if(flug==11)
        cout<<"cycle detected"<<endl;
    else
        cout<<"cycle not  detected"<<endl;




    for (int i = 1; i <= nodes; i++)
        cout<<level[i]<<" ";
    cout<<endl;



    return 0;

}
