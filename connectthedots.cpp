#include <bits/stdc++.h>

using namespace std;
#define s 120
int main()
{
    //freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string sequence = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<int, vector<string>> images;
    vector<pair<int, int>> posOf0(s, {-1, -1}); //posOf0[imageNo] = {row, col}
    //image input 0-9, a-z, A-Z and .
    string inputLine;
    int imageNo = 0, row = 0;
    while(getline(cin, inputLine, '\n'))
    {
        if(inputLine.empty())
        {
            imageNo++;
            row = 0;
        }
        else
        {
            int found = inputLine.find('0');
            if(found != -1) //if found
            {
                posOf0[imageNo].first = row;
                posOf0[imageNo].second = found;
            }
            images[imageNo].push_back(inputLine);
            row++;
        }
    }

    //io handling finished and found position of 0
    //find next symbol, vertically or horizontally
    for(int l = 0; l <= imageNo; l++)
    {
        pair<int, int> pos = posOf0[l]; //{row, col}
        for(int m = 1; m < sequence.size(); m++)
        {
            if(pos.first == -1 || pos.second == -1) continue;
            char findChar = sequence[m];
            //find col: pos.second
            int foundNextCol = images[l][pos.first].find(findChar);
            if(foundNextCol != -1) //if found
            {
                int start = min(pos.second, foundNextCol);
                int end = max(pos.second, foundNextCol);
                for(int j = start + 1; j < end; j++)
                    if(images[l][pos.first][j] == '.')
                        images[l][pos.first][j] = '-';
                    else if(images[l][pos.first][j] == '|')
                        images[l][pos.first][j] = '+';
                pos.second = foundNextCol;
                continue;
            }
            //if not found in the same row
            //find other rows: pos.first
            for(int n = 0; n < images[l].size(); n++)
            {
                if(n == pos.first) continue;
                if(images[l][n][pos.second] == findChar)
                {
                    int start = min(pos.first, n);
                    int end = max(pos.first, n);
                    for(int j = start + 1; j < end; j++)
                        if(images[l][j][pos.second] == '.')
                            images[l][j][pos.second] = '|';
                        else if(images[l][j][pos.second] == '-')
                            images[l][j][pos.second] = '+';
                    pos.first = n;
                    break;
                }
            }
        }
    }

    //debug: print variables

    for(auto it : images)
    {
        //int iNo = it.first;
        for(auto itcc : it.second)
        {
            //cout << iNo << "::";
            for(auto k : itcc)
                cout << k;
            cout << endl;
        }
        //cout << "pos of 0: " << posOf0[iNo].first << ", " << posOf0[iNo].second << endl;
        cout << endl;
    }


    return 0;
}