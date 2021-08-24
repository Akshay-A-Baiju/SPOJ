// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/ARRAYSUB/
// Problem tags : sliding window, must know
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
    //using sliding window technique with maps
    ll n,i;
    cin>>n;
    vll v(n);
    for (auto &it: v)
        cin>>it;
    ll size;
    cin>>size;
    map<ll,ll> mp;
    for (i=0;i<size;i++)
        mp[v[i]]++;
    auto it=--mp.end();
    cout<<it->first<<" ";
    for (;i<n;i++)
    {
        mp[v[i]]++;
        mp[v[i-size]]--;
        if (mp[v[i-size]]==0)
            mp.erase(v[i-size]);
        it=--mp.end();
        cout<<it->first<<" ";
    }
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
