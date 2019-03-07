#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAX_CHAR = 26;

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

    // Count frequencies of all
    // characters
    int freq[MAX_CHAR] = { 0 };
    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;

    // out string for output string
    char out[MAX_CHAR];

    // iterate till sum equals n
    int sum = 0;
    int k = 0;

    // We update both n and sum in this
    // loop.
    while (sum != n)
    {

        sum = 0;
        // check for characters present in freq[]
        for (int i = 0; i < MAX_CHAR; i++)
        {
            if (freq[i] == 0)
                continue;

            // Remove character
            freq[i]--;

            // calculate sum after fixing
            // a particuar char
            int xsum = fact[len - 1 - k];
            for (int j = 0; j < MAX_CHAR; j++)
                xsum /= fact[freq[j]];
            sum += xsum;

            // if sum > n fix that char as
            // present char and update sum
            // and required nth after fixing
            // char at that position
            if (sum >= n)
            {
                out[k++] = i + 'a';
                n -= (sum - xsum);
                break;
            }

            // if sum < n, add character back
            if (sum < n)
                freq[i]++;
        }
    }

    // if sum == n means this char will provide its
    // greatest permutation as nth permutation
    for (int i=MAX_CHAR-1; k < len && i >= 0; i--)
        if (freq[i])
        {
            out[k++] = i + 'a';
            freq[i++]--;
        }

    // append string termination
    // character and print result
    out[k] = '\0';
    cout << out;
}

// Driver program
int main()
{
    int n = 24;
    char str[] = "abcd";

    nPermute(str, n);
    return 0;
}
