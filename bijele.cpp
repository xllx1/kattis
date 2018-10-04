#include <bits/stdc++.h>

using namespace std;

int main()
{
    int actual[6] = {0}, expected[6] = {1, 1, 2, 2, 2, 8}, output[6] = {0};
    for(int i = 0; i < 6; i++)
    {
        cin >> actual[i];
        output[i] = expected[i] - actual[i];
    }
    for(auto j : output)
        cout << j << " ";
    return 0;
}