import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    v = list(map(int, input().split()))
    s = sum(v)
    MOD = int(1e9 + 7)
    for i in range(1, n):
        s = (s << 1) % MOD
    print(s)


t = int(input())
for _ in range(t):
    solve()
