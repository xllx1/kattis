#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    char k;
    deque<char> q;
    unordered_map<char, char> umcc;
    umcc['R'] = 'S';
    umcc['B'] = 'K';
    umcc['L'] = 'H';

    while(cin >> k)
    {
        // cout << "cin: " << k << endl;
        q.push_back(k);
    }
    while(!q.empty())
    {
        if(q.size() >= 3 && q[0] != q[1] && q[1] != q[2] && q[2] != q[0])
        {
            cout << 'C';
            q.pop_front();
            q.pop_front();
            q.pop_front();
        }
        else
        {
            cout << umcc[q.front()];
            q.pop_front();
        }
    }
    return 0;
}