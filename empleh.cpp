#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string start = "+---+---+---+---+---+---+---+---+";
    string odd = "|...|:::|...|:::|...|:::|...|:::|";
    string even = "|:::|...|:::|...|:::|...|:::|...|";
    string grid[17] = {};
    for(int i = 0; i < 17; i++) //initialising grid
    {
        if(i % 2 == 0)//even all start lines
            grid[i] = start;
        else if(i == 1 || i == 5 || i == 9 || i == 13)
            grid[i] = odd;
        else if(i == 3 || i == 7 || i == 11 || i == 15)
            grid[i] = even;
    }

    string temp, wh, bl, dummy, l, o;
    vector<string> white;
    vector<string> black;
    int x = 0, y = 0;
    getline(cin, l);
    stringstream ss0(l);
    while(getline(ss0, l, ' '))
    {
        x++;
        wh = l;
    }
    if(x == 1)
        wh = "";

    getline(cin, o);
    stringstream sso(o);
    while(getline(sso, o, ' '))
    {
        y++;
        bl = o;
    }
    if(y == 1)
        bl = "";
    if(!wh.empty())
    {
        stringstream ss(wh);
        while(getline(ss, temp, ','))
            white.push_back(temp);
    }

    if(!bl.empty())
    {
        stringstream ss1(bl);
        while(getline(ss1, temp, ','))
        {
            if(temp.size() == 3)
                temp[0] = tolower(temp[0]);
            black.push_back(temp);
        }
    }

//    for(auto &it : white)
//        cout << it << endl;
//    for(auto &it1 : black)
//        cout << it1 << endl;
    if(!white.empty())
    {
        for(auto &it : white)
        {
            int r = 0, c = 0;
            char type;
            if(it.size() == 3)
            {
                type = it[0];
                c = 2 + (it[1] - 'a') * 4; //a,b,c
                r = (8 - it[2] + '1') * 2 - 1; //1,2,3
//            cout << type << "::" << c << "::" << r << endl;
                grid[r][c] = type;
            }
            else
            {
                type = 'P';
                c = 2 + (it[0] - 'a') * 4;
                r = (8 - it[1] + '1') * 2 - 1;
//            cout << type << "::" << c << "::" << r << endl;
                grid[r][c] = type;
            }
        }
    }
    if(!black.empty())
    {

        for(auto &it : black)
        {
            int r = 0, c = 0;
            char type;
            if(it.size() == 3)
            {
                type = it[0];
                c = 2 + (it[1] - 'a') * 4; //a,b,c
                r = (8 - it[2] + '1') * 2 - 1; //1,2,3
//            cout << type << "::" << c << "::" << r << endl;
                grid[r][c] = type;
            }
            else
            {
                type = 'p';
                c = 2 + (it[0] - 'a') * 4;
                r = (8 - it[1] + '1') * 2 - 1;
//            cout << type << "::" << c << "::" << r << endl;
                grid[r][c] = type;
            }
        }
    }

    for(int i = 0; i < 17; i++)
        cout << grid[i] << endl;

    return 0;
}