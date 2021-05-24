#include "bits/stdc++.h"
using namespace std;
bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
 
 
void solve()
{
    // Declaring vector of pairs
    vector< pair <int,int> > vect;
 
    // Initializing 1st and 2nd element of
    // pairs with array values
    int arr[] = {5, 20, 10, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );
 
    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
            << vect[i].second << endl;
    }
 
    // using modified sort() function to sort
    sort(vect.begin(), vect.end(), sortbysecdesc);
 
    // Printing the sorted vector(after using sort())
    cout << "The vector after applying sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    //return 0;
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