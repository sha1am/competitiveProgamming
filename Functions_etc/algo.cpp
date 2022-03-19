//#include "bits/stdc++.h"
#include "header1.h"
using namespace std;

//Functions


class generalFunctions {


	class binpow {
		int binpow(int a, int b, int m) {
			if(b==0) return 1;

			if(b&1) {
				int t1=binpow(a,(b-1)/2,m);
				t1=(t1*t1)%m;
				int t=(1ll*a*t1)%m;
				return t;
			} else {
				int t1=binpow(a,b/2,m);
				t1=(t1*t1)%m;
				int t= (1ll*t1)%m;
				return t;
			}
		}
	}
};