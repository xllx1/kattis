#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> vec;
    vector<int> values;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vec[i].resize(k);
        for(auto& j : vec[i]) {
            cin >> j;
            j--;
        }
        cin >> values[i];
    }
    return 0;
}