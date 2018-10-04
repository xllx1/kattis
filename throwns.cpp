#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    int students, command;
    stack<int> st;
    cin >> students >> command;
    cin.get();
    st.push(0);
    while(command--)
    {
        string cmd;
        int m;
        cin >> cmd;
        if(cmd == "undo")
        {
            cin >> m;
            while(m--)
                st.pop();
        }
        else
        {
            m = stol(cmd);
            st.push(((st.top() + m) % students + students) % students);
        }
    }
//    int ans = st.top() % students;
    cout << st.top() << endl;
    return 0;
}