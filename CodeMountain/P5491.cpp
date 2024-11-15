#include <bits/stdc++.h>

using namespace std;
mt19937 mt(time(nullptr));
long long p, N, I;
class Complex{
public:
    long long real, imag;
    Complex(long long real = 0, long long imag = 0): real(real % p), imag(imag % p) {}
    Complex operator + (const Complex &rhs) const {
        return Complex(real + rhs.real, imag + rhs.imag);
    }
    Complex operator - (const Complex &rhs) const {
        return Complex((real - rhs.real) % p + p, (imag - rhs.imag) % p + p);
    }
    Complex operator * (const Complex &rhs) const {
        return Complex(real * rhs.real % p + I * imag % p * rhs.imag % p, real * rhs.imag % p + imag * rhs.real % p);
    }
    Complex operator % (const long long &rhs) const {
        return Complex(real % rhs, imag % rhs);
    }
};
template <typename T>
T qpow(T a, long long b) {
    T res = 1;
    for(; b; b >>= 1, a = a * a % p) if(b & 1) res = res * a % p;
    return res;
}
long long cipolla(long long n, long long p) {
    n %= p;
    long long a;
    while(true) {
        a = mt() % p;
        if(qpow((a * a % p - n + p) % p, (p - 1)/2ll) == p - 1) break;
    }
    I = (a * a % p - n + p) % p;
    Complex x(a, 1), res = qpow(x, (p + 1)/2ll);
    return res.real;
}
void solve() {
    cin >> N >> p;
    if(!N) return cout << 0 << endl, void();
    if(qpow(N, (p - 1)/2ll) == p - 1) return cout << "Hola!" << endl, void();
    auto ans1 = cipolla(N, p), ans2 = p - ans1;
    if(ans1 > ans2) swap(ans1, ans2);
    if(ans1 ^ ans2) cout << ans1 << ' ' << ans2 << endl;
    else cout << ans1 << endl;
}
int main() {
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}