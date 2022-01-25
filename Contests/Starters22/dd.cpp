
// worked but time complexity is off the power of npr 1000!/500!

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
int bitSize=20;
pair<bool,vector<int>> checkThisVector(vector<int> xorArray,vector<int> vec) {
	vector<int> newXorArrayTemp(bitSize,-1);
	bool flag=false;
	int sum=0;
	rep(i,0,bitSize) {
		newXorArrayTemp[i]=xorArray[i]^vec[i];
		sum+=newXorArrayTemp[i];
	}
	if(sum%2==0)flag=true;
	pair<bool,vector<int>> checkResult=make_pair(flag,xorArray);
	return checkResult;

}
void checkWhichWillWork(vector<int>* xorArray,vector<set<vector<int>>>*  allPossibleVectorsWith2iOnes,vector<vector<int>>* ans) {

	rep(i,0,(*allPossibleVectorsWith2iOnes).size()) {
		rep(j,0,(*allPossibleVectorsWith2iOnes)[i].size()) {
			//iterate this set ( ie. allPossibleVectorsWith2iOnes[i])
			set<vector<int>> ::iterator it;
			for(it=(*allPossibleVectorsWith2iOnes)[i].begin(); it!=(*allPossibleVectorsWith2iOnes)[i].end(); it++) {
				//if this is included , size must increase by 0 or 2
				if(checkThisVector((*xorArray),*it).fr) {
					//update new XorArray
					(*xorArray)=checkThisVector((*xorArray),*it).sc;
					//add this vector to ans;
					(*ans).pb(*it);
					//delete this vector from the vector<set<vector<int>>>
					it=(*allPossibleVectorsWith2iOnes)[i].erase(it);

					// end this function 
					return;

				}

			}

		}
	}
}

void makeAllPossiblePermutationsUtiLRecursive(queue<int> givenElementsQ,int r, vector<int> tempV,int sPos, int ePos, int pos,set<vector<int>>* ansForThis2i) {

	//base condition
	if(pos==r) {
		//you have the vector here;
		// debug(tempV);
		(*ansForThis2i).insert(tempV);
		return;
	}

	//main taks
	vector<int> dummyVForIteration;
	queue<int> dummyQ0=givenElementsQ;
	while(!dummyQ0.empty()) {
		dummyVForIteration.pb(dummyQ0.front());
		dummyQ0.pop();
	}

	for(int i=0; i<dummyVForIteration.size(); i++) {
		queue<int> dummyQ1=givenElementsQ;
		tempV[pos]=dummyVForIteration[i];

		// now find this pos in dummyQ1 and delete it and send for next pos;
		while(dummyQ1.front()!=dummyVForIteration[i]) {
			dummyQ1.push(dummyQ1.front());
			dummyQ1.pop();
		}
		if(!dummyQ1.empty()) {
			dummyQ1.pop();
		}


		makeAllPossiblePermutationsUtiLRecursive(dummyQ1,r,tempV,sPos,ePos,pos+1,ansForThis2i);
		while(i!=ePos && dummyVForIteration[i]==dummyVForIteration[i+1]) {
			i++;
		}
	}



}

set<vector<int>> makeAllPossiblePermutations(int numOfOnes) {
	set<vector<int>> ansForThis2i;
	vector<int> tempV(bitSize,-1);
	queue<int> givenElementsQ;

	rep(i,0,numOfOnes) {
		givenElementsQ.push(1);
	}
	rep(i,0,bitSize-numOfOnes) {
		givenElementsQ.push(0);
	}

	vector<int> tempVForSorting;
	while(!givenElementsQ.empty()) {
		tempVForSorting.pb(givenElementsQ.front());
		givenElementsQ.pop();
	}
	sort(tempVForSorting.begin(),tempVForSorting.end());

	rep(i,0,tempVForSorting.size()) {
		givenElementsQ.push(tempVForSorting[i]);
	}

	debug(givenElementsQ);
	makeAllPossiblePermutationsUtiLRecursive(givenElementsQ,bitSize,tempV,0,givenElementsQ.size()-1,0,&ansForThis2i);

	return ansForThis2i;
}

void solveUtil( int n) {
	//empty answer vector for now //size ==n
	vector<vector<int>> ans;
	// make Permutations of array of size
	vector<set<vector<int>>> allPossibleVectorsWith2iOnes;

	for(int i=0; i<=bitSize/2; i++) {
		allPossibleVectorsWith2iOnes.pb(makeAllPossiblePermutations(2*i));
	}
	// now we have all possible vectors with ;
	debug(allPossibleVectorsWith2iOnes);

	//
	vector<int> xorArray(bitSize,0);

	while(ans.size()!=n) {
		checkWhichWillWork(&xorArray,&allPossibleVectorsWith2iOnes,&ans);
	}
	//now we have answer;
	debug(ans);
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