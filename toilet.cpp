#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("1.txt", "r", stdin);
	vector<char> vec;
	string line;
	int up = 0, down = 0, stay = 0;
	getline(cin, line);
	//1: always up; 2: always down; 3: leave it as it is
	for(int i = 1; i < line.size(); i++)
	{
		if(i == 1)
		{
			if(line[1] != line[0])
			{
				up++;
				if(line[i] != 'U')
					up++;
				
				down++;
				if(line[i] != 'D')
					down++;
				stay++;
			}
			else
			{
				if(line[1] != 'U')
					up++;
				if(line[1] != 'D')
					down++;
			}
		}
		else
		{
			if(line[i] != 'U')
				up += 2;
			if(line[i] != 'D')
				down += 2;
			if(line[i] != line[i - 1])
				stay++;
		}
			
	}
	cout << up << endl;
	cout << down << endl;
	cout << stay << endl;
	return 0;
}