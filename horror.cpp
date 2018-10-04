#include <bits/stdc++.h>

using namespace std;
vector<int> D;
vector<vector<int>> AL;

void dfs(int node)
{
    for(auto &it : AL[node])
        if(D[node] + 1 < D[it])
        {
            D[it] = D[node] + 1;
            dfs(it);
        }
}

void bfs(int node)
{
    queue<int> qu;
    D[node] = 0; //to itself 0
    qu.push(node);
    while(!qu.empty())
    {
        int value = qu.front();
        qu.pop();
        for(auto &it : AL[value])
        {
            if(D[value] + 1 < D[it])
            {
                D[it] = D[value] + 1;
                qu.push(it);
            }
        }
    }
}
int main()
{
//    freopen("test.txt", "r", stdin);
    int N, H, L;//N: number of movies, H:number of movies on horror list, L similarity in database
    cin >> N >> H >> L;
    vector<int> HL;
    AL.assign(N, vector<int>());
    D.assign(N, 1e9);
    for(int i = 0; i < H; i++)
    {
        int dummy;
        cin >> dummy;
        HL.push_back(dummy);
    }

    while(L--)
    {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    for(auto &it : HL)
    {
        bfs(it);

        //D[it] = 0;
        //dfs(it);
    }

    int ans = 0;
    for(int m = 0; m < D.size(); m++)
        if(D[m] > D[ans])
            ans = m;

    cout << ans << endl;

    return 0;
}