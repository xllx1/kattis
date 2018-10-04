#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int P;
    cin >> P;
    while(P--)
    {
        int K, p, q;
        char dummy;
        cin >> K >> p >> dummy >> q;
        stack<char> path;
        while(p + q > 2)
        {
            if(p < q)
            {
                path.push('L');
                 q -= p;
            }
            else
            {
                path.push('R');
                p -= q;
            }
        }
        int ans = 1;
        while(!path.empty())
        {
            char top = path.top();
            path.pop();
            if(top == 'R')
                ans = ans * 2 + 1;
            else if(top == 'L')
                ans = ans * 2;
        }
        cout << K << " " << ans << endl;
    }
    return 0;
}