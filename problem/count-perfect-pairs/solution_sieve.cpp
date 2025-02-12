#include <bits/stdc++.h>

using u64 = unsigned long long;
using i64 = long long;

constexpr int N = 1'000'000;
std::vector<int> minPrimeFac(N + 1);

void sieve() {
    std::vector<int> notPrime(N + 1);
    std::vector<int> primes;

    notPrime[0] = 1;
    notPrime[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (!notPrime[i]) {
            minPrimeFac[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (1LL * i * p > N) {
                break;
            }

            minPrimeFac[i * p] = p;
            notPrime[i * p] = 1;

            if (i % p == 0) {
                break;
            }
        }
    }
}

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

        while (v[i] && v[i] != 1) {
            int fac = minPrimeFac[v[i]], power = 0;
            while (v[i] % fac == 0) {
                ++power;
                v[i] /= fac;
            }
            if (power & 1) {
                eigen *= fac;
            }
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

    sieve();

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
