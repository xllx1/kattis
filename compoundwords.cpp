#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string words, line;
    vector<string> w;
    set<string> setOfWords;
    int i = 0;

    while(getline(cin, line, '\n'))
    {
        stringstream ss(line);
        while(ss >> words)
            w.push_back(words);
    }

    while(i < w.size())
    {
        for (int j = 0; j < w.size(); j++) {
            if (j != i)
                setOfWords.insert(w[i] + w[j]);
        }
        i++;
    }
    for(auto &it : setOfWords)
        cout << it << endl;
    return 0;
}
