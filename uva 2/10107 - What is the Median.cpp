#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,ar[10000],i;
    while(cin >> a){
        ar[i++] = a;
        sort(ar,ar+i);
        if(i%2 == 0)cout << (ar[i/2-1]+ar[i/2])/2 << endl;
        else cout << ar[i/2] << endl;
    }
    return 0;
}
