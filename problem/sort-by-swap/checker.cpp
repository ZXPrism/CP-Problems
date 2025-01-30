#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int testCount = inf.readInt();

    auto ReadAnswer = [&](InStream &stream) {
        std::vector<std::string> res;

        for (int testCase = 1; testCase <= testCount; testCase++) {
            setTestCase(testCase);

            std::string token = upperCase(stream.readToken("[a-zA-Z]+", "token"));
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
            quitf(_wa, "Expected %s, found %s", ansTokens[testCase - 1].c_str(),
                  outTokens[testCase - 1].c_str());
        }
    }

    quitf(_ok, "%d token(s)", testCount);

    return 0;
}
