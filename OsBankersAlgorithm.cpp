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
//
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define lcm(a, b)      (a * (b / __gcd(a,b))) 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//clock 
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

void _print(long long t) {cerr << t;}
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
template <class T> void _print(deque<T> d){cerr <<"["; while(!d.empty()){_print(d.front());cerr<<" "; d.pop_front();}cerr<< "]"; }
template <class T> void _print(queue<T> q){cerr <<"["; while(!q.empty()){_print(q.front());cerr<<" "; q.pop();}cerr<< "]"; }
template <class T> void _print(stack<T> s){cerr <<"["; while(!s.empty()){_print(s.top());cerr<<" "; s.pop();} cerr <<"]";}
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
 



void solve(){
	
 int n=5,m=3; //number of processes and m num of resources n=5,m=3
 //cin>>n>>m;

 vector<int> ans;

 //available 
 vector<int> avail(m,0); // get input of total available resources initially

 //update available resources
 avail={3,3,2};
 

 //Max 
 vector<int> tempV(m,-1);
 vector<vector<int>> mmax(n,tempV);
 mmax={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};

 //allocation 
 vector<vector<int>> allocated(n,tempV);
 allocated= {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};

 //Need 
 vector<vector<int>> need(n,tempV);//mmax-allocation

 rep(i,0,n){
 	rep(j,0,m){
 		need[i][j]=mmax[i][j]-allocated[i][j];
 	}
 }

 // application of safety algo.

 vector<bool> finished(n,false);
 bool allFinished=false;

 queue<int> q;

 rep(i,0,n){
 	q.push(i);
 }
debug(q);
 while(!q.empty()){

 	if(finished[q.front()]!=true){

 		//check if need is less than 
 		bool flag0=true;
 		for(int i=0;i<m;i++){
 			if(need[q.front()][i]>avail[i]) flag0=false;
 		}
 		debug(q.front());
 		debug(flag0);

 		if(flag0){

 		finished[q.front()]=true;
 		

 		//avail+=allocated after the process completes
 		rep(i,0,m){
 			avail[i]+=allocated[q.front()][i];
 		}

 		ans.push_back(q.front());
 		q.pop();
 		}

 		else{
 			q.push(q.front());
 			q.pop();
 		}

 	}

 }


//Print the safe sequence
 cout<<"The safe sequence is"<<endl; 
 rep(i,0,n){
 	cout<<"P"<<ans[i]<<" ";
 }

	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	start = clock(); 
	#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
    #endif
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	cout << fixed << setprecision(12);
	
	int t=1;
	//cin>>t;
	while(t--) solve();
	cerr << time(start);
	return 0;
}