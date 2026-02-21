#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> solve() {
    int n; cin >> n;
    vector<int> x(n); for (auto &num : x) cin >> num;
    int q; cin >> q;
    vector<int> m(q); for (auto &num : m) cin >> num;

    // we are not interested about the index of the shop
    // we are just interested about the shops prices

    // sort the prices at shops; to be able to do binary search on it:
    sort(x.begin(), x.end());

    // create a vector for the answers:
    vector<int> answers;

    // for each day qi, look how many shops have price <= mi:
    for (auto &max_price : m) {
        // now binary search on the shops in x:
        int left = 0, right = n - 1, middle = 0;
        int max_bottles = 0;
        while (left <= right) {
            int middle = left + (right - left)/2;
            if (x[middle] <= max_price) {
                int number_of_bottles = middle + 1;
                max_bottles = max(number_of_bottles, max_bottles);
                left = middle + 1;
            } else if (x[middle] > max_price) {
                right = middle - 1;
            }
        }
        answers.push_back(max_bottles);
    }

    return answers;
}

int main() {
    vector<int> answers = solve();
    for (auto &num : answers) cout << num << endl;
    return 0;
}