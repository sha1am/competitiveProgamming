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

void _print(long long t) {cerr << t;}
void _print(const string t) {cerr << t;}
//void _print(int t) {cerr << t;}
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

// // const long long INF=1e18;
// const int32_t M=1e9+7;
// const int32_t MM=998244353;
int bitSize=4;
void makeAllPossibleCombinationsUtiLRecursive(queue<int> q,vector<int> tempV, int pos,	set<vector<int>>* ansForThis2i) {
	//base condition
	if(pos==bitSize || q.empty() ) {
		//you have the vector
		if(pos==bitSize) {
			debug(tempV);
			(*ansForThis2i).insert(tempV);
		}
		return;
	}
	//main work
	// debug(q);
	// debug(tempV);
	int qSize=q.size();
	queue<int> tempQ=q;
	// int j=0;
	for(int i=pos; i<tempV.size(); i++) {
		queue<int> tempQ1=q;
		//fill in the pos the element from the queue
		int tempQFront=tempQ.front();
		tempV[i]=tempQ.front();
		// if(!tempQ.empty()) {
		// 	tempQ.pop();
		// }
		debug(tempV);

		//find the tempQ.front() element and pop that in queue and send the queue forward
		while(tempQ1.front()!=tempQFront) {
			tempQ.push(tempQ1.front());
			tempQ.pop();
		}
		//to pop front value;
		if(!tempQ.empty()) {
			tempQ.pop();
		}
		debug((int)tempQ1.size());
		debug(tempV);
		//call recursively
		makeAllPossibleCombinationsUtiLRecursive(tempQ,tempV,pos+1,ansForThis2i);

	}



}

set<vector<int>> makeAllPossibleCombinations(int numOfOnes) {
	set<vector<int>> ansForThis2i;
	vector<int> tempV(bitSize,0);
	queue<int> q;
	rep(i,0,numOfOnes) {
		q.push(1);
	}
	// rep(i,0,bitSize-numOfOnes) {
	// 	q.push(0);
	// }
	debug(q);

	makeAllPossibleCombinationsUtiLRecursive( q,tempV,0,&ansForThis2i);

	return ansForThis2i;
}

void solveUtil( int n) {
	//empty answer vector for now //size ==n
	vector<vector<int>> ans;
	// make combinations of array of size
	vector<set<vector<int>>> allPossibleVectorsWith2iOnes;

	for(int i=0; i<=2; i++) {
		allPossibleVectorsWith2iOnes.pb(makeAllPossibleCombinations(2*i));
	}
	// now we have all possible vectors with ;
	debug(allPossibleVectorsWith2iOnes);

	//
	vector<int> xorArray(bitSize,0);
}
void solve() {
	int n;
	cin>>n;

	solveUtil(n);
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// freopen("input.in", "r", stdin)c
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