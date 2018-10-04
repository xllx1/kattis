#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("2.txt", "r", stdin);
    char suit;
    int xy;
    unordered_set<int> p;
    unordered_set<int> k;
    unordered_set<int> h;
    unordered_set<int> t;
    bool flag = false;
    while(cin >> suit >> xy)
    {
        cout << xy << endl;
        if(suit == 'P')
        {
            if(p.find(xy) == p.end())
                p.insert(xy);
            else
                flag = true;
        }
        else if(suit == 'K')
        {
            if(k.find(xy) == k.end())
                k.insert(xy);
            else
                flag = true;
        }
        else if(suit == 'H')
        {
            if(h.find(xy) == h.end())
                h.insert(xy);
            else
                flag = true;
        }
        else if(suit == 'T')
        {
            if(t.find(xy) == t.end())
                t.insert(xy);
            else
                flag = true;
        }
    }
    if(flag)
        cout << "GRESKA" << endl;
    else
    {
        cout << 13 - p.size() << " ";
        cout << 13 - k.size() << " ";
        cout << 13 - h.size() << " ";
        cout << 13 - t.size() << endl;
    }
    return 0;
}