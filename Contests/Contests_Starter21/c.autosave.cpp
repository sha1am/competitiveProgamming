#include "bits/stdc++.h"
// #include <cmath>
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

template<typena˛me T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a) {in>>a.fr>>a.sc; return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a) {out<<a.fr<<" "<<a.sc; return out;}
template<typename T,typename T1>T amax(T &a,T1 b) {if(b>a)a=b; return a;}
template<typename T,typename T1>T amin(T &a,T1 b) {if(b<a)a=b; return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
//
int N=11;
vector<bool> tempVec(N,false);
vector<vector<bool>> grid(N,tempVec);

// int N=11;
// vector<int> tempVec(N,0);
// vector<vector<int>> grid(N,tempVec);


int xx[]= {1,1,-1,-1};
int yy[]= {1,-1,1,-1};

int  distance(int  xo,int  yo, int  xn, int yn) {
	//find distance png coordinates
	double dx=abs(xn-xo);
	double dy=abs(yn-yo);

	return abs(dx-dy);

}

double  eucleadianDis(int x1,int y1, int x2, int y2) {

	int dx=abs(x1-x2);
	int dy= abs(y1-y2);

	double ans=-1;

	// ans= pow(dx,2) +pow(dy,2);
	// ans=pow(ans,1/2);

	ans= dx*dx + dy*dy;
	ans=sqrt(ans);
	debug(ans);

	return ans;
}


void solveUtil(int* x,int* y, int cX, int cY, double currentDistance, int gridSize) {

	// go along diagonals if distance <= currentDistance and the point is not travelled yet.

	//get values of x , y in temp variables
	// int tempX=*x,tempY=*y;
	vector<pair<double,pair<int,int>>> validDistancesWithCoordinates;
	for(int i =0; i<4; i++) {
		//hit and trail
		int tempX=*x+xx[i];
		int tempY=*y+yy[i];

		//now check distance
		double currentDisFori=eucleadianDis(tempX,tempY,cX,cY);

		if(currentDisFori<=currentDistance && (tempX<gridSize && tempY<gridSize && tempX>=0 && tempY>=0) && grid[tempX][tempY]!=true) {

			validDistancesWithCoordinates.pb(make_pair(currentDisFori,make_pair(tempX,tempY)));
		}
	}

	//sort the valid distance array

	sort(validDistancesWithCoordinates.begin(),validDistancesWithCoordinates.end());
	debug(validDistancesWithCoordinates);

	if(validDistancesWithCoordinates.size()==0) {
		//print the distance abs(x-y);
		int ans= abs(abs(*x-cX)-abs(*y-cY));
		cout<<ans<<endl;
	} else {
		//update the x, y coordinate, ie move the person
		*x=validDistancesWithCoordinates[0].sc.fr;
		*y=validDistancesWithCoordinates[0].sc.sc;

		//update the current distance now
		currentDistance=validDistancesWithCoordinates[0].fr;

		//mark visited
		grid[*x][*y]=true;
		// grid[*x][*y]=1;

		//call recursively
		solveUtil(x,y,cX,cY,currentDistance,gridSize);

	}

	//if cannot move along the daigonals with getting the same distance or < distance
	// then print the ans;

}

void solve() {

	// reset global variables

	vector<vector<bool>> grid1(N,tempVec);
	// grid.clear();
	grid=grid1;

	// vector<int> tempVec1(N,0);
	// vector<vector<int>> grid1(N,tempVec1);

	// // grid.clear();
	// grid=grid1;





	// vector<bool> v;
	// ___typeFun(v);

	int n=-1,x=-1,y=-1;
	int centerX=-1;
	int centerY=-1;
	cin>>n>>x>>y;


	centerX=(n+1)/2;
	centerY=(n+1)/2;

	debug(centerX);
	debug(centerY);
	debug(x);
	debug(y);

	//decrease everything to match 0- n-1;
	x-=1;
	y-=1;
	centerX-=1;
	centerY-=1;

	solveUtil(&x,&y,centerX,centerY,eucleadianDis(x,y,centerX,centerY),n);


	// //print Grid
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout<<grid[i][j];
	// 	}
	// 	cout<<endl;
	// }


	// cout<<ans<<endl;
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