

// sizeof and size using a vector disparency 
#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

//Modified
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define lcm(a, b)      (a * (b / __gcd(a,b)))
#define endl			"\n" 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//clock
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

// void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(deque<T> d);
template <class T> void _print(queue<T> q);
template <class T> void _print(stack<T> s);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(deque<T> d) {cerr <<"["; while(!d.empty()) {_print(d.front()); cerr<<" "; d.pop_front();} cerr<< "]"; }
template <class T> void _print(queue<T> q) {cerr <<"["; while(!q.empty()) {_print(q.front()); cerr<<" "; q.pop();} cerr<< "]"; }
template <class T> void _print(stack<T> s) {cerr <<"["; while(!s.empty()) {_print(s.top()); cerr<<" "; s.pop();} cerr <<"]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a) {in>>a.fr>>a.sc; return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a) {out<<a.fr<<" "<<a.sc; return out;}
template<typename T,typename T1>T amax(T &a,T1 b) {if(b>a)a=b; return a;}
template<typename T,typename T1>T amin(T &a,T1 b) {if(b<a)a=b; return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
void solve(){
	string s;
	s="#fcfcfc,#5c6166,#5c6166,#fcfcfc,#5c61664d,#0099AD,#FF5792,#ffaa334d#0099AD,#FFFFFF,#8a91991a	#E7F2F3,#D8EDF0,#FFAA33,#ffaa33,#ffaa33,#fcfcfc,#8a919966,#6cbf43b3,#478accb3,#FFAA33,#ff7383b3,#036dd626,#036dd626,#00C6E0,#5696d61a,#5696d61a,#55b4d4,#ffaa33,#fcfcfc,#8a91992e,#8a919959,#8a919966,#fcfcfc4d,#787b809,#86b300,#4cbf99,#ffaa33,#ffaa33,#a37acc,#5c6166,#f07171,#55b4d4,#43AAED,#FF5792,#FF5792,#ed9366#5c6166b3,#5c6166,#ed9366,#FF5792,#FF5792,#22a4e6,#55b4d4,#FF5792,#55b4d4,#f2ae49,#a37acc,#f2ae49,#f07171,#86b300,#22a4e6,#55b4d4,#55b4d480#f2ae49,#ed9366,#55b4d4,#e6b673,#e65050,#c594c5,#f2ae49,#22a4e6,#787b8099,#55b4d4,#787b8099,#FF5792,#86b300,#e65050,#86b300,#22a4e6,#f07171,#f07171,#5c616605,#5c61660f,#5c61660f,#787b8099,#4cbf99,#f2ae49,#6cbf43,#478acc,#ff7383,#e6b673,#5c61660f,#55b4d4,#ed9366,#787b8099,#787b8099#5c6166,#787b8099";

}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// freopen("input.in", "r", stdin);
	// freopen("output.in", "w", stdout);
	start = clock();
#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
#endif

#ifdef SIEVE
	sieve();
#endif
#ifdef NCRk
	init();
#endif
	cout << fixed << setprecision(12);

	int t=1;
	//cin>>t;
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}