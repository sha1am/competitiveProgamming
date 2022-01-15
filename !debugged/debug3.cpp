

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

deque<pair<int,int>> reverseQ(deque<pair<int,int>> q) {
	stack<pair<int,int>> s;

	while(!q.empty()) {
		s.push(q.front());
		q.pop_front();
	}

	while(!s.empty()) {
		q.push_back(s.top());
		s.pop();
	}

	// debug(q);
	return q;
}

void solve() {

	deque<pair<int,int>> q;
	q.push_back(make_pair(1,11));
	q.push_back(make_pair(0,10));
	q.push_back(make_pair(1,9));
	q.push_back(make_pair(0,8));
	q.push_back(make_pair(0,7));
	q.push_back(make_pair(1,6));
	q.push_back(make_pair(1,5));
	q.push_back(make_pair(0,4));
	q.push_back(make_pair(1,3));
	q.push_back(make_pair(1,2));
	q.push_back(make_pair(1,1));
	q.push_back(make_pair(0,0));

	//reverse q

	stack<pair<int,int>> s;

	while(!q.empty()) {
		s.push(q.front());
		q.pop_front();
	}

	while(!s.empty()) {
		q.push_back(s.top());
		s.pop();
	}

	debug(q);

	int count1=0;
	int count0=0;
	deque<pair<int,int>> tempQ;
	while(!q.empty()) {

		if(q.front().fr==0) {
			while(q.front().fr==0) {
				q.pop_front();
				count0++;
			}

			if(count1!=0) {
				//there were ones before; they'd be int the tempQ;
				//print the indexes whos power must be increased by count0
				tempQ=reverseQ(tempQ);
				//increase all indexes
				debug(count0);
				debug(tempQ);
				while(!tempQ.empty()) {
					cerr<<"index"<<tempQ.front().sc<<endl;
					q.push_front(make_pair(tempQ.front().fr,tempQ.front().sc+count0));
					tempQ.pop_front();
				}
				cout<<endl;
				count1=0;
				debug(q);
			}
		}

		if(q.front().fr==1) {
			while(q.front().fr==1) {
				tempQ.pb(q.front());
				q.pop_front();
				count1++;
			}
			count0=0;
		}
		//deal with tempQ

		debug(q);
	}


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