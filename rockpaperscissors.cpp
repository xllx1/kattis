#include <bits/stdc++.h>

using namespace std;

vector<int> playerWins(120, 0); //max 100 players
vector<int> playerLose(120, 0); //max 100 players

int check(int p1, int i1,int p2, int i2)
{
    if(abs(i1 - i2) == 1)
    {
        if(i1 > i2)
        {
            playerWins[p1]++;
            playerLose[p2]++;
        }
        else if(i1 < i2)
        {
            playerWins[p2]++;
            playerLose[p1]++;
        }
    }
    else if(abs(i1 - i2) == 2)
    {
        if(i1 > i2)
        {
            playerWins[p2]++;
            playerLose[p1]++;
        }
        else if(i1 < i2)
        {
            playerWins[p1]++;
            playerLose[p2]++;
        }
    }
}
int main()
{
//    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n = 0, k = 0, p1 = 0, p2 = 0, i1 = 0, i2 = 0;
    unordered_map<string, int> rules;
    rules["rock"] = 1;
    rules["paper"] = 2;
    rules["scissors"] = 3;

    string m1, m2;
    while(cin >> n, n != 0)
    {
        fill(playerWins.begin(), playerWins.end(), 0);
        fill(playerLose.begin(), playerLose.end(), 0);
        cin >> k;
        k = k * n * (n - 1) / 2;
        for(int i = 0; i < k; i++)
        {
            cin >> p1 >> m1 >> p2 >> m2;
            i1 = rules[m1];
            i2 = rules[m2];
            check(p1, i1, p2, i2);
        }
        for(int s = 1; s <= n; s++)
        {
            if(playerWins[s] == 0 && playerLose[s] == 0)
                cout << '-' << endl;
            else
            {
                float output = 0;
                output = (float) playerWins[s] / (playerWins[s] + playerLose[s]);
                cout.precision(3);
                cout << fixed;
                cout << output << endl;
            }
        }
        cout << endl;

    }

    return 0;
}