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


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


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
 
const int N=105;

int z=30,n=202,m=2002;
// for storing the vectors of strings
vector<string> tempV;
vector<vector<string>> u(z,tempV);


// for making the matrix
vector<string> tempV1(m+1,"");
vector<vector<string>> t(n+1,tempV1);


vector<string> lcs(string a, string b, int n ,int m){

	//initialiazation
	rep(i,0,n+1){
		rep(j,0,m+1){
			if(i==0||j==0) t[i][j]="";
		}
	}
	u[0].pb("#");

	//choice daigram 
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(a[i-1]==b[j-1]) {
				t[i][j]=t[i-1][j-1]+a[i-1];
				//char add=a[i-1];
				
				//u[t[i-1][j-1].length()] me a[i-1] add;
				int k=t[i-1][j-1].length();
				debug(k);
				

				rep(i,0,u[k].size()){

					//debug(add);
					debug(u[k][i]);
					u[k][i]+=a[i-1];
					debug(a[i-1]); 
					debug(u[k][i]);
					u[k+1].pb(u[k][i]);

					
				}

			}
			else{
				//t[i][j]=max(t[i][j-1],t[i-1][j]);
				t[i][j]=t[i-1][j].length()>t[i][j-1].length()?t[i-1][j]:t[i][j-1];


			}
		}
	}
	int sz=t[n][m].length();

	return u[sz];
}


void solve(){
	
	string a,b;
	cin>>a>>b;
	int n=a.length(),m=b.length();
	vector<string> ans= lcs(a,b,n,m);

	sort(ans.begin(),ans.end());
	// rep(i,0,ans.size()){
	// 	cout<<ans[i]<<endl;
	// }
	// cout<<endl;
	//cout<<5<<endl;

	// //print u
	rep(i,0,28){
		rep(j,0,u[i].size()){
					cout<<u[i][j]<<"$";
				}
		cout<<endl;
	}

	//print matrix t
	rep(i,0,n+1){
		rep(j,0,m+1){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}


	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
    #endif
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}