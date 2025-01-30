#include "testlib.h"
#include <bits/stdc++.h>

constexpr int MAX_TEST_COUNT = 100;
constexpr int MAX_N = 200'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int testCount = inf.readInt(1, MAX_TEST_COUNT, "testCount");
    inf.readEoln();

    long long sumN = 0;
    for (int testCase = 1; testCase <= testCount; testCase++) {
        setTestCase(testCase);

        // check n: the length of array
        int n = inf.readInt(1, MAX_N, "n");
        inf.readEoln();
        sumN += n;
        ensuref(sumN <= MAX_N, "Sum of `n` over all test cases should not exceed %d", MAX_N);

        // check the array
        auto perm = inf.readInts(n, 1, n, "p");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
