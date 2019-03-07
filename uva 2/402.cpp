#include <iostream>
#include <vector>
using namespace std;
void killSomeone(vector<int> &vec, int &n, int &num)
{
    int t = n - 1;
    while (vec.size() > num and t < vec.size())
    {
        vec.erase(vec.begin() + t);
        t += n - 1;
    }
}
int main()
{
    int N; // N people
    int testCase = 1;
    while (cin >> N)
    {
        int luckyMan = 0;
        cin >> luckyMan;
        vector<int> point(20);
        vector<int> man(N);
        for (int i = 0; i < N; i++)
            man[i] = i + 1;

        for (int i = 0; i < 20; i++)
        {
            cin >> point[i];
        }

        for (int i = 0; i < 20 and man.size() > luckyMan; i++)
        {
            killSomeone(man, point[i], luckyMan);
        }

        cout << "Selection #" << testCase++ << endl;
        for (int i = 0; i < man.size(); i++)
        {
            cout << man[i];
            if (i == man.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
