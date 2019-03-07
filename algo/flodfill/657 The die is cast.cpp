//657 The die is cast

#include <stdio.h>

using namespace std;

char pic[51][51];
int w, h;

int fx[]= {1,0,-1,0};
int fy[]= {0,1,0,-1};


void floodfill_X (int i, int j)
{

    if(pic[i][j] == 'X')
    {
        pic[i][j] = '*';
        int a,b;
        for(int k=0; k<4; k++)
        {
            a=i+fx[k];
            b=j+fy[k];
            floodfill_X(a,b);
        }
    }

}

void ff_dot (int i, int j, int &dots)
{
    if (pic[i][j] == 'X')
    {
        dots++;
        floodfill_X(i, j);
    }


    if(pic[i][j] != '.' && i>=0 && j>=0 && i<h && j<w)
    {
        pic[i][j] = '.';
        int a,b;
        for(int k=0; k<4; k++)
        {
            a=i+fx[k];
            b=j+fy[k];
             ff_dot(a, b, dots);
        }
    }
}

int main()
{
//   freopen("input.txt","rt",stdin);
    int Case = 1;
    while (scanf("%d%d", &w, &h))
    {
        if (0==w && 0==h)
            break;

        getchar();
        for (int i = 0; i < h; i++)
            gets(pic[i]);

        int ans[100] = {0}, nOfans = 0;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (pic[i][j] == '*')
                {
                    ff_dot(i, j, ans[nOfans]);
                    nOfans++;
                }

        //just sort the ans array
        for(int k=0; k<nOfans-1; k++)
        {
            for(int p=0; p<nOfans-1-k; p++)
            {
                if (ans[p] > ans[p+1])
                {
                    int temp= ans[p];
                    ans[p]=ans[p+1];
                    ans[p+1]=temp;
                }
            }
        }


        printf("Throw %d\n", Case++);
        for (int i = 0; i < nOfans; i++)
        {
            if (i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n\n");
    }
    return 0;
}

