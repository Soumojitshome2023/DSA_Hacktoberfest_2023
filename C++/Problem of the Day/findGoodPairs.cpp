/*
   * कर्मणये वाधिकारस्ते मां फलेषु कदाचन ।
   * मां कर्मफलहेतुर्भू: मांते संङगोस्त्वकर्मणि ॥
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

/*
   *  Complete the function which takes the number of ice creamns n, their flavours a[], and minimum distance K as input parameters. It returns the number of possible pairs of ice creams that can be bought.

    Input:
        n = 5, k = 2
        a = {1, 2, 2, 1, 2}

        Output:
        3

        Explanation:
        Possible pairs are found at indices
        (0, 3) where distance, 3-0 >= 2
        (1, 4) where distance, 4-1 >= 2
        (2, 4) where distance, 4-2 >= 2
*/
#include <unordered_map>
#include <vector>

using namespace std;

long long findGoodPairs(vector<int>& a, int n, int k) {
    // Initialize a map to store the indices of each flavor
    unordered_map<int, vector<int> > flavor_indices;

    for (int i = 0; i < n; i++) {
        flavor_indices[a[i]].push_back(i);
    }
    long long good_pairs = 0;

    for (auto& entry : flavor_indices) {
        vector<int>& indices = entry.second;
        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                if (indices[j] - indices[i] >= k) {
                    good_pairs++;
                }
            }
        }
    }
    return good_pairs;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << findGoodPairs(a, n, k) << endl;
}

int32_t main() {
     system("clear");
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("/Users/aman/Documents/30 Days of Code/input.txt", "r", stdin);
    freopen("/Users/aman/Documents/30 Days of Code/output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}
