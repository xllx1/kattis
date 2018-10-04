#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int cases;
    while(cin >> cases && cases != 0)
    {
        string name, line, food;
        map<string, string> mapNameFood;
        map<string, string> mapFoodName;
        for(int i = 0; i < cases; i++)
        {
            cin >> name;
            getline(cin, line, '\n');
            mapNameFood.insert(make_pair(name, line));
        }
        for(auto &it : mapNameFood)
        {
            istringstream iss(it.second);
            name = it.first;
            while(iss >> food)
            {
                if(mapFoodName.find(food) == mapFoodName.end())
                {
                    mapFoodName.insert(make_pair(food, name));
                }
                else
                    mapFoodName[food] += " " + name;
            }
        }

        for(auto &it2 : mapFoodName)
            cout << it2.first << " " << it2.second << endl;
        cout << endl;
    }
    return 0;
}
/*steven code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) { // read n and see if it is 0? (stop if it is)
        cin.get(); // consume new line after n
        unordered_map<string, set<string>> magic_ds;
        for (int i = 0; i < n; i++) {
            string line, name, order;
            getline(cin, line);
            istringstream iss(line);
            iss >> name;
            while (iss >> order)
                magic_ds[order].insert(name);
            // cout << name << " orders " << order << endl;
        }
        for (auto &order_names : magic_ds) {
            cout << order_names.first;
            for (auto &name : order_names.second)
                cout << " " << name;
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
*/