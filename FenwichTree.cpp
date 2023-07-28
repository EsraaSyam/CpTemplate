#include <bits/stdc++.h>
#define nl "\n"
#define fi first
#define se second
#define pi 3.14159
#define ll long long
#define odd(a)  (a&1)
#define even(a)  !(a&1)
#define Mod 1'000'000'007
#define INF 2'000'000'000
#define sz(x) int(x.size())
#define charToInt(s) (s - '0')
#define ull unsigned long long
#define all(s) s.begin(), s.end()
#define rall(v) v.rbegin() , v.rend()
#define fixed(n) fixed << setprecision(n)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define cin(vec) for(auto& i : vec) cin >> i
#define to_decimal(bin) stoll(bin, nullptr, 2)
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Floor(n, m) (((n) / (m)) - ((n) % (m) ? 0 : 1))
#define Upper(s) transform(all(s), s.begin(), ::toupper);
#define Lower(s) transform(all(s), s.begin(), ::tolower);
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
using namespace std;
void esraa()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

struct FenwickTree{
    vector < ll > bit;
    int size {};

    explicit FenwickTree(int n){ // to initialize the tree with size n
        size = n;
        bit.assign(size + 5 , 0);
    }
 
    void update(int idx , ll val){ // to add val to the index idx
        for(; idx < size; idx += (idx & -idx))
            bit[idx] += val;
    }
 
    void update(int l , int r , ll val){ // to add val to the range [l , r]
        update(l , val);
        update(r + 1 , -val);
    }
 
    ll sum(int idx){ // to get the sum of the range [1 , idx]
        ll ret {};
        for(; idx > 0; idx -= (idx & -idx))
            ret += bit[idx];
        return ret;
    }
 
    ll sum(int l , int r){ // to get the sum of the range [l , r]
        return sum(r) - sum(l - 1);
    }
};

void solve(){
    int n , m;
    cin >> n >> m;
    vector < ll > v(n);
    for(auto& i : v) cin >> i;
    FenwickTree ft(n + 1);
    for(int i = 0  ; i < n ; i++){
        ft.update(i + 1 , i + 1 , v[i]); // to initialize the tree with the values of the array
    }
  
} 
int main()
{
    esraa();
    int t = 1;
   // cin >> t;
    while(t--)
      solve();
    return 0;
}