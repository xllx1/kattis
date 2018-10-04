#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, k, leftmost;
    vector<int> nums;
    vector<int> output;
    int curr = 0;
    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
        {
            cin >> k;
            nums.push_back(k);
        }
        leftmost = nums[0];
        output.push_back(nums[0]);
        curr = nums[0];
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] > curr)
            {
                output.push_back(nums[j]);
                curr = nums[j];
            }
        }

        cout << output.size() << endl;
        for(auto it:output)
            cout << it << " ";
    }
}