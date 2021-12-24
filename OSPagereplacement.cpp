#include "bits/stdc++.h"
#include<semaphore.h>
#include<thread>
//#include<mutex>

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
void _print(int t) {cerr << t;}
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

bool checkFun(vector<int> workArray, int pageNum){
    bool flag=false;

    rep(i,0,workArray.size()){
        if(workArray[i]==pageNum) flag=true;
    }

    if(flag) return true;
    else return false;

}

int fifoFun(vector<int> pageReplacement, int pageFrame){

    vector<int> workArray(pageFrame,-1);
    int numOfPageFaults=0;

    int count=0;
    rep(i,0,pageReplacement.size()){

        if(checkFun(workArray,pageReplacement[i])==false)
        {
            numOfPageFaults+=1;

            //update Value
            workArray[count%pageFrame]=pageReplacement[i];
            count++;
        }

        debug(workArray);
        debug(count);


    }

    return numOfPageFaults;
}

int optimalFunHelper(vector<int> pageReplacement,vector<int> workArray,int i){


    int maxCount=-1;

    int ans=-1;



    for(int j=0;j<workArray.size();j++){

        if(checkFun(pageReplacement,workArray[j])){
            return j;
        }

        int count=0;
        for(int k=i+1;k<pageReplacement.size();k++)
        {
            count++;
            if(workArray[j]==pageReplacement[k]) break;
            
        }

        //debug(count);

        if(count>=maxCount) ans=j;

    }

    // debug(workArray);
    // debug(pageReplacement);
    // debug(i);
    // debug(ans);
    return ans;

    }

int OptimalFun(vector<int> pageReplacement, int pageFrame){

    vector<int> workArray(pageFrame,-1);
    int numOfPageFaults=0;

    int count=0;


    rep(i,0,pageReplacement.size()){

        if(checkFun(workArray,pageReplacement[i])==false)
        {
            numOfPageFaults+=1;

            //update Value
            if(checkFun(workArray,-1)){

                workArray[count%pageFrame]=pageReplacement[i];
                count++;
            }

            else{
                int indexOfPageToBe=optimalFunHelper(pageReplacement,workArray,i);
                workArray[indexOfPageToBe]=pageReplacement[i];
            }
            
        }

        debug(workArray);
        
        debug(numOfPageFaults);

    }

    return numOfPageFaults;
}

int LRUfunHelper(deque<int> q,vector<int> workArray){

    int ans=-1, pageId=-1;
    if(!q.empty()){
        pageId=q.front();

    }

    if(pageId==-1) return -1;
    rep(i,0,workArray.size()){
        if(workArray[i]==pageId) return i;
    }

    return -1;
    //it will throw segmentation fault

}
int LRUFun(vector<int> pageReplacement, int pageFrame){

    vector<int> workArray(pageFrame,-1);
    int numOfPageFaults=0;

    //Queue for maintaining the Least recent
    deque<int> q;

    int count=0;
    rep(i,0,pageReplacement.size()){

        cerr<<"The next page number"<<pageReplacement[i]<<endl;

        if(checkFun(workArray,pageReplacement[i])==false)
        {
            numOfPageFaults+=1;

            //update Value

            if(checkFun(workArray,-1)){
                q.push_back(pageReplacement[i]);
                workArray[count]=pageReplacement[i];
                count++;
                //debug(q);

            }
            else{
                int indexOfPageToBe=0;
                if(!q.empty()){
                    indexOfPageToBe=LRUfunHelper(q,workArray);

                }
                workArray[indexOfPageToBe]=pageReplacement[i];
                q.push_back(workArray[indexOfPageToBe]);

                 if(!q.empty()){
                    q.pop_front();
                    }

            
            }

           

            
        }
        else{

            deque<int> tempQ;
            while(q.front()!=pageReplacement[i] && !q.empty()){
                tempQ.push_back(q.front());
                q.pop_front();
            }

            q.push_back(q.front());
            q.pop_front();

            while(!q.empty()){
                tempQ.push_back(q.front());
                q.pop_front();
            }

            q=tempQ;
        }

        debug(workArray);
        debug(q);
        cerr<<"\n"<<endl;

       

    }

    return numOfPageFaults;
}

void solve(){
    //vector<int> pageReplacement{ 1, 3, 0, 3, 5, 6,3};
    vector<int> pageReplacement{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    //no of page frames
    int noOfPageFrame=4;
    //cin>>noOfPageFrame;


    int choice=3;
    // cout<<"Enter 1)-FIFO 2)Optimal 3)LRU (least recently used) "<<endl;
    // cin>>choice;

    int ans=-1;

    switch(choice){
        case 1: //use fifo algo
                ans=fifoFun(pageReplacement,noOfPageFrame);


        break;
        case 2: //use optimal
                ans=OptimalFun(pageReplacement,noOfPageFrame);
        break;
        case 3: //use lru
                ans=LRUFun(pageReplacement,noOfPageFrame);
        break ;
        default: cout<<"Wrong choice "<<endl;
    }

    cout<<"The number of page faults is "<<ans<<endl;	
 
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	start = clock(); 
	#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
    #endif
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	cout << fixed << setprecision(12);
	
	int t=1;
	//cin>>t;
	while(t--) solve();
	cerr << time(start);
	return 0;
}