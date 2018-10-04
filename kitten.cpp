#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("1.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	map<int, int> mp;
	int cur;
	cin >> cur;
	cin.get();
	string line;
	while(getline(cin, line), line != "-1")
	{
		stringstream ss(line);
		vector<int> vec;
		int temp;
		while(ss >> temp)
			vec.push_back(temp);
		for(int i = 1; i < vec.size(); i++)
			mp[vec[i]] = vec[0];
	}
	cout << cur << " ";
	while(mp.find(cur) != mp.end())
	{
		cur = mp.find(cur) -> second;
		cout << cur << " ";
	}
	return 0;
}