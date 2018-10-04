#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("1.txt", "r", stdin);
	int num;
	cin >> num;
	int arr[num] = {};
	unordered_multiset<int> st;
	for(int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	
	for(int k = 0; k < num; k++)
	{
		if(k == 0)
			st.insert(arr[k] - 1);
		else
		{
			auto it = st.find(arr[k]);
			if(it == st.end())//if not found
				st.insert(arr[k] - 1);
			else
			{
				st.erase(it);
				st.insert(arr[k] - 1);
			}
		}
	}
	cout << st.size() << endl;
	return 0;
}