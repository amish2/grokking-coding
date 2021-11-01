#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define sz(x) x.size()
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define F(i, n) for (int i = 0; i < n; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define INC(x,y) FOR(1, x, y)

typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int  ulli;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;


#ifdef AMISH_DEBUG
#include "/home/amish/code/setup/amish_debug.h"
#else
#define debug(...)
#endif

//***********************CODE GOES BELOW************************

int RWT(vector<int> v)
{
    vector<int> maxL(v.size()), maxR(v.size());

    maxL[0] = v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(maxL[i-1] < v[i])
            maxL[i] = v[i];
        else
            maxL[i] = maxL[i-1];
    }
    

}

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    // #ifdef AMISH_DEBUG
    cin.tie(NULL);
    // #endif
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
