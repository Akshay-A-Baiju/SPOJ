// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/ALIEN/
// Problem tags : sliding window
// TC : O(n)
// SC : O(n)

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

void solve()
{
    //using variable sliding window technique  
    ll n,k;
    cin>>n>>k;
    vll station(n);
    scan_vector(station,n);
    ll lo=0,hi=0;   //2-pointers
    ll count=0,sum=0,mn=k;
    while (lo<n && hi<n)
    {
        sum+=station[hi];
        while (sum>k)   //moving lo pointer until sum<=k
        {
            sum-=station[lo];
            lo++;
        }
        if (hi-lo+1>count)
        {
            count=hi-lo+1;
            mn=sum;
        }
        else if (hi-lo+1==count)
            mn=min(mn,sum);
        hi++;
    }
    cout<<mn<<" "<<count;
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
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
