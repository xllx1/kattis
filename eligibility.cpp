#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int cases, sYear, bYear, courses;
    string line, name, secondary, born, output;
    while(cin >> cases)
    {
        for(int i = 0; i < cases; i++)
        {
            cin >> name >> secondary >> born >> courses;
            istringstream (secondary.substr(0, 4)) >> sYear;
            istringstream (born.substr(0, 4)) >> bYear;

            if(sYear > 2009)
                output = "eligible";
            else if(bYear > 1990)
                output = "eligible";
            else if(courses > 40)
                output = "ineligible";
            else
                output = "coach petitions";

            cout << name << " " << output << endl;
        }
    }
    return 0;
}