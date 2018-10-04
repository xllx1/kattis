#include <bits/stdc++.h>

using namespace std;
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
string findMatch(char startChar, char endChar, int start, int end)
{
    //A:65
    unordered_set<pair<int, int>, pair_hash> sS;
    unordered_set<pair<int, int>, pair_hash> sE;
    int sC, eC;
    sC = startChar - 64;
    eC = endChar - 64;
    for(int i = sC - 1; i > 0 ; i--)
    {
        if(start - (sC - i) > 0)
            sS.insert(make_pair(i, (start - (sC - i))));
        if(start + (sC - i) < 9)
            sS.insert(make_pair(i, (start + (sC - i))));
    }
    for(int j = sC + 1; j < 9; j++)
    {
        if(start + (j - sC) < 9)
            sS.insert(make_pair(j, (start + (j - sC))));
        if(start - (j - sC) > 0)
            sS.insert(make_pair(j, (start - (j - sC))));
    }

    for(int i = eC - 1; i > 0 ; i--)
    {
        if(end - (eC - i) > 0)
            sE.insert(make_pair(i, (end - (eC - i))));
        if(end + (eC - i) < 9)
            sE.insert(make_pair(i, (end + (eC - i))));
    }
    for(int j = eC + 1; j < 9; j++)
    {
        if(end + (j - eC) < 9)
            sE.insert(make_pair(j, (end + (j - eC))));
        if(end - (j - eC) > 0)
            sE.insert(make_pair(j, (end - (j - eC))));
    }

    // for(auto &it : sS)
    // cout << "sS: " << it.first << "||" << it.second << endl;
    // cout << "==============================================" << endl;
    // for(auto &it : sE)
    // cout << "sE: " << it.first << "||" << it.second << endl;

    for(auto &it : sS)
        if(sE.find(it) != sE.end())
        {
            string dummy;
            dummy = (char) it.first + 64;
            string output = dummy + " " + to_string(it.second);
            return output;
        }
    return "no";
}

int main()
{
    freopen("2.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cases;
    cin >> cases;
    while(cases--)
    {
        char startChar, endChar;
        int start, end;
        cin >> startChar >> start >> endChar >> end;
        //four cases: 0, 1, 2 or impossible
        if(startChar == endChar && start == end)
            cout << "0 " << startChar << " " << start << endl;
        else if(abs(startChar - endChar) == abs(start - end))
            cout << "1 " << startChar << " " << start << " " << endChar << " " << end << endl;
        else
        {
            string output = findMatch(startChar, endChar, start,end);
            if(output != "no")
                cout << "2 " << startChar << " " << start << " " << output << " " << endChar << " " << end << endl;
            else
                cout << "Impossible" << endl;
        }

    }

    return 0;
}