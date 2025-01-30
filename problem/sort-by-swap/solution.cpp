#include <bits/stdc++.h>

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    auto ref = v;
    std::ranges::sort(v);

    std::vector<int> mismatch;
    for (int i = 0; i < n; i++) {
        if (v[i] != ref[i]) {
            mismatch.push_back(i);
        }
    }

    bool adjDuplicate = false;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] == v[i]) {
            adjDuplicate = true;
            break;
        }
    }

    if (mismatch.size() == 0 && adjDuplicate) {
        std::cout << "YES\n";
    } else if (mismatch.size() == 2 && mismatch[0] + 1 == mismatch[1]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
