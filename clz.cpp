unsigned char clz_mp[256];

#define clzb(v) (clz_mp[v])

inline void clz_init() {
	for (register unsigned i = 0; i < 256; ++i) {
		register unsigned x = i;
		while (x) {
			++clz_mp[i];
			x >>= 1;
		}
		clz_mp[i] = 8 - clz_mp[i];
	}
}

inline unsigned clzw(register unsigned short v) {
	return (v >> 8) ? (clz_mp[v >> 8]) : (8 + clz_mp[v]);
}

inline unsigned clzl(register unsigned v) {
	if (v >> 16) {
		return (v >> 24) ? clz_mp[v >> 24] : (8 + clz_mp[v >> 16]);
	} else {
		return (v >> 8) ? (16 + clz_mp[v >> 8]) : (24 + clz_mp[v]);
	}
}

inline unsigned clzll(register unsigned long long v) {
	if (v >> 32) {
		if (v >> 48) {
			return (v >> 56) ? clz_mp[v >> 56] : (8 + clz_mp[v >> 48]);
		} else {
			return (v >> 40) ? (16 + clz_mp[v >> 40]) : (24 + clz_mp[v >> 32]);
		}
	} else {
		if (v >> 16) {
			return (v >> 24) ? (32 + clz_mp[v >> 24]) : (40 + clz_mp[v >> 16]);
		} else {
			return (v >> 8) ? (48 + clz_mp[v >> 8]) : (56 + clz_mp[v]);
		}
	}
}