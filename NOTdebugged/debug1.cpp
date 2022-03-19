#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++) {
			cin>>arr[i];
		}

		int ans=0;
		int pow=1;
		for(int i=0; i<32; i++) {
			int c=0;
			for(int j=0; j<n; j++) {
				if(arr[j]%2==1)c++;
				arr[j]=arr[j]/2;
			}
			if(c>1) {
				ans+=pow;
			}
			pow=pow*2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
// cd /Applications 
// nativefier \ 
// --name "Tasks" \ 
// --min-width "500" \ 
// --min-height "500" \ 
// --x "200" \ 
// --y "300" \ 
// -f \ 
// "https://mail.google.com/tasks/canvas" 