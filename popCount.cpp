#include <bits/stdc++.h>

inline unsigned int popCount(register unsigned int x) {
#define BIT2(n) n, n + 1, n + 1, n + 2
#define BIT4(n) BIT2(n), BIT2(n + 1), BIT2(n + 1), BIT2(n + 2)
#define BIT6(n) BIT4(n), BIT4(n + 1), BIT4(n + 1), BIT4(n + 2)
#define BIT8(n) BIT6(n), BIT6(n + 1), BIT6(n + 1), BIT6(n + 2)
    static const unsigned char F[] = {BIT8(0)};
#undef BIT8
#undef BIT6
#undef BIT4
#undef BIT2
    return F[x & 255u] + F[x >> 8 & 255u] + F[x >> 16 & 255u] +
           F[x >> 24 & 255u];
}

int main() {
    clock_t t = clock();
    int ans = 0;
    for (int i = 1; i < 100000000; ++i) {
        ans += __builtin_popcount(i);
    }
    std::cout << clock() - t << ' ' << ans << std::endl;
    t = clock();
    ans = 0;
    for (int i = 1; i < 100000000; ++i) {
        ans += popCount(i);
    }
    std::cout << clock() - t << ' ' << ans << std::endl;
    return 0;
}