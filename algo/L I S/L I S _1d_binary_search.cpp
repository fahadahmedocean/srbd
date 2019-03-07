//lis number is correct but sequence is not correct
#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[],int start,int endp,int key)
{
    while(endp-start > 1)
    {
        int mid = start +(endp - start)/2;
        if(a[mid]>=key)
            endp = mid;
        else
            start = mid;
    }
    return endp;
}

int LIS(int input[], int sz)
{
    if(!sz)
        return 0;
    int a[sz];

   //  initialize
    for(int k=0; k<=sz; k++)
        a[k]=-333;


    int length=1;

    a[0] = input[0];

    for(int i=1; i<sz; i++)
    {
        if(input[i]< a[0])

            a[0]=input[i];

        else if(input[i]>a[length-1])

            a[length++]=input[i];

        else
        {
            int pos=bin_search(a,-1,length-1,input[i]);
            //cout<<"pos : "<<pos<<endl;
            a[ pos ]= input[i];
        }

    }
    int k=0;
    while(k!=10)
    {
        cout<<a[k]<<" ";
        k++;
    }
    cout<<endl;
    return length;
}

int main()
{
    //int a[]= {-5,-8,4,0,2,10,6,11,1,9,5,13,16,7,25};
    int a[]= {-1,4,0,1,11,12,13,3,10};
    int sz =sizeof(a)/sizeof(a[0]);

    printf("Longest Increasing Sub-sequence is = %d",LIS(a,sz));
    //return 0;
}
