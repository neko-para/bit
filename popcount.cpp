#define BIT2(n) n, n + 1, n + 1, n + 2
#define BIT4(n) BIT2(n), BIT2(n + 1), BIT2(n + 1), BIT2(n + 2)
#define BIT6(n) BIT4(n), BIT4(n + 1), BIT4(n + 1), BIT4(n + 2)
#define BIT8(n) BIT6(n), BIT6(n + 1), BIT6(n + 1), BIT6(n + 2)
const unsigned char popcount_mp[] = {BIT8(0)};
#undef BIT8
#undef BIT6
#undef BIT4
#undef BIT2

#define popcountb(x) popcount_mp[x]

inline unsigned popcountw(register unsigned short x) {
    return popcount_mp[(unsigned char)x] + popcount_mp[(unsigned char)(x >> 8)];
}

inline unsigned popcountl(register unsigned x) {
    return popcount_mp[(unsigned char)x] + popcount_mp[(unsigned char)(x >> 8)] + popcount_mp[(unsigned char)(x >> 16)] + popcount_mp[(unsigned char)(x >> 24)];
}

inline unsigned popcountll(register unsigned long long x) {
    return popcount_mp[(unsigned char)x] + popcount_mp[(unsigned char)(x >> 8)] + popcount_mp[(unsigned char)(x >> 16)] + popcount_mp[(unsigned char)(x >> 24)] +
    popcount_mp[(unsigned char)(x >> 32)] + popcount_mp[(unsigned char)(x >> 40)] + popcount_mp[(unsigned char)(x >> 48)] + popcount_mp[(unsigned char)(x >> 56)];
}