#include <iostream>
#include <string> // for string handling
#include <algorithm> // for swap()

// problem link: 'https://codeforces.com/problemset/problem/266/B'

using namespace std;
using ll = long long;

void solve() {
    int n, t;
    cin >> n >> t;
    string Queue;
    cin >> Queue;

    // Simulation for each second
    for (int i = 0; i < t; ++i) {
        // We must check every position, but if we swap,
        // we skip the next index to avoid moving the same boy twice in 1 second.
        for (int index = 0; index < n - 1; ++index) {
            if (Queue[index] == 'B' && Queue[index + 1] == 'G') {
                swap(Queue[index], Queue[index + 1]);
                index++; // Skip the next position because that boy already moved
            }
        }
    }
    cout << Queue << endl;
}

int main() {
    solve();
    return 0;
}