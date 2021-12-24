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


//function which returns the num of task that need to be completed.

int fun(vector<pair<int,int>> v1,int lastProcess,vector<bool> status)
{
    sort(v1.begin(),v1.end());

    rep(i,0,v1.size()){
        if(status[v1[i].sc]!=true) return v1[i].sc;
    }

    return -1;
}
// shortest job first ( non-preemtive)

void solve(){

    int numProcess=0;
    cout<<"Enter the number of processes";
    cin>>numProcess;

    vector<int> bt(numProcess,0); //burst times
    vector<int> wt(numProcess,0); //waiting times
    //calculate turn around time for all processes
    vector<int> tat(numProcess,0);
    vector<bool> status(numProcess,false);
    
    //enter burst time
    rep(i,0,numProcess){
        //cout<<"Enter burst time of process "<<i+1;
        cin>>bt[i];
    }
    cout<<endl;

    //Make pair
    vector<pair<int,int>> v1;
    rep(i,0,numProcess){
        pair<int,int> p=make_pair(bt[i],i);
        v1.push_back(p);
    }

    //cout<<"V1[0]="<<v1[0].fr<<" "<<v1[0].sc<<endl;

    int lastProcess=-2;
    int lastWT=0;
    while(fun(v1,lastProcess,status)!=-1){
        int currentProcessNum=fun(v1,lastProcess,status);
        //cout<<"CP="<<currentProcessNum<<endl;
        int i=currentProcessNum;

        wt[currentProcessNum]=bt[lastProcess]+lastWT;
        lastWT=wt[currentProcessNum];
        lastProcess=currentProcessNum;
        tat[currentProcessNum]=wt[currentProcessNum]+ bt[currentProcessNum];
        cout<<"Process:-"<<i+1<<" BT:-"<<bt[i]<<" WT:-"<<wt[i]<<" TAT:- "<<tat[i]<<endl;
        status[currentProcessNum]=true;
    }





    // print all info

    double averageWT=0;
    double averageTAT=0;

    rep(i,0,numProcess){
        averageWT+=wt[i];
        averageTAT+=tat[i];
    }

    cout<<"The Av.WT is "<<(averageWT/numProcess)<<endl;
    cout<<"The Av.TAT is "<<(averageTAT/numProcess)<<endl;
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
