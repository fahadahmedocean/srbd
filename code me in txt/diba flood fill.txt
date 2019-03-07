#include <iostream>
using namespace std;

int n, grid[6][6], found[6][6];
int visited[6][6] = { 0 };

int isValid(int r, int c)
{
    if (r < n && c < n && r >= 0 && c >= 0)
        return 1;

    return 0;
}

int canMove(int x , int y)
{
    if ((grid[x][y] == 1 && grid[x + 1][y] == 1) && (grid[x][y] == 1 && grid[x][y + 1] == 1) ||
        (grid[x][y] == 1 && grid[x - 1][y] == 1) && (grid[x][y] == 1 && grid[x][y - 1] == 1))
        return 0;
    if (visited[x][y])
        return 0;

        return 1;
}


void findPath(int nx, int ny, int mx, int my, int& mindist, int dist, int& ways)
{

    if (nx == mx && ny == my)
    {
        if (mindist > dist)
        {
            mindist = dist;

        }
        ways++;
        return;

    }

    visited[nx][ny] = 1;

        if (isValid(nx + 1, ny) && canMove(nx + 1, ny))//down
        {
            findPath(nx + 1, ny, mx, my, mindist, dist + 1, ways);
        }


        if (isValid(nx, ny + 1) && canMove(nx, ny + 1))// right
        {
            findPath(nx, ny + 1, mx, my, mindist, dist + 1, ways);
        }


        if (isValid(nx - 1, ny) && canMove(nx - 1, ny))// up
        {
            findPath(nx - 1, ny, mx, my, mindist, dist + 1, ways);

        }


        if (isValid(nx, ny - 1) && canMove(nx, ny - 1))//left
        {
            findPath(nx, ny - 1, mx, my, mindist, dist + 1, ways);
        }

    visited[nx][ny] = 0;
}

void initCase()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            grid[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        initCase();
        cin >> n;
        //int grid[M][N];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << endl;
        int sx, sy;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }

            }
        }
        cout <<"Source co-ordinates : "<< sx << " " << sy << endl;


        int dx, dy;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 3)
                {
                    dx = i;
                    dy = j;
                }

            }
        }
        cout<<"Destination co-ordinate : " << dx << " " << dy << endl;
        cout<<endl;

        //memset(visited, 0, sizeof visited);
        int mindist = 999;
        int ways = 0;
        findPath(sx,sy,dx,dy, mindist, 0, ways);
//        if(ways!=0 && mindist!=999)
//        cout<<"Number of ways to reach destination : "<<ways<< "  "<<mindist <<endl;
//        else
//            cout<<"No ways found";
//        cout<<endl;

        if(mindist != 999)
            cout << "Shortest path : " <<  mindist<<endl;
        else
            cout<<"NO PATH FOUND"<<endl;
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

