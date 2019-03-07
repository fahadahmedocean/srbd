
#include <bits/stdc++.h>
using namespace std;
int M,N;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
         cin>>N>>M;
        int mat[N][M], data;
        int process[N][M];

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                cin>>data;
                mat[i][j]=data;
                process[i][j]=data;
            }
        }

        int happyrow[N];
        int cnt=0;

        for(int i=1; i<=N; i++)
        {
            //kontate age mrbo
            int noofzeros[N];
            for(int pp=1; pp<=N; pp++)
            {
                int zero=0;
                for(int ll=1; ll<=M; ll++)
                {
                    if(process[ll][pp]==0)
                        zero++;

                }
                noofzeros[pp]=zero;
            }

            int big=-1;
            int pos;
            int m;
            for( m=1; m<=M; m++)
            {
                if(big<noofzeros[m])
                {
                    big=noofzeros[m];
                    noofzeros[m]=0;
                    pos=m;
                }
            }

            //lezer marchi pos
            for(int j=1; j<=M; j++)
            {
                if(mat[j][pos]==1)
                    process[j][pos]=0;
                else
                    process[j][pos]=1;

                cnt=0;
                for(int k=1; k<=N; k++)
                {
                    int flug=0;
                    for(int p=1; p<=M; p++)
                    {
                        if( process[k][p]==0)
                        {
                            flug=2;
                            break;
                        }
                    }
                    if(flug==0)
                        cnt++;
                }

                happyrow[i]=cnt;
            }


        }

        cout<<"happyrow"<<"  \n";
        for(int k=1; k<=N; k++)
            cout<<happyrow[k]<<"  ";

        cout<<"\nnumber of alteration :  ";
        int alter;
        cin>>alter;

           cout<<"happy row number: "<<happyrow[alter]<<endl;;
    }
    return 0;
}

/*
3
4
4
0 0 0 0
0 1 1 0
0 1 0 0
0 1 0 0
3
4
4
0 1 0 0
0 1 1 0
0 1 0 0
0 1 0 1
4

*/
