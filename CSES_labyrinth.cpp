#include "bits/stdc++.h"
using namespace std;
//#define int               long long
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
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
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
 
const int N=1005;

int n,m;
//vector<vector<int>> vis;
//int distancee[N][N];
vector<int> v(N,0);
vector<vector<int>> distancee(N,v);
int ax,ay,bx,by;
bool pushedIntoQueueOnce[N][N];
//vector<pair<int,int>> prev[N]();
//pair<int,int> prevv[N][N];
vector<pair<int,int>> v1(N,make_pair(-1,-1));
vector<vector<pair<int,int>>> prevv(N,v1);

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool check(int x,int  y){
	if(x<0 || y<0||x>=n||y>=m || pushedIntoQueueOnce[x][y] ){
		return false;
	}
	else return true;
}

void solve(){
	cin>> n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='#'){
				pushedIntoQueueOnce[i][j]=1;
			}
			if(s[j]=='A'){
				ax=i;
				ay=j;
			}
			if(s[j]=='B'){
				bx=i;
				by=j;
			}
		}
	}
	/*for( int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<< pushedIntoQueueOnce[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/

	queue<pair<int,int>> q;
	q.push(make_pair(ax,ay));
	pushedIntoQueueOnce[ax][ay]=true;
	distancee[ax][ay]=0;
	prevv[ax][ay]=make_pair(-1,-1);

	while(!q.empty()){
		pair<int,int > p=q.front();
		q.pop();
		//debug(p);

		for(int i=0;i<4;i++){
			int X,Y;
			X=p.first+dx[i];
			Y=p.second+dy[i];
			if(!check(X,Y))continue;
			q.push(make_pair(X,Y));
			pushedIntoQueueOnce[X][Y]=1;
			distancee[X][Y]=distancee[p.first][p.second]+1;
			prevv[X][Y]=make_pair(p.first,p.second);

		}

	}

	//pair<int, int> path[distancee[bx][by]];
	vector< pair<int,int> > path;
	path.clear();
	 //int i=0;
	//print distance array
	/*
	for( int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<< distancee[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	
	for( int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"("<<prevv[i][j].fr<<","<<prevv[i][j].sc<<")"<<" ";
		}
		cout<<endl;
	}*/
	if(distancee[bx][by]==0){
		cout<<"NO"<<endl;
		
	}
	else{
		cout<<"YES"<<endl;
		cout<<distancee[bx][by]<<endl;


		for(pair<int,int> at=make_pair(bx,by);at!=make_pair(-1,-1);at=prevv[at.first][at.second]){
		path.push_back(at);
			}


	reverse(path.begin(),path.end());
	if(path[0]==make_pair(ax,ay)){
		/*for(vector<pair<int,int>> ::iterator it=path.begin();it!=path.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
		cout<<endl;*/

		int delX,delY,x=path[0].fr,y=path[0].sc;
		queue<char> q1;

		for(vector< pair<int,int>> ::iterator it=path.begin()+1;it!=path.end();it++){
			delX=it->sc-y;
			delY=it->fr -x;
			x=it->fr;
			y=it->sc;
			if(delX==-1 && delY==0)q1.push('L');
			if(delX==+1 && delY==0)q1.push('R');
			if(delX==0 && delY==1)q1.push('D');
			if(delX==0 && delY==-1)q1.push('U');
		}

		while(!q1.empty()){
			cout<<q1.front();
			q1.pop();
		}
		
	}

	}

	
	
	


	/*
	for( int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<< pushedIntoQueueOnce[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	*/

	
	
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
	//cin>>t;
	while(t--) solve();
	return 0;
}