#include <stdio.h>
#include <stdlib.h>

char arr[5][5]={    {'1','1','1','1','1'},
                    {'1','S','X','1','1'},
                    {'1','1','1','1','1'},
                    {'X','1','1','E','1'},
                    {'1','1','1','1','X'}   };
int minimum[20];
int ind=0;

void addToMin(int len)
{
    minimum[ind++]=len;
}

int IsInPath(int (*path)[5],int r,int c)
{
    if(path[r][c]==0)   return 0;
    else    return 1;


}

int isValid(int r,int c)
{
    if((r>=0 && r<=4) && (c>=0 && c<=4))
        return 1;
    else
        return 0;
}


void findMin(int (*path)[5],int len,int r,int c)
{
    int path2[5][5];
    int i,j;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            path2[i][j]=0;

    if(arr[r][c]=='E')
    {
        addToMin(len);
    }
    else if(arr[r][c]=='X' || (arr[r][c]=='1' && IsInPath(path,r,c)))
    {
        return;
    }
    else if((arr[r][c]=='1' && !IsInPath(path,r,c)) || arr[r][c]=='S')
    {
        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
                path2[i][j]=path[i][j];

        path2[r][c]=1;
        len++;
        if(isValid(r,c-1))          findMin(path2,len,r,c-1);

        if(isValid(r-1,c))          findMin(path2,len,r-1,c);

        if(isValid(r,c+1))          findMin(path2,len,r,c+1);

        if(isValid(r+1,c))          findMin(path2,len,r+1,c);

    }
}

int main()
{
    int i,j,flag=0,min=9999;
    int path[5][5];

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            path[i][j]=0;

    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            if(arr[i][j]=='S')
            {
                findMin(path,0,i,j);
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }

    for(i=0;i<ind;i++)
    {
        if(minimum[i]<min)
              min=minimum[i];
    }

    printf("Minimum Distance =%d",min);
    return 0;
}
