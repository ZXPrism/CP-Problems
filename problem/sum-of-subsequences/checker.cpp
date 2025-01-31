#include "testlib.h"
#include <bits/stdc++.h>

constexpr int MOD = 1'000'000'007;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int testCount = inf.readInt();

    auto ReadAnswer = [&](InStream &stream) {
        std::vector<int> res;

        for (int testCase = 1; testCase <= testCount; testCase++) {
            setTestCase(testCase);

            int token = stream.readInt(0, MOD - 1, "token");
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
            quitf(_wa, "Expected %d, found %d", ansTokens[testCase - 1], outTokens[testCase - 1]);
        }
    }

    quitf(_ok, "%d token(s)", testCount);

    return 0;
}
