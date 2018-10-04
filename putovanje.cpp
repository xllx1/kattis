#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("1.txt", "r", stdin);
	int N, C;
	cin >> N >> C;
	vector<int> vec;
	while(N--)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	int max = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		int count = 0, eaten = 0;
		for(int j = i; j < vec.size(); j++)
		{
			if(eaten + vec[j] <= C)
			{
				eaten += vec[j];
				count++;
			}
		}
		if(count > max)
			max = count;
	}
	cout << max << endl;
	return 0;
}