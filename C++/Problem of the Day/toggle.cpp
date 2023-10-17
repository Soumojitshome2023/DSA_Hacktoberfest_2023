/*
   * कर्मणये वाधिकारस्ते मां फलेषु कदाचन ।
   * मां कर्मफलहेतुर्भू: मांते संङगोस्त्वकर्मणि ॥
*/

#include <bits/stdc++.h>
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
   *
*/
#include <algorithm>
#include <vector>

using namespace std;

int toggle(int n, vector<int>& arr) {
    // Check for edge case of empty array
    if (n == 0) {
        return 0;
    }

    // Check for edge case of array with all 1s
    // if (all_of(arr.begin(), arr.end(), [](int x) { return x == 1; })) {
    //     return n;
    // }

    // Initialize variables to store the current and maximum lengths of subarrays with all 1s
    int curr_length = 0, max_length = 0;

    // Iterate over the array
    for (int i = 0; i < n; i++) {
        // If the current element is a 1, increment the current length
        if (arr[i] == 1) {
            curr_length++;
        }
        // If the current element is a 0, reset the current length and check if we should flip
        else {
            curr_length = 0;

            // If flipping the subarray starting at this position would result in a longer subarray with all 1s, update the maximum length
            max_length = max(max_length, i + 1);
        }

        // Update the maximum length if necessary
        max_length = max(max_length, curr_length);
    }

    // Return the maximum length
    return max_length;
}



void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << toggle(n, arr) << endl;
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
