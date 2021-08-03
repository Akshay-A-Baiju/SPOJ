// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/EKO/
// Problem tags : advanced binary search, classical, must know
// TC : O(nlogn)
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
 
bool isWoodSufficient(ll &h,vll &trees,ll &m)   //predicate function which returns if wood length Mirko cuts using 'h' height sawblade >= m or not
{
    ll wood=0;
    for (ll i=0;i<trees.size();i++)
    {
        if (trees[i]>=h)
            wood+=trees[i]-h;
    }
    return wood>=m;
}
 
void solve()
{
    //classic problem: advanced binary search with Predicate function 
    ll n,m;
    cin>>n>>m;
    vll trees(n);
    scan_vector(trees,n);
    ll lo=0,hi=1e9;
    //isWoodSufficient returns : T T T T .. T F F F F... F for h=0 to hi
    //we have to find last true
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isWoodSufficient(mid,trees,m))
            lo=mid;
        else
            hi=mid-1;
    }
    if (isWoodSufficient(hi,trees,m))
        cout<<hi;
    else
        cout<<lo;
}
 
int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
} 
