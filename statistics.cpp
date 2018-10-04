#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string line;
    int cases = 1;
    while(getline(cin, line, '\n'))
    {
        int max = -1000001, min = 1000001, num, n;
        istringstream iss(line);
        iss >> n;
        while(iss >> num)
        {
            if(num > max)
                max = num;

            if(num < min)
                min = num;
        }
        cout << "Case " << cases << ": " << min << " " << max << " " << max - min << endl;
        cases++;
    }
    return 0;
}