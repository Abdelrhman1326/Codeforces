#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    int k1; cin >> k1;
    queue<int> firstSoldier, secondSoldier;

    for (int i = 0; i < k1; i++) {
        int x; cin >> x;
        firstSoldier.push(x);
    }

    int k2; cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x; cin >> x;
        secondSoldier.push(x);
    }

    int turns = 0;

    // n <= 10, which means the number of possible combinations is finite:
    // either end
    // or repeat a previous state → infinite loop
    const int LIMIT = 100000; // safe number

    while (!firstSoldier.empty() && !secondSoldier.empty()) {
        if (turns > LIMIT) {
            cout << -1;
            return;
        }

        int a = firstSoldier.front(); firstSoldier.pop();
        int b = secondSoldier.front(); secondSoldier.pop();

        if (a > b) {
            firstSoldier.push(b);
            firstSoldier.push(a);
        } else {
            secondSoldier.push(a);
            secondSoldier.push(b);
        }

        turns++;
    }

    if (firstSoldier.empty()) cout << turns << " 2";
    else cout << turns << " 1";
}

int main() {
    solve();
    return 0;
}