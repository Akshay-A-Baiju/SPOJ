// Author : Akshay A Baiju
// Problem link : https://www.spoj.com/problems/MAIN74/
// Problem tags : matrix exponentiation, observation, Lame-Knuth theorem
// TC : O(t * log(n))
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

void matrix_mulp(ll A[2][2], ll B[2][2])
{
    //A=A*B
    ll res[2][2];
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            res[i][j]=0;
            for (ll k=0;k<2;k++)
                res[i][j] = (res[i][j] + ((A[i][k]%M)*(B[k][j]%M))%M)%M;
        }
    }
    //copy res to A
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
            A[i][j]=res[i][j];
    }
}

void binMatrixExp(ll trans[2][2], ll exp)
{
    //initializing identity element
    ll res[2][2]={{1,0},{0,1}};
    while (exp)
    {
        if (exp&1)
            matrix_mulp(res,trans);
        matrix_mulp(trans,trans);
        exp>>=1;
    }
    //copy res to trans
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
            trans[i][j]=res[i][j];
    }
}

void solve()
{ 
    //observation: (by Lames-Knuth theorem) the pairs of 2 nos are consecutive pairs of fibonacci sequence
    //n=0 (edge case) least is (0,0), sum=0
    //n=1 (edge case) least is (1,1), sum=2 
    //n=2 -> (3,2) -> sum=5
    //n=3 -> (5,3) -> sum=8
    //n=4 -> (8,5) -> sum=13
    //hence using matrix exponentiation for finding term of recurence relation in O(logn)
    //recurence relation: F(n) = F(n-1) + F(n-2), for n>=2
    //F(0)=2, F(1)=3
    //transition matrix = {{0,1},{1,1}}
    ll n;
    cin>>n;
    ll a=2,b=3;
    if (n==0)
    {
        cout<<0;
        return;
    }
    if (n==1)
    {
        cout<<2;
        return;
    }
    ll trans[2][2]={{0,1},{1,1}};
    binMatrixExp(trans,n-1);
    ll ans=((a*trans[0][1])%M + (b*trans[1][1])%M)%M;
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
