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
// mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(deque<T> d);
template <class T> void _print(queue<T> q);
template <class T> void _print(stack<T> s);
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
const long long minINF=-1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
int N=100002;
void solve() {
	int n;
	cin>>n;

	vector<int> v(n,-1);
	rep(i,0,n) {
		cin>>v[i];
	}

	debug(v);

	//(  for ascending and ) for descending
	char prevCh='x';
	char currCh='x';
	if(v[0]<=v[1]) {
		prevCh='(';
		currCh='(';
	} else
		if(v[0]>v[1]) {
			currCh=')';
			prevCh=')';
		}

	//vector of vectors
	vector<vector<int>> vv;
	vector<int> tempV;
	tempV.pb(v[0]);
	for(int i=1; i<n; i++) {
		debug(v[i]);
		debug(prevCh);
		debug(currCh);
		if(v[i]<=v[i+1]) {
			//ascending is
			currCh='(';
		} else
			if(v[i]>v[i+1]) {
				currCh= ')';
			}

		debug(prevCh);
		debug(currCh);
		if(prevCh==currCh) {
			//let it run
			tempV.pb(v[i]);
		}

		else {
			// now the sequence has changed ,
			//push the temporary variable into vv
			tempV.pb(v[i]);
			vv.pb(tempV);
			//clear the temprorary array
			tempV.clear();
			//
			tempV.pb(v[i]);

			//update the last curr
			prevCh=currCh;

		}

		debug(tempV);
		// debug(v[i]);

		if(i==(n-1)) {
			vv.pb(tempV);
		}


	}


	debug(vv);
	// int max=minINF;
	int maxx=-222;
	rep(i,0,vv.size()) {
		sort(vv[i].begin(),vv[i].end(),greater<int>());
		if(vv[i].size()>=2) {
			maxx= max(maxx,vv[i][0]*vv[i][1]);

		}
	}
	cout<<maxx<<endl;
	debug(vv);
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
	cin>>t;
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}