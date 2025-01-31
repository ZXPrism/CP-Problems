#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int testCount = opt<int>("testCount");
    int sumN = opt<int>("sumN");
    int maxVal = opt<int>("maxVal");

    auto lengths = rnd.partition(testCount, sumN);
    std::cout << testCount << '\n';

    for (auto n : lengths) {
        std::cout << n << '\n';

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(1, maxVal);
        }

        // NOTE: `println` is recommended here rather than directly `cout`
        // since it won't output additional space after the last element
        // which will violate "the well-formed rule"
        println(a);
    }

    return 0;
}
