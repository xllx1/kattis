#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, below0 = 0;
    cin >> n;
    while(n--)
    {
        int temp;
        cin >> temp;
        if(temp < 0)
            below0++;
    }

    cout << below0 << endl;
    return 0;
}