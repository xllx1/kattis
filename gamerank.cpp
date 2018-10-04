#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int rule[] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
    int cons = 0;
    pair<int, int> rank = {25, 0};
    char status;

    while(cin >> status)
    {
        if(rank.first < 1)
            continue;
        if(status == 'W')
        {
            cons++;
            if(cons > 2 && rank.first > 5)
            {
                if(rank.second + 2 > rule[rank.first])
                {
                    rank.second = rank.second + 2 - rule[rank.first];
                    rank.first--;
                }
                else
                    rank.second += 2;
            }
            else
            {
                if(rank.second + 1 > rule[rank.first])
                {
                    rank.first--;
                    rank.second = 1;
                }
                else
                    rank.second++;
            }
        }
        else if(status == 'L')
        {
            cons = 0;
            if(rank.first < 21 && rank != make_pair(20, 0))
            {
                if(rank.second == 0)
                {
                    rank.first = rank.first + 1;
                    rank.second = rule[rank.first] - 1;
                }
                else
                    rank.second--;
            }
        }
        //cout << rank.first << "::" << rank.second << endl;
    }

    //cout << rank.first << "::" << rank.second << endl;
    if(rank.first < 1)
        cout << "Legend" << endl;
    else
        cout << rank.first << endl;

    return 0;
}