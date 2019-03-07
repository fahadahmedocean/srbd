#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define M 6
#define N 6
int mat[M][N] ;
int visited[M][N];

bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0)
        return true;

    return false;
}

bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 1 || visited[x][y])
        return false;

    return true;
}
void findShortestPath(int mat[M][N], int visited[M][N], int i, int j,int x, int y, int& min_dist, int dist)
{
//    int a=i+1;
//    int b=j+1;
//    cout<<a<<","<<b<<"->  ";



    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }
    visited[i][j] = 1;

    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);

    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);

    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);

    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);

    visited[i][j] = 0;
}

void initaial()
{
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {
            mat[i][j]=1;
            visited[i][j]=0;
        }
}


int main()
{
     //freopen("in.txt","r",stdin);//redirects standard input
    //freopen("output.txt","w",stdout);//redirects standard output
    int test, matsize;
    cin>> test;
    int cnt=1;
    while(test--)
    {
        cin>> matsize;
        int min_dist = 99999;
        int source_x,source_y,destination_x,destination_y;

        initaial();

        for(int i=0; i<matsize; i++)
        {
            for(int j=0; j<matsize; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]==2)
                {
                    source_x=i;
                    source_y=j;
                }
                if(mat[i][j]==3)
                {
                    destination_x=i;
                    destination_y=j;
                }

            }

        }
        findShortestPath(mat, visited, source_x, source_y, destination_x, destination_y, min_dist, 0);

        printf("\nCase %d : ",cnt++);
        if(min_dist != 99999)
            printf("The shortest path from source (%d,%d) to destination (%d,%d)  has length = %d\n",source_x+1, source_y+1, destination_x+1, destination_y+1, min_dist);

        else
            printf("Destination (%d,%d) can't be reached from given source (%d,%d)\n",source_x+1, source_y+1, destination_x+1, destination_y+1);

    }
    return 0;
}
