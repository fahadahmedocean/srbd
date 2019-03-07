#include <stdio.h>

int main()
{
    int kase;
    while(1)
    {
        scanf("%d",&kase);
        if(kase==-1)
            break;
        for(int i=0; i<kase; i++)
        {
            int D,I,P=1;
            scanf("%d %d",&D,&I);
            while(D--)
            {
                //if(D==1)break;
                if(I%2!=0)
                {
                    I=I/2+1;
                    P=P*2;
                }
                else
                {
                    P = P*2+1;
                    I = I/2;
                }
            }
            printf("%d\n",P/2);
        }
    }
    return 0;
}
