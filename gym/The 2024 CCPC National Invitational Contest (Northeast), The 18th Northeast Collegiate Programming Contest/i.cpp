#include<bits/stdc++.h>
#define fore(i,l,r)	for(int i=(int)(l);i<(int)(r);++i)
#define fi first
#define se second
#define endl '\n' 
#define ull unsigned long long

const int INF=0x3f3f3f3f;
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;

typedef long long ll;

template<class T>
constexpr T power(T a, ll b){
    T res = 1;
    while(b){
        if(b&1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

constexpr ll mul(ll a,ll b,ll mod){ //快速乘，避免两个long long相乘取模溢出
    ll res = a * b - ll(1.L * a * b / mod) * mod;
    res %= mod;
    if(res < 0) res += mod; //误差
    return res;
}

template<ll P>
struct MLL{
    ll x;
    constexpr MLL() = default;
    constexpr MLL(ll x) : x(norm(x % getMod())) {}

    static ll Mod;
    constexpr static ll getMod(){
       if(P > 0) return P;
       return Mod;
    }

    constexpr static void setMod(int _Mod){
       Mod = _Mod;
    }
    constexpr ll norm(ll x) const{
       if(x < 0){
           x += getMod();
       }
       if(x >= getMod()){
           x -= getMod();
       }
       return x;
    }
    constexpr ll val() const{
       return x;
    }
    explicit constexpr operator ll() const{ 
       return x; //将结构体显示转换为ll类型： ll res = static_cast<ll>(OBJ)
    }
    constexpr MLL operator -() const{ //负号，等价于加上Mod
       MLL res;
       res.x = norm(getMod() - x);
       return res;
    }
    constexpr MLL inv() const{
       assert(x != 0);
       return power(*this, getMod() - 2); //用费马小定理求逆
    }
    constexpr MLL& operator *= (MLL rhs) & { //& 表示“this”指针不能指向一个临时对象或const对象
       x = mul(x, rhs.x, getMod()); //该函数只能被一个左值调用
       return *this;
    }
    constexpr MLL& operator += (MLL rhs) & {
       x = norm(x + rhs.x);
       return *this;
    }
    constexpr MLL& operator -= (MLL rhs) & {
       x = norm(x - rhs.x);
       return *this;
    }
    constexpr MLL& operator /= (MLL rhs) & {
       return *this *= rhs.inv();
    }
    friend constexpr MLL operator * (MLL lhs, MLL rhs){
       MLL res = lhs;
       res *= rhs;
       return res;
    }
    friend constexpr MLL operator + (MLL lhs, MLL rhs){
       MLL res = lhs;
       res += rhs;
       return res;
    }
    friend constexpr MLL operator - (MLL lhs, MLL rhs){
       MLL res = lhs;
       res -= rhs;
       return res;
    }
    friend constexpr MLL operator / (MLL lhs, MLL rhs){
       MLL res = lhs;
       res /= rhs;
       return res;
    }
    friend constexpr std::istream& operator >> (std::istream& is, MLL& a){
       ll v;
       is >> v;
       a = MLL(v);
       return is;
    }
    friend constexpr std::ostream& operator << (std::ostream& os, MLL& a){
       return os << a.val();
    }
    friend constexpr bool operator == (MLL lhs, MLL rhs){
       return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (MLL lhs, MLL rhs){
       return lhs.val() != rhs.val();
    }
};

const ll mod = 998244353;
using Z = MLL<mod>;

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        m = std::min(1ll * m, Z::getMod() - 1);
        if (m <= n) return; //已经处理完了需要的长度
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) { //线性递推逆元和阶乘逆元
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m; //新的长度
    }

    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) { //二项式系数
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    if(n < k){
    	std::cout << "0\n";
    	return 0;
    }
    std::vector<Z> dp(n + 1);
    std::vector<Z> g(k + 1, 0);
	dp[k] = comb.fac(k); //初始化为 k 阶乘
	fore(i, 1, k + 1){
		g[i] = comb.fac(i);
		fore(j, 1, i)	g[i] -= comb.fac(j) * g[i - j];
	}
	
	fore(i, k + 1, n + 1)
		fore(j, 1, k + 1)
			dp[i] += dp[i - j] * g[j];
	
	std::cout << dp[n] << endl;
	
	return 0; 
}
