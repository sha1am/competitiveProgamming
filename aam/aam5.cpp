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
// #define debug(x)
#else
// #define debug(x)
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
 
// const long long INF=1e18;
// const int32_t M=1e9+7;
// const int32_t MM=998244353;
 
int bitSize=101;
vector<int> convertToBase2(int n) {
	vector<int> tempV(bitSize,0);
	int i=0;
	while(n!=0) {
		int rem=n%2;
		n/=2;
		tempV[i]=rem;
		i++;
	}
	// debug(tempV);
	return tempV;
}
 
int msb(vector<int> v) {
	int index=-1;
	for(int i=0; i<v.size(); i++) {
		if(v[i]==1)index=i;
	}
	// debug(index);
	return index;
}
int cntMSB(vector<int> v1,vector<int> v2,int smsb1, int smsb2) {
	int num=0;
	int cnt=0;
	for(int i=v1.size()-1; i>=0; i--) {
		if(v1[i]==1 && v2[i]==1) {
			cnt++;
			// int a=pow(2,i);
			int a=(long long)1<<i;
			num+=a;
 
		}
		// else if(v1[i]==1 && v2[i]==0) cnt++; // this will never be case, because first only we checked
		else
			if((v1[i]==0 && i<=smsb2)&& (i!=0 && v1[i-1]==1) ) {
				// int a=pow(2,i);
				// debug(i);
				int a=(long long)1<<i;
				// debug(a);
				num+=a;
				cnt++;
				break;
			} else
				if(v1[i]==0 && v2[i]==0) { //do nothing
				}
		// debug(num);
 
	}
	// debug(cnt);
	// debug(num);
	return num;
}
int nsbN1(vector<int> v) {
	int cnt=0;
	for(int i=0; i<v.size(); i++) {
		if(v[i]==1)cnt++;
	}
	return cnt;
}
int smsb(vector<int> v1,int msb1,vector<int> v2,int msb2) {
	// v[msb]=0;
	int j=v1.size()-1;
	while(v1[j]==v2[j]){
		v1[j]=0;
		v2[j]=0;
		j--;
	}
	int index=-1;
	for(int i=0; i<v1.size(); i++) {
		if(v1[i]==1)index=i;
	}
	// debug(index);
	return index;
}
void solve() {
	int n1=-1,n2=-1;
	cin>>n1>>n2;
 
	// convert both to binary
	vector<int> vn1(bitSize,-1);
	vn1=convertToBase2(n1);
	vector<int> vn2(bitSize,-1);
	vn2=convertToBase2(n2);
 
	//find most significant bit.
	int msb1=msb(vn1);
	// debug(msb1);
	int msb2=msb(vn2);
	int ans=-1;
	// int ans=msb1;
	
	int smsb1=smsb(vn1,msb1,vn2,msb2);
	// debug(smsb1);
	int smsb2=smsb(vn2,msb2,vn1,msb1);
	if(nsbN1(vn1)==1){
		ans=n1;
	} else {
		if(msb1==msb2) {
			//
			ans= cntMSB(vn1,vn2,smsb1,smsb2);
		} else {
			ans= (long long)1<<(msb1+1);
		}
 
	}
	cout<<ans<<endl;
	
	// delete(&n1);
	// delete(&n2);
	// delete(&vn1);
	// delete(&vn2);
	
 
}
 
bgcloud organizations add-iam-policy-binding qwiklabs-gcp-01-7fffba0de6ff --member="user:student-03-e7c39afcec77@qwiklabs.net" --role="roles/owner"
gcloud organizations add-iam-policy-binding qwiklabs-gcp-01-7fffba0de6ff --member="user:student-03-e7c39afcec77@qwiklabs.net" --role="roles/resourcemanager.projectCreator"
 
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
	// cout << fixed << setprecision(12);
 
	int t=1;
	cin>>t;
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}