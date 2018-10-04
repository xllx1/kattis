#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s1, s2 = "ss";
    cin >> s1;

    if (s1.find(s2) != string::npos)
        cout << "hiss" << endl;
    else
        cout << "no hiss" << endl;
    return 0;
}