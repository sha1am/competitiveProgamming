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


int W=102; //increase it before using in realfunction ********* maybe 50-100
int N=103; // for power one equal to size of array in question
//intitialise inner pair
vector<int> tempV0(32,0);
pair<int,vector<int>> tempP=make_pair(-1,tempV0);
//now initiliaze outer pair
vector<pair<int,vector<int>>> tempV1; // size of this array is unknown in the begin
pair<bool,vector<pair<int,vector<int>>>> element=make_pair(false,tempV1);
// final t in making
vector<pair<bool,vector<pair<int,vector<int>>>>> tempV2(W+1,element);
vector<vector<pair<bool,vector<pair<int,vector<int>>>>>> t(N+1,tempV2);

bool checkIndexPowerOf2AllSetToZero(vector<pair<int,int>>* indexPowerOf2) {

	bool flag=true;
	rep(i,0,(*indexPowerOf2).size()) {
		if((*indexPowerOf2)[i].sc!=0) {
			flag=false;
		}
	}
	return flag;
}
pair<vector<int>,int> recursiveIndexPowerOf2Util(vector<pair<int,int>>* indexPowerOf2) {


	vector<int> thisAns;
	pair<vector<int>,int> thisAnsModified;
	int minPow=INF;
	rep(i,0,(*indexPowerOf2).size()) {
		//find minimum power except 0;
		if((*indexPowerOf2)[i].sc<minPow && (*indexPowerOf2)[i].sc!=0 ) {
			minPow=(*indexPowerOf2)[i].sc;
		}
	}

	debug(minPow);

	rep(i,0,(*indexPowerOf2).size()) {
		//check which indexes have power greater than or equal to minPow
		//add them to the thisAns

		if((*indexPowerOf2)[i].sc>=minPow) {
			thisAns.pb((*indexPowerOf2)[i].fr);
			(*indexPowerOf2)[i].sc-=minPow;
		}
	}
	int multiplier=pow(2,minPow);
	thisAnsModified=make_pair(thisAns,multiplier);

	return thisAnsModified;

}

void indexPowerOf2Util(vector<pair<int,int>>* indexPowerOf2) {

	vector<pair<vector<int>,int>> ans;
	pair<vector<int>,int> tempPP;

	cerr<<"insideindexPowerOf2Util"<<endl;
	debug((*indexPowerOf2));
	int numOfMoves=0;
	while(checkIndexPowerOf2AllSetToZero(indexPowerOf2)==false) {
		vector<int> thisAns;
		tempPP=recursiveIndexPowerOf2Util(indexPowerOf2);
		thisAns=tempPP.fr;
		int powOf2ToWhichMultiplied=tempPP.sc;
		ans.pb(make_pair(thisAns,powOf2ToWhichMultiplied));
		numOfMoves+=1;
	}

	debug(numOfMoves);

	//now printAll the indexes


}

bool zeroCheckOkayOrNot(vector<int> v,int n) {
	bool flag=true;
	rep(i,0,n+1) {
		if(v[i]==0) {
			flag=false;
			break;
		}
	}
	return flag;
}

int countDiffrentNoSpecies(vector<int> v) {
	set<int> s;
	//put everything in set
	rep(i,0,v.size()) {
		s.insert(v[i]);
	}
	s.erase(0);
	return (s.size());
}
void debugPrintT() {

	rep(i,0,3+1) {
		rep(j,0,6+1) {
			cerr<<t[i][j].fr;
		}
		cerr<<endl;
	}
	cerr<<endl;
}


void debugPrintTT() {
	//print the sum and all vectors which have t[i][j].fr==true;
	//see only in N==1 and
	rep(i,0,N+1) {
		rep(j,0,W+1) {
			if( t[i][j].fr) {
				cerr<<"i"<<i<<"j"<<j<<" "<<endl;

				rep(k,0,t[i][j].sc.size()) {
					if(1) {
						cerr<<"sum: "<<t[i][j].sc[k].fr<<endl;

						//print the sum and all vectors with them
						// t[i][j].sc[0]; //this is the 0th pair which has (sum+vector)|| sum .(0,1,2,3,4 according to how many sums are formed)
						// t[i][j].sc[0].fr // this the sum corresponding to the 0th pair
						// t[i][j].sc[0].sc // this the vector corresponding to the 0th pair

						//print vector
						debug(t[i][j].sc[k].sc);
					}
				}


			}

		}
	}
	cerr<<endl;
}

