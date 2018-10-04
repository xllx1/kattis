#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    //ASCII: A(65)
    freopen("test.txt", "r", stdin);
    int rightP = 0, time = 0, t = 0;
    char problem;
    string line, status;
    int frequency[25] = {0};
    while (getline(cin, line, '\n'), line != "-1") {
        stringstream ss(line);
        ss >> time >> problem >> status;
//        cout << "time: " << time << ":: problem id: " << problem - 65 << ":: status: " << status << endl;
        if (status == "right") {
            rightP++;
            frequency[problem - 65] += time;
            t += frequency[problem - 65];
//            cout << time << "right: " << problem << "::" << problem - 65 << " | frequency: " << frequency[problem - 65] << endl;
        } else {
            frequency[problem - 65] += 20;
//            cout << "wrong: " << problem << "::" << problem - 65 << " | frequency: " << frequency[problem - 65] << endl;
        }
    }
    cout << rightP << " " << t;
    return 0;
}