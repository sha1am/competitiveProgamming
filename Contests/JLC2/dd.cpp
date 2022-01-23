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

int numOfMoves=0;
struct box {
	int c[3];
};

struct boxSet {

	multiset<int> msF;
};
bool checkIfTheBoxesAreGood(struct boxSet bS[]) {
	//size is always three
	//check if no boxes has any foreigners
	bool flag=true;
	rep(i,0,3) {
		if(bS[i].msF.size()!=0) {
			//means there are still some foriegners
			flag=false;
		}
	}
	cerr<<"Flag"<<flag<<endl;
	// debug((bool)flag);
	return flag;
}
void exhangeForiegnersLeanently(struct boxSet *bS) {
	//tc can be n^3 ie 1000^3
	rep(i,0,3) {
		//check for all boxes i=0,1 2
		// iterator in this bS[i].msF
		multiset<int>::iterator it;
		for(it=bS[i].msF.begin(); it!=bS[i].msF.end();) {
			int a=*it;
			//find this number in corresponding box bS[a].msF
			//do this process ,when both are mutually into one another
			if(bS[a].msF.find(i)!=bS[a].msF.end() && bS[i].msF.find(a)!=bS[i].msF.end()) {
				//means the element is there and can be exchanged leanenly // will cost me one operation
				//delete element int that
				debug(i); debug(a);
				debug(bS[i].msF);

				//increment steps +1
				numOfMoves+=1;
				cerr<<"numOfMovesInLineant"<<endl;
				debug(numOfMoves);
				debug(bS[a].msF);
				auto it1=bS[a].msF.find(i);
				if(it1!=bS[a].msF.end()) {
					bS[a].msF.erase(it1); //deletes single instance

				}
				// erase the element who's corresponding element is there is this i
				multiset<int>::iterator it2=bS[i].msF.find(a);
				{
					// the both iterators it and it2 are pointing to the same location then take care
					// iterator can be nullified.
					//NOt sure about this *************
					if(it==it2) {
						it=bS[i].msF.erase(it);
					} else {
						//delete and increase it
						bS[i].msF.erase(it2);
						++it;

					}
				}
				debug(bS[i].msF);
				debug(bS[a].msF);
				//delete element in this one too

				cerr<<"hey"<<endl;

			} else {
				//do nothing
				++it;
			}
		}
	}
}
void exhangeForiegnersStrictly(struct boxSet *bS) {
	//tc can be n^3 ie 1000^3
	bool flag=false;
	set<int> s= {0,1,2};
	rep(i,0,3) {
		//check for all boxes i=0,1 2
		s.erase(i);

		//entry debug
		//debug
		cerr<<"strictStart"<<endl;
		rep(i,0,3) {
			debug(bS[i].msF);
		}

		//iterate through this set
		set<int>::iterator it;
		for(it=s.begin(); it!=s.end(); ++it) {
			debug(*it);
			//check for this i's countries kid in others
			while(bS[*it].msF.find(i)!=bS[*it].msF.end()) {

				flag=true;
				//to make sure to take all the childrens of this country
				multiset<int>::iterator it1=bS[*it].msF.find(i);
				//delete the elemet correspondign to this iterator it1
				int a=*it1;
				debug(a);
				it1=bS[*it].msF.erase(it1); //it has changed **** // not erase because this is not an exchange operation
				//now exchanging becaue of using lineantFunction

				//exchange with any random not required foreigner of this country
				multiset<int>::iterator it2=bS[i].msF.begin(); ///idk
				// int toDelNum=*it2;
				bS[*it].msF.insert(*it2); //del kro bhai
				//now delete from this one
				bS[i].msF.erase(it2);

				//increase number of moves by 1;
				numOfMoves+=1;
				cerr<<"numOfMovesInStrict"<<endl;
				debug(numOfMoves);

				//debug
				rep(i,0,3) {
					debug(bS[i].msF);
				}
				if(flag==true) break;
			}
			if(flag==true) break;

		}
		if(flag==true) break;
	}

	cerr<<"strictEnd"<<endl;
	if(checkIfTheBoxesAreGood(bS)!=true) {
		//try solving lineantly
		exhangeForiegnersLeanently(bS);
	}

}

void solve() {

	//reset global variable for each test case
	numOfMoves=0;

	int n;
	cin>>n;
	//not used till now
	struct box bO[3];

	rep(i,0,3) {
		cin>>bO[i].c[0]>>bO[i].c[1]>>bO[i].c[2];
	}

	// rep(i,0,3) {
	// 	cout<<bO[i].c[0]<<bO[i].c[1]<<bO[i].c[2]<<endl;
	// }
	map<int,char> mp;
	mp.insert(make_pair(0,'r'));
	mp.insert(make_pair(1,'g'));
	mp.insert(make_pair(2,'b'));

	//succesfully entered
	struct boxSet bS[3];
	rep(i,0,3) {
		//for each box find the foriegners
		rep(j,0,3) {
			if(i!=j) {
				rep(k,0,bO[i].c[j]) {
					bS[i].msF.insert(j);
				}
			}
		}
	}

	//print foriegner for each box
	rep(i,0,3) {
		debug(bS[i].msF);
	}

	if(checkIfTheBoxesAreGood(bS)==1) {
		//this is okay //print 0
		cout<<0;
	} else {
		//first try exchange such foreigner that in one step both is at home.
		exhangeForiegnersLeanently(bS);
		cerr<<"lineantCheckingDone"<<endl;

		//lets see the changes are permanent or not?
		rep(i,0,3) {
			debug(bS[i].msF);
		}
		debug(numOfMoves);

		//check if the boxes are good or not //if not now exchangeForigners
		if(checkIfTheBoxesAreGood(bS)) {
			//from linear checking
			cout<<numOfMoves;
		} else {
			//could be returned a calculated number . but lemme hit and trail
			// numOfMoves+=(bS[0].msF.size())*2;

			while(!checkIfTheBoxesAreGood(bS)) {
				exhangeForiegnersStrictly(bS);
			}
			if(checkIfTheBoxesAreGood(bS)) {
				//printResult
				cout<<numOfMoves;
			} else {
				cout<<""<<endl;
			}
		}
		// cout<<numOfMoves;
	}

	rep(i,0,3) {
		debug(bS[i].msF);
	}

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
	while(t--) {
		solve();
		if(t!=0) {
			cout<<endl;
		}
	}
	cerr <<"Time Taken: "<<time(start);
	return 0;
}