void debugPrintTTt() {
	//print the sum and all vectors which have t[i][j].fr==true;
	//see only in N==1 and
	rep(i,0,N+1) {
		rep(j,0,W+1) {
			if(j==0) {



				cerr<<"i"<<i<<"j"<<j<<" "<<endl;

				//print the sum and all vectors with them
				// t[i][j].sc[0]; //this is the 0th pair which has (sum+vector)|| sum .(0,1,2,3,4 according to how many sums are formed)
				// t[i][j].sc[0].fr // this the sum corresponding to the 0th pair
				// t[i][j].sc[0].sc // this the vector corresponding to the 0th pair
				rep(k,0,t[i][j].sc.size()) {
					//print sum
					cerr<<t[i][j].sc[k].fr<<endl;
					//print vector
					debug(t[i][j].sc[k].sc);
				}

			}
		}
		cerr<<endl;
	}
}
void debugPrintTTtt() {
	//print the sum and all vectors which have t[i][j].fr==true;
	//see only in N==1 and
	rep(i,0,N+1) {
		rep(j,0,W+1) {
			if(i<4 && j<7) {
				cerr<<"i"<<i<<"j"<<j<<" "<<endl;

				rep(k,0,t[i][j].sc.size()) {
					if(1) {
						cerr<<"sum: "<<t[i][j].sc[k].fr<<endl;

						//print the sum and all vectors with them
						// t[i][j].sc[0]; //this is the 0th pair which has (sum+vector)|| sum .(0,1,2,3,4 according to how many sums are formed)
						// t[i][j].sc[0].fr // this the sum corresponding to the 0th pair
						// t[i][j].sc[0].sc // this the vector corresponding to the 0th pair

						//print vector
						debug(t[i][j].sc[k].sc);
					}
				}


			}

		}
	}
	cerr<<endl;
}
int calculateMostSignificantBitIndex(vector<int> sumOfAllBinaryNumbers) {
	int index=-1;
	rep(i,0,32) {
		if((sumOfAllBinaryNumbers)[i]==1) {
			index=i;
		}
	}

	return index;
}
vector<int> convertDecimalToBinary(int numDecimal) {

	vector<int> numBinary(32,0);

	vector<int> tempV;
	while(numDecimal!=0) {
		int rem=numDecimal%2;
		tempV.pb(rem);
		numDecimal/=2;
	}
	// sort(tempV.begin(),tempV.end(),greater<int>());
	for(int i=0; i<tempV.size(); i++) {
		numBinary[i]=tempV[i];
	}
	return numBinary;

}
int returnnIndexValueWhen2Set(int n, int poww) {
	//modified for powersum
	int ans=-1;
	// if(poww==0) {
	// 	ans=0;
	// } else {
	// 	ans=n*pow(2,poww);
	// }
	ans=n*poww;
	// debug(ans);
	return ans;
}

