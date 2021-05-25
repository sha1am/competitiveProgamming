#include "bits/stdc++.h"
using namespace std;
//#define int               long long
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


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
const int N=1000000;
int n,m;
vector<int> adj[N];
vector<int> col(N,-1);
vector<bool>pushedIntoQueueOnce(N,0);
 
void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x-=1;
		y-=1;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;
	int max=0;

	for(int i=0;i<n;i++){
		if(pushedIntoQueueOnce[i])continue;
		q.push(i);
	//col[0]=1;
	pushedIntoQueueOnce[i]=1;
	//int max=0;
		while(!q.empty()){
		int parentVertex=q.front();
		debug(parentVertex);
		q.pop();

		for(int i=1;;i++){
			bool flag=true;
			for(int x: adj[parentVertex]){
				//cout<<"a1"<<endl;
				if(col[x]==i)flag=false;
				//cout<<"a"<<endl;
				
			}
			if(flag==true){
				col[parentVertex]=i;
				//cout<<"b"<<endl;
				if(i>max)max=i;
				break;
			}
		}

		for(int x: adj[parentVertex]){
			debug(x);
			if(pushedIntoQueueOnce[x])continue;
			q.push(x);
			pushedIntoQueueOnce[x]=1;
		}
	}
	}
	

	debug(max);

	if(max==2){
		for(int i=0;i<n;i++){
			cout<<col[i]<<" ";
			}
	}
	else cout<<"IMPOSSIBLE"<<endl;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
    #endif
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}