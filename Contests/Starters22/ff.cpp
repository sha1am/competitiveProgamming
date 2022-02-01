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
// #define endl			"\n"


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

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;


void solve() {


	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;


	//store the string in a vector
	queue<int> qA;
	queue<int> qB;

	rep(i,0,n) {
		qA.push(a[i]-'0');
	}
	rep(i,0,n) {
		qB.push(b[i]-'0');
	}
	debug(qA);
	debug(qB);


	vector<int> ans;

	//count number of zeros
	int cntLZ=0;
	while(qA.front()==0) {
		cntLZ+=1;
		qA.pop();
	}
	while(qB.front()==0) {
		cntLZ+=1;
		qB.pop();
	}

	//we have all leading zeros
	rep(i,0,cntLZ) {
		ans.pb(0);
	}
	debug(ans);
	debug(qA);
	debug(qB);



	//keep track of all 1s with number of zeros after them
	queue<int> qAOnes;
	queue<int> qBOnes;

	while(!qA.empty()) {
		if(qA.front()==1 ) {
			//now pop this and count zeros
			qA.pop();
			int cntZerosCurrent=0;
			while(!qA.empty() && qA.front()==0) {
				cntZerosCurrent+=1;
				qA.pop();
			}
			//now we have all zeros for this 1
			qAOnes.push(cntZerosCurrent);

		}
	}
	debug(qAOnes);
	while(!qB.empty()) {
		if(qB.front()==1) {
			//now pop this and count zeros
			qB.pop();
			int cntZerosCurrent=0;
			while(!qB.empty() && qB.front()==0) {
				cntZerosCurrent+=1;
				qB.pop();
			}
			//now we have all zeros for this 1
			qBOnes.push(cntZerosCurrent);

		}

	}
	debug(ans);
	debug(qAOnes);
	debug(qBOnes);
	//now check which qX front has greater number of zeros and add them to the answer;
	bool flag=true;
	while(!qAOnes.empty() || !qBOnes.empty()) {
		debug(qAOnes);
		debug(qBOnes);

		if(qBOnes.empty() || qAOnes.empty()) {
			// we either need to print one of them fully into the ans;
			while(!qBOnes.empty()) {
				ans.pb(1);
				rep(i,0,qBOnes.front()) {
					ans.pb(0);
				}
				qBOnes.pop();
			}
			while(!qAOnes.empty()) {
				ans.pb(1);
				rep(i,0,qAOnes.front()) {
					ans.pb(0);
				}
				qAOnes.pop();
			}
		} else {
			if(qBOnes.front()>qAOnes.front()) {
				flag=false;

			} else
				if(qBOnes.front()==qAOnes.front()) {

					if(checkSet(qAOnes,qBOnes)) {
						flag=false;
						// sBG.pop();
					} else {
						// sAG.pop();
					}
				}


			if(flag) {
				ans.pb(1);
				rep(i,0,qAOnes.front()) {
					ans.pb(0);
				}
				qAOnes.pop();
			} else {
				ans.pb(1);
				rep(i,0,qBOnes.front()) {
					ans.pb(0);
				}
				qBOnes.pop();
			}
			debug(ans);

		}
	}

	//print ans ;
	debug(ans);

	int cntOfOnesTillNow=0;
	int cntOfInv=0;
	rep(i,0,ans.size()) {
		if(ans[i]==1) cntOfOnesTillNow+=1;
		else {
			cntOfInv+=cntOfOnesTillNow;
		}
	}

	cout<<cntOfInv<<endl;

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