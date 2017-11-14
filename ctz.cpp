unsigned char ctz_mp[256];

inline void ctz_init() {
    for (register unsigned i = 0; i < 256; ++i) {
        register unsigned x = i;
        while (x) {
            ++ctz_mp[i];
            x >>= 1;
        }
    }
}

#define ctzb(v) (ctz_mp[v])

inline unsigned ctzw(register unsigned short v) {
    return ((unsigned char)(v)) ? ctz_mp[(unsigned char)v] : (8 + ctz_mp[(unsigned char)(v >> 8)]);
}

inline unsigned ctzl(register unsigned v) {
    if ((unsigned short)v) {
        return ((unsigned char)(v)) ? ctz_mp[(unsigned char)v] : (8 + ctz_mp[(unsigned char)(v >> 8)]);
    } else {
        return ((unsigned char)(v >> 16)) ? (16 + ctz_mp[(unsigned char)(v >> 16)]) : (24 + ctz_mp[(unsigned char)(v >> 24)]);
    }
}

inline unsigned ctzll(register unsigned long long v) {
    if ((unsigned)v) {
        if ((unsigned short)v) {
            return ((unsigned char)(v)) ? ctz_mp[(unsigned char)v] : (8 + ctz_mp[(unsigned char)(v >> 8)]);
        } else {
            return ((unsigned char)(v >> 16)) ? (16 + ctz_mp[(unsigned char)(v >> 16)]) : (24 + ctz_mp[(unsigned char)(v >> 24)]);
        }
    } else {
        if ((unsigned short)(v >> 32)) {
            return ((unsigned char)(v >> 32)) ? (32 + ctz_mp[(unsigned char)(v >> 32)]) : (40 + ctz_mp[(unsigned char)(v >> 40)]);
        } else {
            return ((unsigned char)(v >> 48)) ? (48 + ctz_mp[(unsigned char)(v >> 48)]) : (56 + ctz_mp[(unsigned char)(v >> 56)]);
        }
    }
}