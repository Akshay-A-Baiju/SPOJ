// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/PRIME1/
// Problem tags : segmented sieve, classical
// TC : O(t + nloglogn)
// SC : O(1e5)

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define umap                unordered_map
#define uset                unordered_set
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

vll primes;     //store the primes till 1e5

void sieveOfErato(ll n)
{
    //TC: O(n*log(logn))

    vector <bool> isPrime(n+1,true);
    for (ll i=2;i<=n;i++)
    {
        if (isPrime[i])
        {
            for (ll j=i*i;j<=n;j=j+i)
                isPrime[j]=false;
        }
    }
    for (ll i=2;i<=n;i++)
    {
        if (isPrime[i])
            primes.pb(i);
    }
}

void segmentedSieve(ll lo, ll hi)
{
    //TC: O(nloglogn)
    
    if (lo==1)
        lo++;
    vector <bool> isPrime(hi-lo+1,true);
    for (ll i=0;primes[i]*primes[i]<=hi;i++)
    {
        ll p=primes[i];
        ll j=(lo/p)*p;
        if (j<lo)
            j+=p;
        for (;j<=hi;j+=p)
        {
            if (j!=p)
                isPrime[j-lo]=false;
        }
    }
    for (ll i=lo;i<=hi;i++)
    {
        if (isPrime[i-lo])
            cout<<i<<endl;
    }
}

void solve()
{    
    ll lo,hi;
    cin>>lo>>hi;
    segmentedSieve(lo,hi);
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    cin>>t;
    sieveOfErato(100000LL);     //preComputing all primes in range 2 to 1e5, as we need to precompute primes till sqrt(R)
    while (t--)
    {
        solve();
        cout<<endl;
    }
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
