#include <iostream>
#include <set>

using namespace std;

int main()
{
    int cases;
    while(cin >> cases)
    {
        for(int i = 0; i < cases; i++)
        {
            set<int> sets;
            int guests, code;
            cin >> guests;
            for(int j = 0; j < guests; j++)
            {
                cin >> code;
                if(sets.empty())
                    sets.insert(code);
                else
                {
                    auto it = sets.find(code);
                    if(it == sets.end())
                        sets.insert(code);
                    else
                        sets.erase(code);
                }
            }
            cout << "Case #" << i + 1 << ": " << *(sets.begin()) << endl;
        }
    }
    return 0;
}