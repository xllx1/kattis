#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n, T, k, output = 0, j = 0;
    list<int> tasks;
    while(cin >> n)
    {
        cin >> T;
        for(int i = 0; i < n; i++)
        {
            cin >> k;
            tasks.push_back(k);
        }
        while((j + tasks.front()) <= T && !tasks.empty())
        {
            j += tasks.front();
            tasks.pop_front();
            output++;
        }

        cout << output << endl;
        output = 0;
        j = 0;
        tasks = list<int>();
    }

    return 0;
}