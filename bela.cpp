#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases, score = 0;
    char suit;
    unordered_map<char, int> mp;
    mp.insert(make_pair('A', 0));
    mp.insert(make_pair('K', 1));
    mp.insert(make_pair('Q', 2));
    mp.insert(make_pair('J', 3));
    mp.insert(make_pair('T', 4));
    mp.insert(make_pair('9', 5));
    mp.insert(make_pair('8', 6));
    mp.insert(make_pair('7', 7));
    int dom[8] = {11, 4, 3, 20, 10, 14, 0, 0};
    int notDom[8] = {11, 4, 3, 2, 10, 0, 0, 0};
    cin >> cases >> suit;
    cases = cases * 4;
    while(cases--)
    {
        char k, s;
        cin >> k >> s;
        if(s == suit)
            score += dom[mp.find(k) -> second];
        else
            score += notDom[mp.find(k) -> second];
    }
    cout << score << endl;
    return 0;
}