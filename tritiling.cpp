#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, plus = 2;
    int f[31] = {0};
    f[0] = 1; //f(1) = 1
    f[2] = 3; //f(2) = 3

    while(cin >> n, n != -1)
    {
        while(n - plus >= 2) //keep looping until n - 2 = plus
        {
            for(int j = plus; j >=0; j -= 2)
                if(j == plus)
                    f[plus + 2] += 3 * f[j];
                else
                    f[plus + 2] += 2 * f[j];
            plus += 2;
        }

        cout << f[n] << endl;
//        for(int i = 0; i < 30; i++)
//            cout << i << "||" << f[i] << endl;
    }

    return 0;
}