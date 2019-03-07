#include <stdio.h>
#include <math.h>

int  main ()
{
    int n, x,y,t,sum,i,m ;

    scanf ("%d",&t) ;
    for (i=1 ; i<=t ; i++)
    {
        scanf ("%d",&n) ;
        m= n ;
        sum=0;
        while (sum != 1)
        {
            sum =0 ;

            while (m>0)
            {
                x = m%10 ;
                y = m/10 ;
                sum = sum + pow (x,2) ;
                m =y ;
            }

            m = sum ;

            if (sum<=9)
            {
                if(sum!=1)
                    printf ("Case #%d: %d is an Unhappy number.\n",i,n) ;
                if (sum == 1)
                    printf ("Case #%d: %d is a Happy number.\n",i,n ) ;
                break;
            }
        }
    }
    return 0;
}
