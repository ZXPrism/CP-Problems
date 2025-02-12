#include "testlib.h"
#include <bits/stdc++.h>

constexpr int MAXN = 1'000'000;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int testCount = inf.readInt();

    auto ReadAnswer = [&](InStream &stream) {
        std::vector<long long> res;

        constexpr long long MAXANS = 1LL * MAXN * (MAXN - 1) / 2;

        for (int testCase = 1; testCase <= testCount; testCase++) {
            setTestCase(testCase);

            long long token = stream.readLong(0LL, MAXANS, "token");
            res.push_back(token);
        }
        stream.quitif(!stream.seekEof(), _pe, "Expected EOF after reading %d token(s)", testCount);

        return res;
    };

    auto outTokens = ReadAnswer(ouf);
    auto ansTokens = ReadAnswer(ans);

    for (int testCase = 1; testCase <= testCount; testCase++) {
        setTestCase(testCase);

        if (outTokens[testCase - 1] != ansTokens[testCase - 1]) {
            quitf(_wa, "Expected %lld, found %lld", ansTokens[testCase - 1],
                  outTokens[testCase - 1]);
        }
    }

    quitf(_ok, "%d token(s)", testCount);

    return 0;
}
