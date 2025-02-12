#include <bits/stdc++.h>

using u64 = unsigned long long;
using i64 = long long;

constexpr int N = 1'000'000;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int zeroCnt = 0;
    i64 ans = 0;
    std::vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int eigen = 1;

        int sqr = static_cast<int>(std::sqrt(v[i]));
        for (int fac = 2; fac <= sqr; fac++) {
            int power = 0;
            while (v[i] % fac == 0) {
                ++power;
                v[i] /= fac;
            }
            if (power & 1) {
                eigen *= fac;
            }
        }
        if (v[i] != 1) {
            eigen *= v[i];
        }

        if (v[i]) {
            ans += cnt[eigen] + zeroCnt;
            ++cnt[eigen];
        } else {
            ans += i;
            ++zeroCnt;
        }
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
