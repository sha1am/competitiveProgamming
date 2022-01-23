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

int bitSize=4;

vector<vector<vector<int>>> globalVBinary;
vector<vector<int>> globalVDecimal;

bool xorSumEvenOrNot(vector<vector<int>> vv) {
	bool flag=false;
	int sum=0;
	rep(i,0,vv.size()) {
		int thisBitXor=vv[i][0];
		rep(k,1,bitSize) {
			thisBitXor=thisBitXor ^ vv[i][k];
		}
		sum+=thisBitXor;
		// debug(sum);

	}
	// debug(sum);
	if(sum%2==0) {
		flag=true;
	}

	return flag;
}
int convertBinaryToNum(vector<int> v) {

	int sumB=0;
	rep(i,0,bitSize) {
		int a=pow(2,i);
		if(v[i]==1) {
			sumB+=a;
		}
	}
	debug(sumB);
	return sumB;
}

void recursiveSolve(vector<vector<int>> vv,int posvvStart,int posvvEnd,int sum) {
	//base condition
	if(posvvStart==posvvEnd+1) {
		//now take and print all all if sum is even;
		rep(i,0,vv.size()) {
			// debug(vv[i]);
		}
		cerr<<endl;
		if(xorSumEvenOrNot(vv)) {
			//then push the vector into a vector of vvi;
			// globalVBinary.pb(vv);
		}

		return;
	}

	//real work
	// vector<vector<int>> tempVV1=vv;
	// vector<vector<int>> tempVV2=vv;

	// for fill possvv vector in vector<vector<int>>
	// fill this whole vector in vvi
	rep(i,0,bitSize) {
		//just to fill 0,1 in i-th pos recusviely2
		// debug(posvvStart);
		// for(int j=0; j<2; j++) {
		int sumTemp=sum;

		vv[posvvStart][i]=0;
		recursiveSolve(vv,posvvStart+1,posvvEnd,sumTemp);
		vv[posvvStart][i]=1;
		// debug(j)
		// debug(vv[posvvStart]);
		// debug(vv[posvvStart][i]);
		debug(vv);
		// if(j==1) sumTemp+=1;

		// debug(vv);

		//now leave this and solve all from posvvStart+1--posvvEnd;
		recursiveSolve(vv,posvvStart+1,posvvEnd,sumTemp);

		cerr<<"####"<<endl;

		// }

		// cerr<<"i"<<i<<"filled"<<endl;
	}

}
void solveUtil(int n) {
	//to represent a number in 4 bits
	vector<int> v(bitSize,0);
	vector<vector<int>> vv(n,v);
	debug(vv);
	int pos=0;
	int sum=0;
	rep(i,0,n) {
		recursiveSolve(vv,0,i,sum);

	}

	//now we have all our vectors in glbalV

	// cout<<"Shadab"<<endl;

	debug(globalVBinary);
	// vector<int> vvV={1,1,0,0};
	// convertBinaryToNum(vvV);

	//convert this into numbers

	rep(i,0,globalVBinary.size()) {
		vector<int> tempV;
		rep(j,0,globalVBinary[i].size()) {
			int a=convertBinaryToNum(globalVBinary[i][j]);
			tempV.pb(a);

		}
		debug(tempV);
		globalVDecimal.pb(tempV);
	}


}

void solve() {
	int n=2;
	cin>>n;

	//generate all permutations of 32 sized [1,0,1,1,1....];
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