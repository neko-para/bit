#include <bits/stdc++.h>
using namespace std;
#include "clz.cpp"

int main() {
    clz_init();
    clock_t t = clock();
    unsigned ans = 0;
    for (long long i = 1; i < 100000000; ++i) {
        ans += __builtin_clzll(i);
    }
    cout << clock() - t << ' ' << ans << endl;
    t = clock();
    ans = 0;
    for (long long i = 1; i < 100000000; ++i) {
        ans += clzll(i);
    }
    cout << clock() - t << ' ' << ans << endl;
    return ans;
}
