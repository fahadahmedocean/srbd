#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int maxx = 26;
long long int fact[21];


void Factorials()
{
    fact[0] = 1;
    for (int i = 1; i <20; i++)
        fact[i] = fact[i - 1] * i;
}


void nPermute(char str[], int n)
{
    Factorials();
    int len = strlen(str);

    int freq[maxx] = { 0 };
    char out[maxx];

    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;

    int sum = 0;
    int k = 0;

    while (sum != n)
    {

        sum = 0;
        for (int i = 0; i < maxx; i++)
        {
            if (freq[i] == 0)
                continue;
            freq[i]--;

            int xsum = fact[len - 1 - k];
            for (int j = 0; j < maxx; j++)
                xsum /= fact[freq[j]];

            sum += xsum;

            if (sum >= n)
            {
                out[k++] = i + 'a';
                n -= (sum - xsum);
                break;
            }

            if (sum < n)
                freq[i]++;
        }
    }


    for (int i=maxx-1; k < len && i >= 0; i--)
        if (freq[i])
        {
            out[k++] = i + 'a';
            freq[i++]--;
        }

    out[k] = '\0';
    cout << out;
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n ;
        char str[21] ;
        cin>>str;
        cin>>nth;
        nPermute(str, nth);
    }
    return 0;
}
