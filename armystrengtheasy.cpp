#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("test.txt", "r", stdin);
    int cases;
    cin >> cases;
    cin.get();
    for(int i = 0; i < cases; i++)
    {
        int G, M, strength;
        string line;
        set<int> sG;
        set<int> sM;

        cin.get();
        cin >> G >> M;
        cin.get();
        getline(cin, line, '\n');
//        cout << line << endl;
        stringstream ss(line);
        while(ss >> strength)
            sG.insert(strength);

        getline(cin, line, '\n');
//        cout << line << endl;
        stringstream ss2(line);
        while(ss2 >> strength)
            sM.insert(strength);

//        cout << "G: ";
//        for(auto &it : sG)
//            cout << it  << "::" ;
//
//        cout << endl;
//        cout << "M: ";
//        for(auto &it : sM)
//            cout << it  << "::" ;

        while(!sG.empty() && !sM.empty())
        {
            if(*sG.begin() < *sM.begin())
                sG.erase(sG.begin());
            else
                sM.erase(sM.begin());
        }

        if(sG.empty() && sM.empty())
            cout << "uncertain" << endl;
        else if(sG.empty())
           cout << "MechaGodzilla" << endl;
        else if(sM.empty())
            cout << "Godzilla" << endl;
    }
    return 0;
}