#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solve() {
    int n, m;
    if (!(cin >> n >> m)) return {};

    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    // We only need to sort 'a' to perform binary search on it
    sort(a.begin(), a.end());

    vector<vector<int>> answers;
    for (int i = 0; i < m; ++i) {
        int bi;
        cin >> bi;

        // Manual Binary Search to find the count of elements <= bi
        // We want the first index where a[mid] > bi
        int left = 0, right = n - 1;
        int count = 0;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (a[middle][0] <= bi) {
                // This element and everything to its left is <= bi
                count = middle + 1;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        // Store [original_index, answer]
        answers.push_back({i, count});
    }

    sort(answers.begin(), answers.end());
    return answers;
}

int main() {
    vector<vector<int>> answers = solve();
    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i][1] << (i == answers.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}