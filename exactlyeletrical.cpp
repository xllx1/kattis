#include <iostream>

using namespace std;

int main()
{
    int aX, aY, bX, bY, difference = 0, t, diffX = 0, diffY = 0;

    while(cin >> aX >> aY >> bX >> bY >> t)
    {
        //difference = ((aX - bX) > (aY - bY))?(aY - bY):(aX - bX);
        diffX = abs(aX - bX);
        diffY = abs(aY - bY);

        difference = diffX + diffY;

        if(difference == 0)
            cout << 'Y' << endl;
        else if(difference % 2 == 0 && t >= (diffX + diffY) && t % 2 == 0) //even
            cout << 'Y' << endl;
        else if(difference % 2 != 0 && t >= (diffX + diffY) && t % 2 != 0)
            cout << 'Y' << endl;
        else
            cout << 'N' << endl;
    }
    return 0;
}