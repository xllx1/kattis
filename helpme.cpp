#include <bits/stdc++.h>

using namespace std;

string order = "KQRBN";
bool Comp(string lhs, string rhs)
{
    if(lhs[0] != rhs[0])
    {
        int lhs_val = order.find(lhs[0]);
        int rhs_val = order.find(rhs[0]);

        if (lhs_val != rhs_val)
            return lhs_val < rhs_val;
    }
    else if(lhs[2] != rhs[2])
        return lhs[2] < rhs[2];
    else
        return lhs[1] < rhs[1];
}
bool Comp1(string lhs, string rhs)
{
    if(lhs[0] != rhs[0])
    {
        int lhs_val = order.find(lhs[0]);
        int rhs_val = order.find(rhs[0]);

        if (lhs_val != rhs_val)
            return lhs_val < rhs_val;
    }
    else if(lhs[2] != rhs[2])
        return lhs[2] > rhs[2];
    else
        return lhs[1] < rhs[1];
}

bool wayToSort(string lhs, string rhs)
{
    if(lhs[1] != rhs[1])
        return lhs[1] < rhs[1];
    else
        return lhs[0] < rhs[0];
}
bool wayToSort1(string lhs, string rhs)
{
    if(lhs[1] != rhs[1])
        return lhs[1] > rhs[1];
    else
        return lhs[0] < rhs[0];
}
string convert(string temp, int count, int i)
{
    string dummy;
    dummy = (char) count + '`';
    string m, t;
    m = toupper(temp[1]);
    if(m == "P" || m == "p")
        t = "" + dummy + to_string(i / 2);
    else
        t = m + "" + dummy + to_string(i / 2);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("test.txt", "r", stdin);
    vector<string> white;
    vector<string> black;
    vector<string> whiteP;
    vector<string> blackP;
    for(int i = 18; i > 1; i--)
    {
        if(i % 2 != 0)
        {
            string line;
            getline(cin, line, '\n');
            line = line.substr(1, line.size() - 2);
//            cout << i << "line: " << line << endl;
            stringstream ss(line);
            string temp;
            int count = 0;
            while(getline(ss, temp, '|'))
            {
                count++;
                if(temp[1] != ':' && temp[1] != '.')
                {
                    string t;
//                    n = (char) temp[1];
//                    cout << i/2 << "temp: " << temp << "||" << n << endl;
                    t = convert(temp, count, i);
                    if((char) temp[1] == 'P' || (char) temp[1] == 'p')
                    {
                        if(isupper(temp[1])) // white player
                            whiteP.push_back(t);
                        else
                            blackP.push_back(t);
                    }
                    else
                    {
                        if(isupper(temp[1])) // white player
                            white.push_back(t);
                        else
                            black.push_back(t);
                    }
                }
            }
        }
        else{
            string line;
            getline(cin, line, '\n');
        }
    }

    sort(white.begin(), white.end(), Comp);
    sort(black.begin(), black.end(), Comp1);

    sort(whiteP.begin(), whiteP.end(), wayToSort);
    sort(blackP.begin(), blackP.end(), wayToSort1);

    cout << "White: ";
    for(int i = 0; i < white.size(); i++)
    {
        if(i == white.size() - 1)
            cout << white[i];
        else
            cout << white[i] << ",";
    }
    if(!white.empty() && !whiteP.empty())
        cout << ",";
    for(int i = 0; i < whiteP.size(); i++)
    {
        if(i == whiteP.size() - 1)
            cout << whiteP[i];
        else
            cout << whiteP[i] << ",";
    }

    cout << endl << "Black: ";
    for(int j = 0; j < black.size(); j++)
    {
        if(j == black.size() - 1)
            cout << black[j];
        else
            cout << black[j] << ",";
    }
    if(!black.empty() && !blackP.empty())
        cout << ",";
    for(int j = 0; j < blackP.size(); j++)
    {
        if(j == blackP.size() - 1)
            cout << blackP[j];
        else
            cout << blackP[j] << ",";
    }
    return 0;
}