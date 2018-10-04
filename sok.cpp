#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double ratio = 0, o = 0 , m = 0;
    vector<double> output(3, 0);
    vector<int> fruit(3, 0);
    vector<int> fruitL(3, 0);

    while(cin >> fruit[0] >> fruit[1] >> fruit[2] >> fruitL[0] >> fruitL[1] >> fruitL[2])
    {

        for(int i = 0; i < 3; i++)
        {
            o = (double)(fruitL[i]*1.0/fruit[i]);
            if(o > m)
            {
                m = o;
                ratio = (double) fruit[i]*1.0/fruitL[i];
            }
        }

        for(int i = 0; i < 3; i++)
        {
            output[i] = (double) (fruit[i] - fruitL[i] * ratio) * 1.0;
        }

        cout << fixed;
        cout << setprecision(5);

        for(auto it : output)
            cout << it << " ";

        fruit.clear();
        fruitL.clear();
        ratio = 0;
        m = 0;
        o = 0;
    }
    return 0;
}
