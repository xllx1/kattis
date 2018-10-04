#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; // shortcut notation

vector<vi> AL; // Adjacency List, pre   ferably put as global variable as it will be accessed by the recursive DFS routine
vi visited; // global variable for the same reason

void dfs(int u) { // the most basic standard DFS implementation, easy to memorize
    visited[u] = 1;
    for (auto &v : AL[u])
        if (!visited[v])
            dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M; // 1 <= N, M <= 200000, rather big, but fine
    cin >> N >> M; // N vertices and M edges

    // STORE the graph
    AL.assign(N, vi()); // N rows, indexed [0..N-1]
    for (int i = 0; i < M; i++) { // O(M)
        int a, b;
        cin >> a >> b; a--; b--; // convert to 0-based indexing (otherwise you need N+1 rows in your Adjacency List)
        AL[a].push_back(b); // O(1)
        AL[b].push_back(a); // bi-directional
    }

    // EXPLORE the graph
    visited.assign(N, 0); // O(N)
    dfs(0); // O(N+M)

    bool disconnected = false;
    // LAST PART START: PRINT the required answers (houses that are not connected to house 1) and adjust disconnected boolean flag accordingly
    for(int i = 0; i < visited.size(); i++)
        if(visited[i] == 0) {cout << i+1 << endl; disconnected = true;}
    // LAST PART END
    if (!disconnected)
        cout << "Connected\n";

    return 0;
}
