#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N = 0, W = 0, H = 0;
    double D = 0;
    cin >> N >> W >> H;
    D = pow(pow(W, 2) + pow(H, 2), 0.5);
    while(N--)
    {
        int length;
        cin >> length;
        if(length <= D)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
    return 0;
}