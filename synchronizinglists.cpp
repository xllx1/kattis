#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    vector<int> first;
    vector<int> firstA;
    vector<int> last;
    vector<int> lastO;
    while(cin >> n && n != 0)
    {
        for(int i = 0; i < n*2; i++)
        {
            cin >> k;
            if(i < n)
            {
                first.push_back(k);
                firstA.push_back(k);
            }
            else
                last.push_back(k);
        }

        sort(first.begin(), first.end());
        sort(last.begin(), last.end());
        first.insert(first.end(), last.begin(), last.end());

        for(int i = 0; i < n; i++)
        {
            auto it = find(first.begin(), first.end(), firstA[i]);
            lastO.push_back(*(it + n));
        }

        for(auto k:lastO)
            cout << k << endl;

        cout << endl;
        first = vector<int>();
        firstA = vector<int>();
        last = vector<int>();
        lastO = vector<int>();
    }

    return 0;
}