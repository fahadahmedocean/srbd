#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void coprime(int a, int b)
{
    if ( gcd(a, b) == 1)
        cout << "Co-Prime" << endl;
    else
        cout << "Not Co-Prime" << endl;
}


int main()
{
    int a, b ;
    cout<< "input a and b \n";
    cin>>a>>b;
    coprime(a, b);
    return 0;
}
