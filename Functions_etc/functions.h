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

	class funToPrintCombinations {

		void recursiveCombinationFunction(queue<int> q1, vector<int> tempVec , int frameSize, int pos) {

			// debug(q1);
			// auto name = type_name<decltype(q1.size())>();
			//cout<<name<<endl;

			//base condition
			if (pos == frameSize) {
			//print the arrray
				debug(tempVec);
				return;
			}
			
			queue<int> tempQ = q1;

			//in this loop
			//fill in the first(nth place)
			for (int i = 0; i < q1.size(); i++) {

				if(!tempQ.empty()) {
					tempVec[pos] = tempQ.front();

				}
				//recursevely call for

				//delete tempQ.front()
				if (!tempQ.empty()) {
					tempQ.pop();
				}
				recursiveCombinationFunction(tempQ, tempVec, frameSize, pos + 1);
			}

		}

		void printAllCombinations(queue<int> q1, int frameSize) {

			vector<int> tempVec(frameSize, -1);
			cout << "shada3" << endl;

			recursiveCombinationFunction(q1, tempVec, frameSize, 0);


		}
		void solve() {
			//vector<int> arr = {'a', 'b', 'c', 'd'};


			// FrameSize should be less than array size
			queue<int> q;
			q.push(1);
			q.push(2);
			q.push(3);
			q.push(4);
			q.push(5);
			q.push(6);




			int frameSize = 3;


			// cout << "shada1" << endl;

			printAllCombinations(q, frameSize);
			// cout << "shada2" << endl;

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