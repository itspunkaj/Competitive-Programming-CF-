#include <bits/stdc++.h>
#include <string.h>

#define int long long
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define yes cout << "YES\n";
#define no cout << "NO\n";

const int maxi = 1e9 + 7;
// const int MAXN = 1e7 + 1;
void vella()
{
    return;
}
void sella()
{
    return;
}
void tella()
{
    return;
}
using namespace std;

#define pb push_back
#define F first
#define S second
#define sz size()
#define all(V) V.begin(), V.end()
#define rall(V) V.rbegin(), V.rend()
#define take(x)       \
    for (auto &y : x) \
        cin >> y;
#define vi vector<int>
#define vvi vector<vector<int>>
#define show(x)      \
    for (auto y : x) \
        cout << y << " ";

int nxt()
{
    int x;
    cin >> x;
    return x;
}

bool prime[10000000 + 1];
vector<int> pp;
void sieve()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] wills
    // finally be false if i is Not a prime, else true.
    int n = 10000000 + 1;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
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
void unqVec(vi &v)
{
    v.erase(unique(all(v)), v.end());
}

//------------------------------------------------------* Template Ends Here *------------------------------------------------------//

/*__________________________________________________________________________________________________________________________________*/
/*__________________________________________________________________________________________________________________________________*/

//---------------------------------------------------------* Actual Code *---------------------------------------------------------//

void solve()
{
    int n = nxt();
    vi v(n);
    take(v);
    
    int ans = INT_MAX; 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k= 0; k < 3; k++) {
                int temp = (i+j+k);
                vi a = v;
                a[0] += i;
                a[1] += j;
                a[2] += k;
                if((a[0]+a[1]+a[2])%3 == 0) {
                    for(int l = 3; l < n; l++) {
                        int x = a[l] + a[l-1] + a[l-2];
                        a[l] += (3-x%3)%3;
                        temp += (3-x%3)%3;
                    }

                    ans = min(ans,temp);
                } 
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // sieve();
    int t = 1;
    t = nxt();
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
