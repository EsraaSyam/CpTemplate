#include<bits/stdc++.h>
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

template < typename T = int > istream& operator >> (istream &in, vector < T > & v){
    for(auto & x : v) in >> x;
    return in;
} 

template < typename T = int > ostream& operator << (ostream &out, const vector < T > & v){ 
    for(const T & x : v) out << x << " "; 
    return out;
}

void esraa()
{
    //freopen("shuffle.in", "r", stdin), freopen("shuffle.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
int n , m;
vector < vector < pair < ll , ll > > > adj;
vector < ll > dist;
vector < int > prv;
void dijkstra(int src){
    dist.assign(n + 1 , 1e18);
    prv.assign(n + 1 , -1);
    priority_queue < tuple < ll , int , int > , vector < tuple < ll , int , int > > , greater < > > pq;
    pq.emplace(0 , -1 , src);
    dist[src] = 0;
    while(!pq.empty()){
        auto [w , from , to] = pq.top();
        pq.pop();
        if(w > dist[to]) continue;
        prv[to] = from;
        for(auto & [u , d] : adj[to]){
            if(dist[u] > w + d){
                pq.emplace(w + d , to , u);
                dist[u] = w + d;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.assign(n + 1 , vector < pair < ll , ll > >());
    for(int i = 0; i < m; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
    dijkstra(1);
    if(!~prv[n]) return cout << -1 << nl , void();
    stack < int > st;
    int cur = n;
    while(cur != -1){
        st.push(cur);
        cur = prv[cur];
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << nl;
    
    
}
int main()
{
    esraa();
    int t = 1;
    //cin >> t;
    //cin.ignore();
    while(t--)
      solve();
    return 0;
}
