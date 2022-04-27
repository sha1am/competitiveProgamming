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

// int n=1003,m=1003;
int n=12,m=12;

int xx[]= {0,0,1,-1};
int yy[]= {1,-1,0,0};


void solve() {
	//take the grid as input

	vector<char> tempV(m,'#');
	vector<vector<char>> grid(n,tempV);

	int xa,xb,ya,yb,fa,fb;

	cin>>xa>>xb;
	cin>>ya>>yb;
	cin>>fa>>fb;

	debug(xa);
	debug(xb);

	string tempS;
	// while(tempS.length()==0) {
	// 	getline(cin,tempS);

	// }
	getline(cin,tempS);
	getline(cin,tempS);

	// 	##A....#
	//	#..##..#
	//	#.##.B.#
	//	#.###..# nxm

	grid[xa-1][xb-1]='A';
	grid[ya-1][yb-1]='B';
	grid[fa-1][fb-1]='#';


	// //printGrid
	// rep(i,0,n) {
	// 	rep(j,0,m) {
	// 		cout<<grid[i][j];
	// 	}
	// 	cout<<endl;
	// }
	vector<int> tempVV(m,-1);
	vector<vector<int>> vis(n,tempVV);
	int dis=0;

	queue<pair<int,int>> q;
	q.push(make_pair(xa-1,xb-1));

	while(!q.empty()) {
		//mark this one as visited.
		vis[q.front().fr][q.front().sc]=0; // !=-1
		debug(q);
		//push all the neighbours into the queue, which are not visited till now;
		rep(i,0,4) {
			int newX=q.front().fr+xx[i];
			int newY=q.front().sc+yy[i];
			debug(newX);
			debug(newY);
			// debug(n);
			// debug(m);

			if (newX>=0 && newY>=0 && newX<n && newY<m && vis[newX][newY]==-1) {
				// debug(newX);
				// debug(newY);
				q.push(make_pair(newX,newY));
				vis[newX][newY]=dis+1;
				debug(vis[newX][newY]);
			}
		}
		q.pop();
		dis+=1;
		debug(dis);

	}

	//printGrid
	rep(i,0,n) {
		rep(j,0,m) {
			cerr<<vis[i][j];
		}
		cerr<<endl;
	}
	cerr<<"###"<<endl;



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
	string temps;
	getline(cin,temps);
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}