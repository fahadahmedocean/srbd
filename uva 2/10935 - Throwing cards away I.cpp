#include<bits/stdc++.h>
using namespace std;
# define MAX 100

int intArray[MAX];
int frnt = 0;
int rear = -1;
int itemCount = 0;

int frontElement()
{
    return intArray[frnt];
}

bool isEmpty()
{
    return itemCount == 0;
}

bool isFull()
{
    return itemCount == MAX;
}

int sizee()
{
    return itemCount;
}

void insrt(int data)
{

    if(!isFull())
    {

        if(rear == MAX-1)
        {
            rear = -1;
        }

        intArray[++rear] = data;
        itemCount++;
    }
}

int removeData()
{
    int data = intArray[frnt++];

    if(frnt == MAX)
    {
        frnt = 0;
    }

    itemCount--;
    return data;
}


void initial()
{
    intArray[MAX]= {};
    frnt=0;
    rear=-1;
    itemCount=0;


}



int main()
{
    int n;

    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        initial();

        for(int i=1; i<=n; i++)
        {
            insrt(i);
        }
        int j =0;


        cout<<"Discarded cards:";
        while(sizee()>1)
        {
            cout<<' '<<frontElement();
            removeData();

            int a = frontElement();
            removeData();

            if(!isEmpty())
                cout<<',';
            insrt(a);
        }
        cout<<endl;
        cout<<"Remaining card: "<<frontElement()<<endl;
        removeData();

    }
    return 0;
}
