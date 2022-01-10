//#include "bits/stdc++.h"
#include "header1.h"
using namespace std;

//Functions


class generalFunctions {


	class funToPrintPermutations {
		void recursivePermutationFunction(vector<char> v1, vector<char> tempVec
		                                  , int frameSize, int pos) {

			//base condition
			if (pos == frameSize) {
				//print the arrray
				debug(tempVec);
				return;
			}

			//in this loop
			//fill in the first(nth place)
			for (int i = 0; i < v1.size(); i++) {
				tempVec[pos] = v1[i];
				//recursevely call for
				recursivePermutationFunction(v1, tempVec, frameSize, pos + 1);

			}
		}

		void printAllPermutations(vector<char> v1, int frameSize) {

			vector<char> tempVec(frameSize, -1);
			cout << "shada3" << endl;

			recursivePermutationFunction(v1, tempVec, frameSize, 0);


		}
		void solve() {
			vector<char> arr = {'a', 'b', 'c', 'd'};
			int frameSize = 8;

			cout << "shada1" << endl;

			printAllPermutations(arr, frameSize);
			cout << "shada2" << endl;

		}
	}
	//not sure about this one yet
	class funToPrintCombinations {
		// you can skip the pos
		void printCombinationUtil(queue<int> q, int frameSize, vector<int> tempVec, int pos) {
			//base condition
			// stop if tempVec.size()==frameSize or q.empty()==1
			// debug(tempVec);
			// debug(q);

			if(tempVec.size()==frameSize || q.empty()) {
				// print tempVec
				if(tempVec.size()==frameSize) {
					debug(tempVec);

				}
				return;
			}

			//real job
			queue<int> tempQ=q;

			while(!q.empty()) {

				vector<int> tempTempVec=tempVec;
				//can give signbrt error
				tempTempVec.pb(q.front());

				//forward q-q.front();
				// debug((int)q.size());
				q.pop();
				printCombinationUtil(q,frameSize,tempTempVec,pos+1);

			}


		}

		void printCombination(queue<int> q, int frameSize ) {
			vector<int> tempVec;

			printCombinationUtil(q,frameSize,tempVec,0);
		}

		void solve() {


			queue<int> q;
			q.insert(1);
			q.insert(2);
			q.insert(3);
			q.insert(4);

			int frameSize=2;

			printCombination(q,frameSize);

		}


	}

	class funToCalculatePrimeFactors {

		// root n complexity
		class simplePrimeFactors {
			vector<pair<int,int>> primeFactors(int n) {
				//to store the factors
				vector<pair<int,int>> primeFactorArr;

				int countOf2=0;
				while(n%2==0) {
					n/=2;
					countOf2+=1;
				}

				if(countOf2>0) {
					primeFactorArr.push_back(make_pair(2,countOf2));
				}

				for(int i=3; i*i<=n; i+=2) {
					int countOfI=0;
					while(n%i==0) {
						n/=i;
						countOfI+=1;
					}
					if(countOfI>0) {
						primeFactorArr.push_back(make_pair(i,countOfI));
					}
				}

				debug(n)

				//if a number itself is prime factor to add it too
				if(n>2) {
					primeFactorArr.push_back(make_pair(n,1));

				}

				debug(primeFactorArr);

				return primeFactorArr;


			}

			void solve() {
				int n=(17*17*5);
				// int n=5;
				// cin>> n;

				vector<pair<int,int>> result=primeFactors(n);

				for(int i=0; i<result.size(); i++) {
					cout<<result[i].first<<" ";
				}
				cout<<endl;



			}

		}

	}
};