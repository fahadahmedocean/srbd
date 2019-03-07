#include<bits/stdc++.h>

using namespace std;

typedef pair<unsigned short, unsigned short> point;
unsigned short M = 250, N = 250;
char dc[251][251];
inline unsigned short  Max(unsigned short x, unsigned short y)
{
    return x ^ ((x ^ y) & -(x < y));
}

inline unsigned short Min(unsigned short x, unsigned short y)
{
    return y ^ ((x ^ y) & -(x < y));
}

void clear()
{
    for(int i=0; i < N; i++)
    {
        memset(dc[i], 'O', M);
        dc[i][M] = '\0';
    }
}

void apply_color(point& A, point& B, char C)
{
    if (A == B)
    {
        dc[A.second][A.first] = C;
    }
    else if (A.first == B.first)
    {
        while(A.second <= B.second)
        {
            dc[A.second++][A.first] = C;
        }
    }
    else
    {
        while(A.second <= B.second)
        {
            memset(dc[A.second]+A.first, C, B.first-A.first+1);
            A.second++;
        }
    }
}

void fill_color(const point& A, char P, char C)
{
    bool spanLeft, spanRight;
    stack<point> S;
    S.push(A);
    while(S.empty() == false)
    {
        point n = S.top();
        short x, y;
        x = n.first;
        y = n.second;
        S.pop();
        while(y >= 0 && dc[y][x] == P)
            y--;
        y++;
        spanLeft = spanRight = false;
        while(y < N && dc[y][x] == P )
        {
            dc[y][x] = C;
            if((!spanLeft) && x > 0 && dc[y][x-1] == P)
            {
                S.push(point(x-1, y));
                spanLeft = true;
            }
            else if(spanLeft && x > 0 && dc[y][x-1] != P)
            {
                spanLeft = false;
            }
            if((!spanRight) && x < M-1 && dc[y][x+1] == P)
            {
                S.push(point(x+1, y));
                spanRight = true;
            }
            else if(spanRight && x < M-1 && dc[y][x + 1] != P)
            {
                spanRight = false;
            }
            y++;
        }
    }
}

bool process_cmd(const string& cmdline)
{
    bool result = false;
    stringstream tokens(stringstream::in | stringstream::out);
    tokens << cmdline;
    char cmd, C;
    unsigned short X1,X2, Y1, Y2;
    tokens >> cmd;
    switch(cmd)
    {
    case 'I':
        tokens >> M >> N;
        if(M > 0 && M <= 250 && N> 0 && N <= 250)
            clear();
        else
            M=N=0;
        break;
    case 'C':
        if(M > 0 && M <= 250 && N> 0 && N <= 250)
            clear();
        break;
    case 'L':
        tokens >> X1 >> Y1 >> C;
        X1--;
        Y1--;
        if(X1 < M && Y1 < N && C >= 'A' && C <= 'Z')
        {
            point A(X1, Y1);
            apply_color(A, A, C);
        }
        break;
    case 'V':
        tokens >> X1 >> Y1 >> Y2 >> C;
        X1--;
        Y1--;
        Y2--;
        if(X1 < M && Y1 < N && Y2 < N && C >= 'A' && C <= 'Z')
        {
            point A(X1, min(Y1, Y2)), B(X1, max(Y1, Y2));
            apply_color(A, B, C);
        }
        break;
    case 'H':
        tokens >> X1 >> X2 >> Y1 >> C;
        X1--;
        X2--;
        Y1--;
        if(X1 < M && X2 < M && Y1 < N && C >= 'A' && C <= 'Z')
        {
            point A(min(X1, X2), Y1), B(max(X1, X2), Y1);
            apply_color(A, B, C);
        }
        break;
    case 'K':
        tokens >> X1 >> Y1 >> X2 >> Y2 >> C;
        X1--;
        X2--;
        Y1--;
        Y2--;
        if(X1 < M && X2 < M && Y1 < N && Y2 < N && C >= 'A' && C <= 'Z')
        {
            if(X1 > X2)
                swap(X1, X2);
            if(Y1 > Y2)
                swap (Y1, Y2);
            point A(X1, Y1), B(X2, Y2);
            apply_color(A, B, C);

        }
        break;
    case 'F':
        tokens >> X1 >> Y1 >> C;
        X1--;
        Y1--;
        if(X1 < M && Y1 < N && C >= 'A' && C <= 'Z' && dc[Y1][X1] != C)
        {
            fill_color(point(X1, Y1), dc[Y1][X1], C);
        }
        break;
    case 'S':
    {
        string filename;
        tokens >> filename;
        cout << filename << endl;
        copy(dc, dc+N, ostream_iterator<string>(cout, "\n"));
    }
    break;
    case 'X':
        result= true;
        break;
    default:
        break;
    }
    return result;
}

/* main
 * */
int main()
{
    bool exit = false;
    while ( exit == false )
    {
        string cmdline;
        getline(cin, cmdline);
        exit = process_cmd(cmdline);
    }
    return 0;
}
