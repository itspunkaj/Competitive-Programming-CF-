/*
Problem Link:

https://codeforces.com/contest/1840/problem/D

*/


#include <bits/stdc++.h>
#include <string.h>

#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";


const int maxi = 1e9 + 7;
// const int MAXN = 1e7 + 1;
void vella() {
    return;
}
void sella() {
    return;
}
void tella() {
    return;
}
using namespace std;

#define pb push_back
#define F first
#define S second
#define sz size()
#define all(V) V.begin(),V.end()
#define rall(V) V.rbegin(),V.rend()
#define take(x) for(auto &y:x) cin>>y;
#define show(x) for(auto y:x) cout<<y<<" ";

int nxt() {
    int x;
    cin >> x;
    return x;
}

bool prime[10000000+1];
vector<int> pp;
void sieve()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] wills
    // finally be false if i is Not a prime, else true.
    int n = 10000000+1;
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            pp.pb(p);
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    sort(all(pp));
}

void unqVec(vi &v){
    v.erase(unique(all(v)),v.end());
}
//------------------------------------------------------* Template Ends Here *------------------------------------------------------//


/*__________________________________________________________________________________________________________________________________*/
/*__________________________________________________________________________________________________________________________________*/


//---------------------------------------------------------* Actual Code *---------------------------------------------------------//

void solve() {
    int n = nxt();
    vi v(n);
    take(v);
    unqVec(v);
    
    n = v.sz;

    if(n <= 3) {
        cout << 0;
        return;
    }
    sort(all(v));
    int ans = INT_MAX;
    
    for(int i2 = 0; i2 < n; i2++) {
        int i1 = 0;
        int i4 = n-1;

        int i3 = upper_bound(all(v),v[i2+1]+(v[i4]-v[i2+1])/2) - v.begin() - 1;
        ans = min(ans,max((v[i4]-v[i3+1]+1)/2,max((v[i3]-v[i2+1]+1)/2,(v[i2]-v[i1]+1)/2)));
    }

    cout << ans;

    
}
    


signed  main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 
	// sieve();
    int t = 1;
    t = nxt();
    while(t--) {
        solve();
        cout<<"\n";
    } 
} 
