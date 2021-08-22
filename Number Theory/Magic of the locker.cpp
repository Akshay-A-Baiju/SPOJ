// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/LOCKER/
// Problem tags : number theory, observation
// TC : O(t*log(n))
// SC : O(1)

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

ll binExp(ll exp)
{
    ll res=1;
    ll base=3;
    while (exp)
    {
        if (exp&1)
            res=(res*base)%M;
        base=(base*base)%M;
        exp>>=1;
    }
    return res;
}

void solve()
{  
    //we have to find the combination of numbers having sum = n and maximum product 
    //we observe that when we divide n into groups of 3 and do the product, maximum product is obtained
    ll n;
    cin>>n;
    if (n==1)
    {
        cout<<1;
        return;
    }
    ll ans;
    ll exp=n/3;
    if (n%3==0)
        ans=binExp(exp);
    else if (n%3==1)
        ans=(binExp(exp-1)*4)%M;
    else
        ans=(binExp(exp)*2)%M;
    cout<<ans;
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
