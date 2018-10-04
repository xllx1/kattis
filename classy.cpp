#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    int cases;
    cin >> cases;
    cin.get();
    while(cases--)
    {
        multiset<pair<string, string>> msss;
        int n;
        cin >> n;
        while(n--)
        {
            string name, classes, cl, dummy;
            cin >> name >> classes >> dummy;
            name.pop_back();
//            cout << name << endl;
            string newclass;
//            cout << name << "::" << classes << "::" ;
            stringstream ss1(classes);
            bool isUpper = false, isMiddle = false, isLower = false;
            while (getline(ss1, cl, '-'))
            {
                if(cl == "upper")
                {
                    isUpper = true;
                    newclass = "A" + newclass;
                }
                else if(cl == "middle")
                {
                    isMiddle = true;
                    newclass = "B" + newclass;
                }
                else if(cl == "lower")
                {
                    isLower = true;
                    newclass = "C" + newclass;
                }
            }
            string k;
            for(int i = 0; i < (10 - newclass.size()); i++)
            {
                k += "B";
            }
            newclass = newclass + k;

//            cout << newclass << endl;
            msss.insert(make_pair(newclass, name));
        }
        for(auto &it : msss)
            cout << it.second << endl;
        cout << "==============================\n";
    }
    return 0;
}