#include <iostream>

using namespace std;

int main()
{
    int x = 0, y = 0;
    string output;
    freopen("test.txt", "r", stdin);
    while(cin >> x >> y)
    {
        if(x == 0 && y == 0)
            break;

        if(x + y == 13)
            output = "Never speak again.";
        else if(x ==  y)
            output = "Undecided.";
        else if(x < y)
            output = "Left beehind.";
        else
            output = "To the convention.";

        cout << output << endl;
    }
    return 0;
}