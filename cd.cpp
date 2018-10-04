#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    int Jack,Jill;
    while(cin >> Jack >> Jill && Jack != 0 && Jill != 0)
    {
        int output = 0;
        unordered_multimap<int, int> cd;
        for(int i = 0; i < Jack; i++)
        {
            int M;
            cin >> M;
            cd.insert(make_pair<int, int>(move(M), 1));//jack frequency of  catalog numbers++
        }
        for(int i = 0; i < Jill; i++)
        {
            int N;
            cin >> N;
            auto it = cd.find(N);
            if(it != cd.end() && it -> second == 1)
                output++;
        }
        cout << output << endl;
    }
    return 0;
}