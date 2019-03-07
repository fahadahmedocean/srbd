#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,a,arr[102] = {0},mx = 0,index = -1,ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a]++;
        if(arr[a] > mx)
        {
            mx = arr[a];
            index = a;
        }
    }
    for(int i = 1; i <= 100; i++)
        if(i != index)
            ans+=arr[i];
    cout << ans << endl;
    return 0;
}
