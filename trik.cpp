#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int pos[] = {0, 1}, m=0;
    char swap;
    while(cin >> swap)
    {
        m = pos[0] * 2 + pos[1];
        switch(swap)
        {
            case 'A':
                if(m == 1 || m == 2)
                {
                    pos[0] = !pos[0];
                    pos[1] = !pos[1];
                }
                break;
            case 'B':
                if(m == 2 || m == 3)
                    pos[1] = !pos[1];
                break;
            case 'C':
                if(m == 1 || m == 3)
                    pos[0] = !pos[0];
                break;
            default:
                break;
        }
    }
    int output = pos[0] * 2 + pos[1];
    cout << output << endl;

    return 0;
}