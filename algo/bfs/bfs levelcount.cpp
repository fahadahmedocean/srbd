#include<iostream>
#include<stdio.h>
using namespace std;

int nodes, adjMatrix[100][100];
int queeee[100], front1 = 0, rear = -1;
int level[100] ;



int isEmpty()
{
    if (front1>rear)
        return 1;
    else
        return 0;
}

int isFull()
{

    if (rear == nodes-1)
        return 1;
    else
        return 0;
}

void enqueeee(int n)
{

    if (isFull())
        return;
    else
    {
        rear++;
        queeee[rear] = n;
        return;
    }
}

int dequeeee()
{
    int x;
    if (isEmpty())
        return -1;
    else
    {
        x = queeee[front1];
        front1++;
        return x;
    }
}


void breadthFirstSearch(int SouceVertex)
{
    for(int i=1;i<=nodes;i++)
        level[i]=-1;
    int u;

    enqueeee(SouceVertex);
    level[SouceVertex] = 0;

    while (!isEmpty())
    {
        u = dequeeee();

        for (int i = 1; i <= nodes; i++)
        {
            if (adjMatrix[u][i] == 1 && level[i] == -1)

            {

                level[i] = level[u] + 1;

                enqueeee(i);



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
        adjMatrix[n1][n2] = 1;
        adjMatrix[n2][n1] = 1;

    }
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cout << adjMatrix[i][j] << " ";

        }
        cout << endl;
    }

    cout << "Enter the starting vertex: ";
    cin >> SourceVertex;
     printf("\n");

    breadthFirstSearch(SourceVertex);



       for (int i = 1; i <= nodes; i++)
        printf("%d ", i);
        printf("\n");
    for (int i = 1; i <= nodes; i++)
        printf("%d ", level[i]);



    return 0;

}