void knapsack(vector<int> weight,vector<int> value,int w,int n,int sumToMake) {
	// assume sumToMake!=0 in every case
	//top down appproach

	rep(i,0,n+1) {
		rep(j,0,w+1) {
			if(i==0) {
				//make first one false
				t[i][j].fr=false;
				// make t[i][j].sc a empty
				vector<pair<int,vector<int>>> tempV10;
				t[i][j].sc=tempV10;

			}
			if(i>0 && j==0) {
				//step 1:- calculate all possible sums in this. //only one possible in this vertical row (ie. not taking any one of them)
				// int sum=0;
				int sum=0;
				//mdified for power sum ********
				rep(k,0,i) {
					sum+=value[k];
				}
				vector<int> tempV01(32,0);
				//set indexes from starting to 000.. according to size of current array (ie.i) ***** doubt
				rep(k,0,i) { //**
					tempV01[k]=0; //0 in this case ,in other cases according to selected or not
				}
				pair<int,vector<int>> tempP=make_pair(sum,tempV01);
				//push this pair into the vector
				vector<pair<int,vector<int>>> tempV11;
				tempV11.pb(tempP);

				if(sum==sumToMake) {
					t[i][j].fr=true;
					cerr<<"UnsignedcomparisionWorking"<<endl;

				}
				// make t[i][j].sc a empty
				t[i][j].sc=tempV11;
			}
		}

	}
	// cerr<<"endOf1stINitial";
	// debugPrintT();


	//now do it for row i=1, special case;
	rep(i,0,n+1) {
		rep(j,0,w+1) {
			if(i==1 && j!=0) {
				// just take the biggest value (ie.w) not all combinations (ie.NOT 0,1,2,..w)
				//because we need to consume all values we get
				//step 1:- calculate all possible sums in this. //only one possible in this vertical row (ie. not taking any one of them)
				int sum=returnnIndexValueWhen2Set(value[0],j); //first value*w
				debug((int)sum);

				vector<int> tempV01(32,0);
				//set indexes from starting to 000.. according to size of current array (ie.i)
				tempV01[i-1]=j; //index of i-1 th value to w (ie. J)

				pair<int,vector<int>> tempP=make_pair(sum,tempV01);
				//push this pair into the vector
				vector<pair<int,vector<int>>> tempV12;
				tempV12.pb(tempP);

				if(sum==sumToMake) {
					t[i][j].fr=true;
					cerr<<"UnsignedcomparisionWorking"<<endl;
				}
				// make t[i][j].sc a empty
				t[i][j].sc=tempV12;
			}
		}
	}
	cerr<<"endOf2ndSpecialCaseINitial"<<endl;
	debugPrintT();

	//main part
	//now fill the rest
	rep(i,2,n+1) {
		cerr<<"i"<<i<<endl;
		rep(j,1,w+1) {
			//fill this according to rules
			cerr<<"j"<<j<<endl;
			int valAtIJ=value[i-1];
			debug(valAtIJ);
			//how many values can be filled at this state? -- (0,1,2..w)

			//this rep loop for only to check if the sumToMakeBeMadeFromThis or not? *** lil doubt
			for(int k=0; k<=j; k++) { //////#######
				//now at each 0 || 1 || 2 etc (ie. k)
				int remSumToMake=(int)sumToMake-(int)returnnIndexValueWhen2Set(valAtIJ,k);
				debug(k);
				debug(remSumToMake);
				if(remSumToMake<0) {
					//dont do anything // it is certain that this will not have any .
				} else {
					// t[i-1][j-k]; //find value in this
					rep(l,0,(t[i-1][j-k].sc).size()) {
						if((t[i-1][j-k].sc)[l].fr==remSumToMake) {
							t[i][j].fr=true; // this means the sumToMake can be made using this too;
							cerr<<"TrueSetFlag0"<<endl;
							break;
						}

					}
				}

			}

			vector<pair<int,vector<int>>> tempV13;
			//to keep track of all the combinations and their respective sums
			for(int k=0; k<=j; k++) {
				//now at each 0 || 1 || 2 etc (ie. k)

				// t[i-1][j-k]; //find value in this
				rep(l,0,(t[i-1][j-k].sc).size()) {
					// pair<int,vector<int>> tempPToKeepTrackOfAllSumsP;
					vector<int> tempVToKeepTrackOfAllSums;
					int sumOfThisIteration =(int)returnnIndexValueWhen2Set(valAtIJ,k)+ (t[i-1][j-k].sc)[l].fr;
					debug(sumOfThisIteration);
					tempVToKeepTrackOfAllSums=((t[i-1][j-k].sc)[l].sc);
					//just set the next bit {i th} to k;
					tempVToKeepTrackOfAllSums[i-1]=k; //i-1 because for i=1 , the index of 0 should be filled
					//push This vector int vector of vector of this index (ie.t[i][j])
					tempV13.pb(make_pair(sumOfThisIteration,tempVToKeepTrackOfAllSums));
					// debug(tempV13);

				}
			}

			//set the vector vector int now
			t[i][j].sc=tempV13;


		}

		cerr<<"end of this I in main"<<endl;
		cerr<<endl;
		cerr<<endl;
	}
	cerr<<"endOf3rd Main INitial";
	debugPrintT();

}
void solve() {

	//RESET GLOBAL VARIABLES

	rep(i,0,N+1) {
		rep(j,0,W+1) {
			// t[i][j].clear();
			t[i][j]=element;
		}
	}

	//
	int x,s;
	cin>>x>>s;

	vector<int> xBin=convertDecimalToBinary(x);
	vector<int> sBin=convertDecimalToBinary(s);

	debug(xBin);
	debug(sBin);

	int mostSignificantBitIndexOfXBin=calculateMostSignificantBitIndex(xBin);
	int mostSignificantBitIndexOfSBin=calculateMostSignificantBitIndex(sBin);

	set<int> cursedIndexes;
	rep(i,0,32) {
		if(xBin[i]!=1) {
			//mark cursed
			cursedIndexes.insert(i);
		}
	}
	debug(mostSignificantBitIndexOfXBin);
	debug(mostSignificantBitIndexOfSBin);
	debug(cursedIndexes);
	vector<pair<int,bool>> sBinWithMarking;

	bool flag=false;
	for(int i=mostSignificantBitIndexOfSBin; i>=0; i--) {
		if(cursedIndexes.find(i)!=cursedIndexes.end()) {
			//mark solution cannot be possible if there is a cursed place and all cursed place aftere this index
			for(int j=i; j>0; j--) {
				// every position is cursed //check if any is not cursed
				if(cursedIndexes.find(j)==cursedIndexes.end()) {
					//safe solution exists
					flag=true;
					break;
				} else {
					//cannot be solved
					cerr<<"i"<<i<<endl;
					// break;
				}
			}
			//shift this number to next index i-1
			if(i==0) {
				//cannot shift in this case;
			} else {
				sBin[i-1]+=sBin[i]*2;
				sBin[i]=0;
			}
			debug(sBin);
		}
	}

	debug(sBin);

	if(flag==false) {
		//cannot be solved
		cout<<-1<<endl;
	} else {
		//continue forward
		vector<int> arrOfNumbers;
		rep(i,0,mostSignificantBitIndexOfXBin+1) {
			if(cursedIndexes.find(i)!=cursedIndexes.end()) {
				//i is cursed , so skip
			} else {
				arrOfNumbers.pb(pow(2,i));

			}
		}
		debug(arrOfNumbers);
		//reverse array of numbers

		//same weight for all // if include same number of noOf2s decreased from totalPowersOf Orgional
		vector<int> weight= {1,1,1,1,1,1};

		// vector<int> value= {2,4,8,16,128,512};
		vector<int> value=arrOfNumbers;

		int  sum=s;


		//calculate total powers of 2
		int totalSumOfoPowersOf2=0;
		rep(i,0,32) {
			totalSumOfoPowersOf2+=sBin[i];
		}
		debug(totalSumOfoPowersOf2);

		int n=value.size();

		int w=totalSumOfoPowersOf2;

		knapsack(weight,value,w,n,sum);

		//knapsack

		//debugging
		// debugPrintT();

		// debugPrintTT();
		// debugPrintTTt();

		// debugPrintTTtt();

		//

		//now
		vector<vector<int>> allVecWhichGiveSumRequired;
		// bool flag=false;
		rep(j,0,w+1) {
			rep(i,0,n+1) {
				if(t[i][j].fr==true ) {
					//flag==true
					cerr<<"i"<<i<<"j"<<j<<" "<<endl;

					rep(k,0,t[i][j].sc.size()) {
						if(t[i][j].sc[k].fr==sum) {
							cerr<<"sum: "<<t[i][j].sc[k].fr<<endl;

							//print the sum and all vectors with them
							// t[i][j].sc[0]; //this is the 0th pair which has (sum+vector)|| sum .(0,1,2,3,4 according to how many sums are formed)
							// t[i][j].sc[0].fr // this the sum corresponding to the 0th pair
							// t[i][j].sc[0].sc // this the vector corresponding to the 0th pair

							//print vector
							debug(t[i][j].sc[k].sc);
							allVecWhichGiveSumRequired.pb(t[i][j].sc[k].sc);

						}
					}


				}
			}
			//if found in this j , then exit.  don't look in further J's
			// if(flag==true)break; ///**********
		}

		//first remove all which have zero between (0,1,2...n)
		vector<vector<int>> allVecWhichGiveSumRequiredNew;
		rep(i,0,allVecWhichGiveSumRequired.size()) {
			if(zeroCheckOkayOrNot(allVecWhichGiveSumRequired[i],n)){
				//remove this vector 
			}
			else{
				allVecWhichGiveSumRequiredNew.pb(allVecWhichGiveSumRequired[i]);
			}
			}

		//now allVec vvi has all the smallest valid vectors;

		vector<pair<int,vector<int>>> tempP; //store vector with their minimum varieties
		rep(i,0,allVecWhichGiveSumRequiredNew.size()) {
			int min=countDiffrentNoSpecies(allVecWhichGiveSumRequiredNew[i]);
			tempP.pb(make_pair(min,allVecWhichGiveSumRequiredNew[i]));
		}
		//sort this vector of pair
		sort(tempP.begin(),tempP.end());

		//now the top most element has the least number of 
		debug(tempP);

		// cout<<tempP[0].fr<<endl;






	}








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