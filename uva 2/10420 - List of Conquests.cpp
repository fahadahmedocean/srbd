#include<stdio.h>
//#include<string.h>

char *strcpynew(char *d, char *s){
   char *saved = d;
   while ((*d++ = *s++) != '\0');

   return saved; //returning starting address of s1
}


int strCmp(char string1[], char string2[] )
{
    int i = 0;
    int flag = 0;
    while (flag == 0)
    {
        if (string1[i] > string2[i])
        {
            flag = 1;
        }
        else if (string1[i] < string2[i])
        {
            flag = -1;
        }

        if (string1[i] == '\0')
        {
            break;
        }

        i++;
    }
    return flag;
}


int main()
{
    int a,i,j,k;
    char cn[2001][30],ld[70];
    while(scanf("%d",&a)==1)
    {
        int count[2001]= {0};
        for(i=0; i<a; i++)
        {
            scanf("%s",cn[i]);
            gets(ld);
        }
        for(i=0; i<a; i++)
            for(j=i+1; j<a; j++)
                if(strCmp(cn[i],cn[j])==0)
                {
                    count[i]++;
                    cn[j][0]='\0';
                }
        for(i=0; i<a-1; i++)
        {
            for(j=i+1; j<a; j++)
            {
                if(cn[j][0]=='\0')
                    continue;
                if(strCmp(cn[i],cn[j])>0)
                {
                    strcpynew(ld,cn[i]);
                    strcpynew(cn[i],cn[j]);
                    strcpynew(cn[j],ld);
                    k=count[i];
                    count[i]=count[j];
                    count[j]=k;
                }
            }
        }
        for(i=0; i<a; i++)
        {
            if(cn[i][0]!='\0')
                printf("%s %d\n",cn[i],count[i]+1);
        }
    }
    return 0;
}
