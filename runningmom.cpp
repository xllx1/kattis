#include <bits/stdc++.h>

using namespace std;

unordered_map<string, set<string>> al;
unordered_map<string, int> visited;
bool flag = false;

void dfs(string ver)
{
    //not visited: 0; being explore: 1; fully explored: 2
    visited[ver] = 1;
    for(auto &it : al[ver])
    {
        if(visited[it] == 0)
            dfs(it);
        else if(visited[it] == 1)
            flag = true;
    }
    visited[ver] = 2;
}

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        string o, d;
        cin >> o >> d;
        al[o].insert(d);
        visited[o] = 0;
        visited[d] = 0;
    }

    string city;
    while(cin >> city)
    {
        flag = false;
        for(auto &it : visited)
            visited[it.first] = 0;
        dfs(city);
        cout << (flag ? "safe\n" : "trapped\n");
//        if(flag)
//            cout << city << " safe" << endl;
//        else
//            cout << city << " trapped" <<endl;
    }
    return 0;
}