#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, rA = 0, rB = 0;
    cin >> a >> b;

    while(a != 0)
    {
        rA = rA * 10 + a % 10;
        a /= 10;
    }
    while(b != 0)
    {
        rB = rB * 10 + b % 10;
        b /= 10;
    }

    cout << max(rA, rB) << endl;
    return 0;
}