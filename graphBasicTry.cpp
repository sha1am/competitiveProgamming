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


//void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

//template <class T> void _print(T arr[]);
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
//template <class T> void _print(T arr[]){cerr <<"["; for( T i: arr){_print(arr[i]);cerr << " ";}cerr<<"]";}



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
void printQ(queue<int> q){
	while(!q.empty()){
		cout<< q.front();
		q.pop();
	}
	cout<<endl;
}
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
const int N=0;
 

int n=12;
vector< vector<pair<int,int> > > g(12);

void printV1(vector < pair< int, int> > v1){
    vector<pair<int ,int> > :: iterator it;
    for( it=v1.begin();it!=v1.end();it++){
        cout<<it->first<< " "<< it->second<<" "<<endl;
    }
}
void printAdjList(vector< vector< pair< int, int> > > g){
    for(int i=0;i<n;i++){
        vector<pair<int,int> > :: iterator it;
        for( it=g[i].begin();it!=g[i].end();it++){
            cout<<it->first<<" "<<it->second<<"\t";
        }
        cout<<endl;
    }
    
    cout<<endl;
    
}
//insert  adjacency list
void insertAdjList(){
	for(int i=0;i<n;i++){
		vector<pair<int,int> > v1;
		char choice;
		cout<<"Do you want to add connected verteces of vertex "<<i<<"y/n"<<endl;
		cin>>choice;
		while(choice=='y' || choice=='Y'){
			int vertex, weight;
			pair<int, int> p;
			cout<<"Enter vertex and weight "<<endl;
			cin>>vertex>>weight;
			p=make_pair(vertex,weight);
			v1.push_back(p);
			cout<<"Do you want to add more vertices for vertex no"<<i<<"(y/n)"<<endl;
			cin>>choice;

			}
		g.push_back(v1);	

	}

}
 
void solve(){
	 
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
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