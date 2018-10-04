#include <bits/stdc++.h>
using namespace std;

#define MAX_N 110 // max number of villagers

int main() {
    freopen("test.txt", "r", stdin);

    ios_base::sync_with_stdio(false); cin.tie(NULL); // standard

    int N, E, villager_id, number_of_songs = 0;
    unordered_set<int> know[MAX_N]; // MAJOR HINT: (to speed up some operations below), this is a hashtable of what songs that this villager knows

    cin >> N; // 1 <= N <= 100, the number of villagers. The villagers are numbered 1 to N. Villager number 1 is the bard.
    cin >> E; // 1 <= E <= 50 , the number of evenings.

    while (E--) { // O(E * (N+(N+EN)) = O(E^2*N)
        // Each line begins with a positive integer K, 2 <= K <= N, the number of villagers present that evening,
        int K;
        cin >> K;

        // followed by K positive integers separated by spaces representing the villagers.
        vector<int> present_tonight;
        bool bard_present = false;
        while (K--) { // O(K) = O(N) as K <= N
            cin >> villager_id;
            if (villager_id == 1) bard_present = true; // The Bard is present in this evening
            present_tonight.push_back(villager_id); // O(1)
        }

        if (bard_present) { // the Bard is present
            // The bard teaches a new song to the villagers CURRENTLY present
            number_of_songs++; // the bard teaches a new song
            for (auto &p : present_tonight) // O(K) = O(N)
                know[p].insert(number_of_songs); // this villager p, who is present tonight, learns a new song (with id = number_of_songs) from the bard, O(1) if we use hashtable
        }
        else { // the Bard is not present
            // The villagers CURRENTLY present will sing all songs that have been taught by the Bard
            // And afterwards, they will all know the songs
                for (int song_id = 1; song_id <= number_of_songs; song_id++) { // for all songs that the Bard have sung so far, O(E*N)

                for (auto &p : present_tonight) // O(K) = O(N)
                    if (know[p].find(song_id) != know[p].end()) // this villager p knows that song song_id, O(1) with unordered_set
                        for (auto &p : present_tonight) // O(K) = O(N)
                            know[p].insert(song_id);
                // LAST PART END
            }
        }
    }

    for (villager_id = 1; villager_id <= N; villager_id++) // O(N)
        if ((int)know[villager_id].size() == number_of_songs) // if this villager (including the Bard/1) knows all song, output his/her id, O(1)
            cout << villager_id << "\n"; // print that villager_id
    // PS: the Bard is always the first one of the output as the Bard knows all songs

    return 0;
}