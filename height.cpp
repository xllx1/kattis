#include <bits/stdc++.h>

using namespace std;

int insertionSort(int arr[], int n)
{
    int i, key, j, output = 0;
    for (i = 1; i < n; i++)
    {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j--;
           output++;
       }
       arr[j+1] = key;
    }
    return output;
}

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int cases;
    cin >> cases;
    cin.get();
    int output[cases] = {};
    for(int j = 0; j < cases; j++)
    {
        string line;
        getline(cin, line, '\n');
        stringstream ss(line);
        int num, temp, i = 0, arr[20] = {};
        ss >> num;
        while(ss >> temp && i < 20)
        {
            arr[i] = temp;
            i++;
        }
        output[j] = insertionSort(arr, 20);
    }
    for(int k = 0; k < cases; k++)
        cout << k + 1 << " " << output[k] << endl;
    return 0;
}