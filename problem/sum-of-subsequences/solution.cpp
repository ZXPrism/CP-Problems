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

    i64 sum = std::accumulate(v.begin(), v.end(), 0LL);
    constexpr i64 MOD = 1000'000'007;
    for (int i = 1; i < n; i++) {
        sum = (sum << 1) % MOD;
    }

    std::cout << sum << '\n';
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
