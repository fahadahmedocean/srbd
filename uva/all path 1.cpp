#include <bits/stdc++.h>
using namespace std;
#define N 5

int visited[N][N];
int maze[N][N];

bool isValidCell(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;

    return true;
}

void countPaths(int maze[N][N], int x, int y, int desx,int desy,int visited[N][N], int& count)
{

    if (x == desx && y == desy)
    {
        count++;
        return;
    }
    visited[x][y] = 1;
    if (isValidCell(x, y) && maze[x][y])
    {

        if (x + 1 < N && !visited[x + 1][y])
            countPaths(maze, x + 1, y,desx,desy, visited, count);

        if (x - 1 >= 0 && !visited[x - 1][y])
            countPaths(maze, x - 1, y, desx,desy,visited, count);

        if (y + 1 < N && !visited[x][y + 1])
            countPaths(maze, x, y + 1, desx,desy,visited, count);

        if (y - 1 >= 0 && !visited[x][y - 1])
            countPaths(maze, x, y - 1, desx,desy,visited, count);
    }

    visited[x][y] = 0;
}

void initaial()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            maze[i][j]=0;
            visited[i][j]=0;
        }
}

int main()
{


    int test, matsize;
    cin>> test;
    int cnt=1;
    while(test--)
    {
        cin>> matsize;
        int count = 0;
        int source_x,source_y,destination_x,destination_y;
        initaial();

        for(int i=0; i<matsize; i++)
        {
            for(int j=0; j<matsize; j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]==2)
                {
                    source_x=i;
                    source_y=j;
                }
                if(maze[i][j]==3)
                {
                    destination_x=i;
                    destination_y=j;
                }

            }

        }

        countPaths(maze, source_x,source_y,destination_x,destination_y, visited, count);

        cout << "Total number paths are " << count<<endl;

    }
}











//https://www.techiedelight.com/find-total-number-unique-paths-maze-source-destination/
//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
//https://www.hackerearth.com/practice/notes/dynamic-programming-problems-involving-grids/

