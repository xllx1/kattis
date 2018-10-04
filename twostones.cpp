#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n % 2 == 0) //even
        cout << "Bob";
    else
        cout << "Alice";
    return 0;
}