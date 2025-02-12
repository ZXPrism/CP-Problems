#include <bits/stdc++.h>

using u64 = unsigned long long;
using i64 = long long;

constexpr int MAX_VAL = 1'000'000;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::vector<i64> squares(MAX_VAL);
    for (int i = 1; i <= MAX_VAL; i++) {
        squares[i - 1] = 1LL * i * i;
    }

    i64 ans = 0;
    std::vector<int> cnt(MAX_VAL + 1);
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            for (auto sq : squares) {
                if (sq % v[i] == 0 && sq / v[i] <= MAX_VAL) {
                    ans += cnt[sq / v[i]];
                }
            }
            ans += cnt[0];
        } else {
            ans += i;
        }

        ++cnt[v[i]];
    }

    std::cout << ans << '\n';
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
