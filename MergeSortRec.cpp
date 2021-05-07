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
 
const int N=0;
 void printArr(int arr[],int size){
 	for( int i=0;i<size;i++){
 		cout<<arr[i]<<" ";
 	}
 	cout<<endl;
 }
 void merge(int arr[],int low,  int mid,int  high){
 	int n=mid-low+1, m=high-(mid+1)+1;
 	debug(n);
 	debug(m);
 	int l[n],r[m];

 	// copy array in l and m
 	for(int i=0;i<n;i++){
 		l[i]=arr[low +i];
 	}
 	for( int j=0;j<m;j++){
 		r[j]=arr[mid+1+j];
 	}
 	int i=0,j=0,k=low;
 	while ( i<n && j<m){
 		if(l[i]<r[j]){
 			arr[k]=l[i];
 			i++;
 			k++;
 		}
 		else{
 			arr[k]=r[j];
 			k++;
 			j++;
 		}
 	}
 	while(i<n){
 		arr[k]=l[i];
 		i++;
 		k++;
 	}
 	while(j<m){
 		arr[k]=r[j];
 		j++;
 		k++;
 	}
 }
 void mergeSort(int arr[],int low,int high){
 	if(low<high){
 		int mid=low + (high-low)/2;
 		mergeSort(arr,low,mid);
 		mergeSort(arr,mid+1,high);
 		merge(arr,low,mid,high);
 	}

 }
void solve(){
	int arr[]={4,5,3,5,2,6,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,n-1);
	printArr(arr,n);
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