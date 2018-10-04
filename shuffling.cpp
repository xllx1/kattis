#include <bits/stdc++.h>

using namespace std;

vector<int> ca;
vector<int> temp;

int in_shuffle()
{
    int first = 0, cards = ca.size(), k = 0;
    int second = ca.size() / 2;
    while(first < ca.size() / 2)
    {
        temp[k++] = ca[second++];
        temp[k++] = ca[first++];
    }
    if(k < cards)
        temp[k] = ca[second];
}

void out_shuffle()
{
    int first = 0, cards = ca.size(), k = 0;
    int second = (ca.size() + 1) / 2;
    while(second < cards)
    {
        temp[k++] = ca[first++];
        temp[k++] = ca[second++];
    }
    if(k < cards)
        temp[k] = ca[first];
    // int m = 0;
    // for(auto &it : temp)
    // cout << m++ << "::" << it << endl;
}

bool match()
{
    for(int j = 0; j < ca.size(); j++)
    {
        if(ca[j] != j)
        {
            // cout << "mismatched" << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("2.txt", "r", stdin);
    int cards, output = 1;
    string io;
    cin >> cards >> io;

    for(int i = 0; i < cards; i++)
    {
        temp.push_back(i);
        ca.push_back(i);
    }
    if(io == "in")
        in_shuffle();
    else
        out_shuffle();
    ca.assign(temp.begin(), temp.end());

    while(!match())
    {
        if(io == "in")
            in_shuffle();
        else
            out_shuffle();
        ca.assign(temp.begin(), temp.end());
        output++;
    }

    cout << output << endl;
    return 0;
}