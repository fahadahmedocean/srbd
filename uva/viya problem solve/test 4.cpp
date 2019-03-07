#include <bits/stdc++.h>
using namespace std;
int i, j,n;
int a[20][20];
int row, col;


int print_board()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j] = '-';
        }
    }

}

int print_Array()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%c\t",a[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

int place_Queen(int row, int col)
{
    a[row][col] = 'Q';
}

/* The function were I got the problem */
int safeToPlace(int row, int col)
{
    int i, j, flag;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=n; j++)
        {
            int k = abs(row - i);
            int l = abs(col - n);
            if(a[i][col] != 'Q' && a[k][l] != 'Q')
            {
                flag =1;
            }
            else
            {
                flag =0;
                break;
            }
        }
    }
    return flag;
}


main()
{
    //clrscr();
    printf("Enter no. of queen(s): ");
    scanf("%d",&n);

    print_board();

    for(i=1; i<=n; i++)
    {
        printf("\n\nPosition of Queen %d",i);
        printf("\n\tRow: ");
        scanf("%d",&row);
        printf("\tColumn: ");
        scanf("%d",&col);

        if(safeToPlace(row,col) == 1)
        {
            place_Queen(row,col);
        }

    }
    print_Array();


    //getch();
}


