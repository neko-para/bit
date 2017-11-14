unsigned char ctz_mp[256];

#define ctzb(v) (ctz_mp[v])

inline void ctz_init() {
    for (register unsigned i = 0; i < 256; ++i) {
        register unsigned x = i;
        while (x) {
            ++ctz_mp[i];
            x >>= 1;
        }
    }
}