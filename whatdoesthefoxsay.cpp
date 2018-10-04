#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cases;
    cin >> cases;
    cin.get();
    while(cases--)
    {
        unordered_set<string> sounds;
        string sound, line, line2;
        string animal, goes, s;

        getline(cin, line);

        while(true)
        {
            getline(cin, line2);
            istringstream iss2(line2);
            iss2 >> animal >> goes >> s;

            if(line2 == "what does the fox say?")
                break;
            else
                sounds.insert(s);
        }


        istringstream iss(line);
        while(getline(iss, sound, ' '))
        {
            if(sounds.find(sound) == sounds.end())
                cout << sound << ' ';
        }
        cout << endl;
    }
    return 0;
}