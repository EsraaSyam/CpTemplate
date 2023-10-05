#include<bits/stdc++.h>

#define nl "\n"
#define fi first
#define se second
#define pi 3.14159
#define ll long long
#define odd(a)  (a&1)
#define even(a)  !(a&1)
#define Mod 1'000'000'007
#define INF 2'000'000'000 // 2e9
#define sz(x) int(x.size())
#define charToInt(s) (s - '0')
#define ull unsigned long long
#define number_line iota(all(vec) , 1)
#define all(s) s.begin(), s.end()
#define rall(v) v.rbegin() , v.rend()
#define fixed(n) fixed << setprecision(n)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define to_decimal(bin) stoll(bin, nullptr, 2)
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Floor(n, m) (((n) / (m)) - ((n) % (m) ? 0 : 1))
#define Upper(s) transform(all(s), s.begin(), ::toupper);
#define Lower(s) transform(all(s), s.begin(), ::tolower);
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
//  ----- bits-------
#define pcnt(n) __builtin_popcount(n)
#define pcntll(n) __builtin_popcountll(n)
#define clz(n) __builtin_clz(n)    // <---100
#define clzll(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)  // 0001---->
#define ctzll(n) __builtin_ctzll(n)

using namespace std;

template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << " ";
    return out;
}

void esraa() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
int block_size;
const int N = 1e6 + 9;
vector < int > v;
int freq[N];
ll res;
struct query{
    ll l, r, idx;

    query(int l , int r , int idx){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    bool operator < (const query &other) const{
        if(l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return r < other.r;
    }
};

void add(int idx) {

}

void remove(int idx) {

}

ll get_answer() {
    return res;
}

vector < ll > MO(vector <query> queries){
    vector < ll > answers(sz(queries));
    sort(all(queries));
    int l = 0 , r = -1;
    for(auto &q : queries){
        while(r < q.r) add(++r);
        while(l > q.l) add(--l);
        while(r > q.r) remove(r--);
        while(l < q.l) remove(l++);
        answers[q.idx] = get_answer();
    }
    return answers;
}

void solve() {
    

}

int main() {
    esraa();
    int t = 1;
    // cin >> t;
    //cin.ignore();
    while (t--)
        solve();
    return 0;
}
