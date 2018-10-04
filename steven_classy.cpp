// monitor this cs2040c public repl for live discussion
// on Sat 24 March 2018, 9am-2pm

// this is the public discussion of solving
// https://open.kattis.com/problems/classy

#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> stringstring; // we want to associate somebody with his/her class, so let's just use a pair :)

string toHashCode(string &the_ranking) { // convert the_ranking into an EXACTLY 10 digits string for precise comparison :), yes, define our own hash function
    // example from Sample Input 1:
    // mom: upper-upper-lower-middle          --> 3312222222
    // dad: middle-middle-middle-lower-middle --> 2221222222
    // hence mom is higher than dad
    string hashcode = "", token;
    int i = 0;
    istringstream iss(the_ranking);
    while (getline(iss, token, '-')) { // at most 10 tokens, separated by a '-'
        i++;
        if (token == "upper" ) hashcode = "3" + hashcode; // give a '3' (1 char) for an "upper" (5 characters)
        else if (token == "middle") hashcode = "2" + hashcode; // give a '2' (1 char) for a "middle" (6 characters, the one that can confuse your comparison)
        else if (token == "lower" ) hashcode = "1" + hashcode; // give a '1' (1 char) for an "lower" (5 characters)
    }
    // LAST PART: something is missing, this is near complete, is your hashcode always 10 digits? :D
    string k;
    for(int i = 0; i < (10 - hashcode.size()); i++)
    {
        k += "B";
    }
    hashcode = hashcode + k;
    return hashcode; // temporary, no change here
}

int main() {
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); // always use this if you are a C++ user, just to avoid silly TLE

    int T; // 1 <= T <= 500, number of test cases
    cin >> T; // just read it

    while (T--) { // repeat T times, O(T * (mn + mn log n)) = O(Tmn log n)
        int n; // 1 <= n <= 100, number of people
        cin >> n; // just read it

        // read input and store in a vector of pair of strings
        vector<stringstring> people;
        for (int i = 0; i < n; i++) { // O(10mn), m is length of name, not more than 30, the word "upper", "middle", "lower" also short
            string name, ranking, dummy_class; // each of the n lines have format
            cin >> name >> ranking >> dummy_class; // "name:" (the ':' is annoying) ranking (separated with '-') and the useless suffix 'class'
            name.pop_back(); // delete that last ':' in first token/string (name)
            people.emplace_back(toHashCode(ranking), name); // the priority is sort descending by ranking first, before sort by name (unique names)
            cout << name << "::" << ranking << "::" << toHashCode(ranking) << endl;
        }

        // the main part, "sort"
        sort(people.begin(), people.end(), [](const stringstring &a, const stringstring &b) { // O(m * n log n)
            if (a.first != b.first) return a.first  > b.first;  // descending of class... we need to focus on how to properly sort the classes
            else                    return a.second < b.second; // ascending of name (unique)
        });

        // print the answer (final form)
        for (auto &ranking_name : people) // O(mn)
            cout << ranking_name.second << endl;
        cout << "==============================\n";
    }

    return 0;
}
