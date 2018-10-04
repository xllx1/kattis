#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int M, P, L, egg, rateR, rateS, week, kM;
    string line;
    while(getline(cin, line, '\n'))
    {
        stringstream ss(line);
        ss >> M >> P >> L >> egg >> rateR >> rateS >> week;
        for(int i = 0; i < week; i++)
        {
            kM = M;
            M = P / rateS;
            P = L / rateR;
            L = kM * egg;
        }
        cout << M << endl;
    }
    return 0;
}