#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vectorOfInt;
vector<vectorOfInt> al;
vectorOfInt visited;

void dfs(int node)
{
    //mark current node as visited--1
    visited[node] = 1;
    //visit its neighbours
    for(auto &it : al[node])
        if(!visited[it]) //if not visited, call dfs(it)
            dfs(it);
}

void bfs(int node)
{
    list<int> queue;

    // Mark the current node as visited and enqueue
    visited[node] = 1;
    queue.push_back(node);

    while(!queue.empty())
    {
        node = queue.front();
        queue.pop_front();

        for (auto &it : al[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                queue.push_back(it);
            }
        }
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    int N, M;
    cin >> N >> M;

    al.assign(N, vectorOfInt());
    while(M--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.assign(N, 0);
    bfs(0);

    bool notConnected = false;
    for(int i = 0; i < visited.size(); i++)
        if(!visited[i]) // 0 means not connected
        {
            cout << i + 1 << endl;
            notConnected = true;
        }

    if(!notConnected)
        cout << "Connected" << endl;

    return 0;
}