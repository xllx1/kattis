#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, E, villager, songNum = 0;
    unordered_set<int> kSet[110];
    cin >> N;
    cin >> E;
    while(E--)
    {
        int k;
        cin >> k;
        vector<int> hereTonight;
        bool bard = false;
        while(k--)
        {
            cin >> villager;
            if(villager == 1)
                bard = true;
            hereTonight.push_back(villager);
        }

        if(bard)
        {
            songNum++;
            for(auto &it : hereTonight)
                kSet[it].insert(songNum);
        }
        else
        {
            for(int i = 1; i <= songNum; i++)
            {
                for(auto &it : hereTonight)
                    if(kSet[it].find(i) != kSet[it].end())
                        for(auto &w : hereTonight)
                            kSet[w].insert(i);
            }
        }
    }

    for(int j = 1; j <= N; j++)
        if((int)kSet[j].size() == songNum)
            cout << j << endl;
    return 0;
}