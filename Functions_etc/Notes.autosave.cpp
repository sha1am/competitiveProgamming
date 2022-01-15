//Notes
// #include "bits/stdc++.h"
#include "header1.h"
using namespace std;
class set {

	// how to delete every second element from s

	void eraseEverySecondElement(set<int> s ) {

		//does not work in odd number of elements
		set<int>::iterator it;
		// it=s.begin();
		it=s.begin();

		// ++it;

		for(; it!=s.end() && ++it!=s.end() ;) {
			it=s.erase(it);
		}
		cout<<endl;
		printSet(s);

	}




};