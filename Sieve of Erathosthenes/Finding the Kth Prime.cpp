// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/TDKPRIME/
// Problem tags : sieve
// TC : O(NloglogN + t)	//N=90000000
// SC : O(N)

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

vll prime(5000001);
vector <bool> isPrime(90000001,true);

void sieveOfEratosthenes()
{
	ll N=90000000;		//as first 5 million primes are contained in 86028121
	isPrime[0]=isPrime[1]=false;
	for (ll i=2;i*i<=N;i++)
	{
		if(isPrime[i])
		{
			//mark the multiples of i, starting from the square of the i as false
			for (ll j=i*i;j<=N;j+=i)
				isPrime[j]=false;
		}
	}
	ll index=1,i=2;
	while (index<=5000000)
	{
		if (isPrime[i])
		{
			prime[index++]=i;
		}
		i++;
	}
}

void solve()
{    
	ll n;
	cin>>n;
	cout<<prime[n];
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    cin>>t;
    sieveOfEratosthenes();		//preComputing the primes using sieve
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
