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
	int n,k;
	cin>>n>>k;

	vector<int> v(n,-1);
	map<int,int> mp;
	rep(i,0,n) {
		cin>>v[i];
		if(mp.find(v[i])!=mp.end()) {
			// the element already exits;
			mp[v[i]]+=1;
		} else {
			mp[v[i]]=1;
		}
	}

	debug(mp);

	// will keep the count of index with the size of the multiset.
	multiset<pair<int,int>> sCount;

	rep(i,0,k+1) {
		sCount.insert(make_pair(0,i));
	}
	debug(sCount);
	multiset<int> s[k+1];
	// multiset<pair<int, multiset<int>>> ss[k+1];

	map<int,int> ::iterator it=mp.begin();

	for(; it!=mp.end(); ++it) {
		if(it->sc>=k+1) {
			int kk=it->sc;
			rep(i,0,kk) {

				// check which s[i] to insert to.
				int indexToInsert=0;
				// indexToInsert=sCount.begin()->sc;
				indexToInsert=i;
				
				if(i>=(k+1)) indexToInsert=0;

				s[indexToInsert].insert(it->fr);
				debug((int)indexToInsert);
				debug(s[indexToInsert]);
				// debug(i);
				//update the count in the count fuction
				multiset<pair<int,int>> :: iterator it1=sCount.begin();
				for(; it1!=sCount.end(); it1++) {
					if(it1->sc==indexToInsert) {
						int aa=it1->fr;
						int bb=it1->sc;
						debug(aa);
						debug(bb);

						it1=sCount.erase(it1);
						debug(sCount);
						sCount.insert(make_pair(aa+1,bb));
						debug(sCount);
						break;
					}


				}
			}
			// //rest all in s[0]
			
			// rep(i,0,(kk-(k+1))){
			// 	s[]
			// }
			cerr<<"HEy"<<endl;
			//update the new count
			rep(i,0,k+1) {
				debug(s[i])

			}
			mp[it->fr]=0;
			continue;
			// it->sc=0;
			debug(mp);

		} else {
			//it->sc is whatever else (ie. 3 2 1)
			while(it->sc>0) {
				multiset<pair<int,int>> sCountTemp=sCount;
				//find 0 and remove it;
				multiset<pair<int,int>> ::iterator it1=sCountTemp.begin();
				for(; it1!=sCountTemp.end(); ++it1) {
					if(it1->sc==0) {
						sCountTemp.erase(it1);
						break;
					}
				}
				int indexToInsert=0;
				indexToInsert=sCountTemp.begin()->sc;

				s[indexToInsert].insert(it->fr);

				//update the count in the sCount

				multiset<pair<int,int>>::iterator it2=sCount.begin();
				for(; it2!=sCount.end(); ++it2) {
					if(it2->sc==indexToInsert) {
						int aa=it2->fr;
						int bb=it2->sc;
						it2=sCount.erase(it2);
						sCount.insert(make_pair(aa+1,bb));
						break;

					}

				}
				debug(it->sc);
				it->sc-=1;
				debug(it->sc);

				rep(i,0,k+1) {
					debug(s[i]);

				}

			}
		}
		debug(mp);
	}

	rep(i,0,k+1) {
		debug(s[i]);

	}
	cerr<<"Hello"<<endl;
	//now print acccordingly


	///first check if the s[1]-s[k] has equal number of elements
	bool flag=true;
	int minn=s[1].size();
	rep(i,1,k+1) {
		if(s[i].size()!=minn) flag=false;

		if(s[i].size()<minn) {
			minn=s[i].size();
		}
	}
	debug(minn);
	if(flag==false){
		//shift all extra elements to s[0];
		rep(i,1,k+1){
			while(s[i].size()!=minn){
				int aa=*s[i].begin();
				s[i].erase(s[i].find(aa));
				s[0].insert(aa);
				break;
			}
		}
	}

	rep(i,0,k+1) {
		debug(s[i]);

	}
	cerr<<"Hello#"<<endl;


	rep(j,0,n) {
		//now find v[i] is present in which multiset?
		rep(i,0,k+1) {
			if(s[i].find(v[j])!=s[i].end()) {
				//the value is present
				cout<<i<<" ";
				//delete from this multiset;
				s[i].erase(s[i].find(v[j]));
				break;
			} else {
				continue;
			}
		}
	}

	cout<<endl;



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