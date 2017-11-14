#include <bits/stdc++.h>
using namespace std;

#include "ctz.cpp"

#define _TEST_SIZE_ 1000000000
#define _TEST_INIT_ ctz_init
#define _TEST_BUILTIN_ __builtin_ctzll
#define _TEST_FUNC_ ctzll

int main() {
    _TEST_INIT_();
    clock_t t = clock();
    unsigned ans = 0;
    for (long long i = 1; i < _TEST_SIZE_; ++i) {
        ans +=_TEST_BUILTIN_(i);
    }
    cout << clock() - t << ' ' << ans << endl;
    t = clock();
    ans = 0;
    for (long long i = 1; i < _TEST_SIZE_; ++i) {
        ans += _TEST_FUNC_(i);
    }
    cout << clock() - t << ' ' << ans << endl;
    return ans;
}
