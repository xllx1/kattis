#include <bits/stdc++.h>
using namespace std;

#define INF -1

typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    int n, m;
    cin >> n >> m; //n*m grid

    vector<vi> AM;
    AM.assign(n, vi());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            int l = temp - '0';
            AM[i].push_back(l);
        }
    }
    int r = 0, c = 0;

    int dist[n][m];
    //initialise distance
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;

    dist[r][c] = 0;
    queue<ii> q;
    q.push({r, c});

    while (!q.empty()) { // run BFS
        ii f = q.front();
        q.pop();
        r = f.first; c = f.second;
        int step = AM[r][c];
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir] * step, nc = c + dc[dir] * step;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (dist[nr][nc] == INF)
            {
                dist[nr][nc] = dist[r][c]+1;
                q.push({nr, nc});
            }
        }
    }

     for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++)
          cout << dist[i][j];
       cout << endl;
     }

    cout << dist[n - 1][m - 1] << endl;
    return 0;
}