#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;

int floodfill(int m, int n, int i, int j) {
    // If out of bounds
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }

    // If already used
    if(visited[i][j]) {
        return 0;
    }

    // Use this point
    visited[i][j] = true;

    // Use all adjacent points
    floodfill(m, n, i, j+1);
    floodfill(m, n, i, j-1);
    floodfill(m, n, i+1, j);
    floodfill(m, n, i-1, j);

    return 1;
}

int main() {
    freopen("test.txt", "r", stdin);
    int m, n;
    int count = 1;
    while(cin >> m && cin >> n) {

        for(int i = 0; i < m; i++) {
            vector<char> temp;
            visited.assign(m, vector<bool>());
            for(int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if(c == '#')
                    visited[i].push_back(true);
                else
                    visited[i].push_back(false);
                temp.push_back(c);
            }
            grid.push_back(temp);
        }

        int stars = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                stars += floodfill(m, n, i, j);
            }
        }

        cout << "Case " << count << ": " << stars << endl;
        count++;
    }
}