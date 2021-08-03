// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/AGGRCOW/
// Problem tags : advanced nibary search, classical, must know
// TC : O(nlog(1e9))
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

bool canPlaceCows(ll &minDist, vll &stall, ll c)    //predicate function -> returns if aggressive cows can be placed at minDist or not
{
    ll last=0,i=1,n=stall.size();  //placed the first aggressive cow in 0th index
    c--;                           //as first aggressive cow is placed
    while (c>0 && i<n)
    {
        if (stall[i]-stall[last]>=minDist)
        {
            c--;
            last=i;
        }
        i++;
    }
    return (c==0);  //c=0 means all aggressive cows can be placed at minDist
}

void solve()
{ 
    //classical problem : advanced binary search using Predicate function 
       
    ll n,c;
    cin>>n>>c;
    vll stall(n);
    scan_vector(stall,n);
    sort(all(stall));
    //predicate function: canPlaceCows : T T T . . . T F F F . . . F F, for minDist=0 to hi
    //find the last occurence of T -> maximum minDist between aggressive Cows
    ll lo=0,hi=1e9;
    while (hi-lo>1)
    {
        ll mid=(lo+hi)/2;
        if (canPlaceCows(mid,stall,c))
            lo=mid;
        else
            hi=mid-1;
    }
    if (canPlaceCows(hi,stall,c))
        cout<<hi;
    else
        cout<<lo;
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
