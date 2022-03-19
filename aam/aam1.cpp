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


#ifndef OendlINE_JUDGE
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
	// string s;
	// cin>>s;
	// debug(s);
	// cout<<"S"<<endl;
	vector<char> stringO;

	for(int i=0; i<s.length(); i++) {
		stringO.push_back(s[i]);
	}
	vector<char> stringOO=stringO;
	// debug(stringO);
	int count=0;
	int count1=0;
	//for each new i , we have to travel from the end // to get the biggest palin
	while(stringO.size()!=0) {
		char fr=stringO[0];
		//an array to mark all the characters equal to 0th char from end.
		vector<int> vis(stringO.size(),-1);
		for(int i=0; i<stringO.size(); i++) {
			if(stringO[i]==fr) vis[i]=0; // 0-possible candidate , 1- PC but visited
		}
		// debug(vis);
		bool flagForThisPalindrome=false;
		while(flagForThisPalindrome!=true) {
			for(int j=stringO.size()-1; j>=0; j--) {
				if(vis[j]==0 && stringO[j]==fr) {
					vis[j]=1; // mark this visited
					int i=0;
					int dummyI=0;
					int dummyJ=j;
					bool flagThisCase=true; // lets assume its true
					while(dummyI<dummyJ) {
						if(stringO[dummyI]!=stringO[dummyJ]) {
							flagThisCase=false;
							break;
						}
						dummyI++; dummyJ--;
					}
					// if the whole while lp gets executed without setting the flag false. delte the indexes.
					// cout<<i<<" "<<j<<endl;
					if(flagThisCase) {
						// cout<<i<<" "<<j<<endl;
						stringO.erase(stringO.begin()+i,stringO.begin()+j+1);
						flagForThisPalindrome=true;
						count+=1;
						// debug(stringO);
						break;
					}
					// debug(stringO);

				}
			}
		}

	}
	
	while(stringOO.size()!=0) {
		char lst=stringOO[stringOO.size()-1];
		//an array to mark all the characters equal to 0th char lstom end.
		vector<int> vis(stringOO.size(),-1);
		for(int i=0; i<stringOO.size(); i++) {
			if(stringOO[i]==lst) vis[i]=0; // 0-possible candidate , 1- PC but visited
		}
		// debug(vis);
		bool flagForThisPalindrome=false;
		while(flagForThisPalindrome!=true) {
			for(int i=0; i<stringOO.size(); i++) {
				if(vis[i]==0 && stringOO[i]==lst) {
					vis[i]=1; // mark this visited
					int j=stringOO.size()-1;
					int dummyI=i;
					int dummyJ=j;
					bool flagThisCase=true; // lets assume its true
					while(dummyI<dummyJ) {
						if(stringOO[dummyI]!=stringOO[dummyJ]) {
							flagThisCase=false;
							break;
						}
						dummyI++; dummyJ--;
					}
					// if the whole while lp gets executed without setting the flag false. delte the indexes.
					// cout<<i<<" "<<j<<endl;
					if(flagThisCase) {
						// cout<<i<<" "<<j<<endl;
						stringOO.erase(stringOO.begin()+i,stringOO.begin()+j+1);
						flagForThisPalindrome=true;
						count1+=1;
						// debug(stringOO);
						break;
					}
					// debug(stringOO);

				}
			}
		}

	}
	// cout<<"A"<<endl;
	// debug(count);
	// debug(count1);
	int minn=min(count, count1);
	// debug(minn);
	// return count-1;
	// return min-1;
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