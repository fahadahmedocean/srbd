#include <bits/stdc++.h>
using namespace std;

#define maxx 100

int nodes;
int adjMat[maxx][maxx];
int Qu[maxx*maxx], frnt = 0, rear = -1;
int level[maxx], parent[maxx];
int flug=1;

int isEmpty()
{
    if(frnt> rear)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear == nodes-1)
        return 1;
    else
        return 0;
}

void enQu(int data)
{
    if(isFull())
        return;
    else
    {
        rear++;
        Qu[rear] = data;
        return;
    }
}

int deQu()
{
    int data;
    if(isEmpty())
        return -1;
    else
    {
        data = Qu[frnt];
        frnt++;
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
    enQu(SourceVertex);

    level[SourceVertex] = 0;
    parent[SourceVertex] = 0;

    while(!isEmpty())
    {
        u = deQu();

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
                    enQu(i);
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
