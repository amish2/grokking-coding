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
vector<int> NSL_index(vector<int> v)
{
    vector<int> a;
    stack<pair<int, int>> s;
    for(int i= 0; i< v.size(); i++)
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top().first < v[i])  
                a.push_back(s.top().second);  

            else //s.top() >= v[i]
            {
                while(s.size() > 0 && s.top().first >= v[i]) 
                    s.pop();

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top().second);  
            }
        }
        s.push( make_pair(v[i],i) );
    }
    return a;
}

vector<int> NSR_index(vector<int> v)
{
    vector<int> a;
    stack<pair<int, int>> s;
    for(int i= v.size() -1 ; i>= 0; i--)
    {
        if(s.size()==0)
            a.push_back(v.size());
        
        else if (s.size() > 0)
        {
            if(s.top().first < v[i])  
                a.push_back(s.top().second);  

            else //s.top() >= v[i]
            {
                while(s.size() > 0 && s.top().first >= v[i]) 
                    s.pop();

                if(s.size() == 0)
                    a.push_back(v.size());

                else
                    a.push_back(s.top().second);  
            }
        }
        s.push( make_pair(v[i],i) );
    }
    reverse(a.begin(), a.end());
    return a;
}

int MAH(vector <int> v)
{
    vector<int> left = NSL_index(v);
    vector<int> right = NSR_index(v);
    debug(left);
    debug(right);

    for(int i=0; i<right.size(); i++)
        if(right[i] == -1)
            right[i] = v.size();

    vector<int> ans(v.size());

    for(int i=0; i<v.size(); i++)
        ans[i] = ( (right[i] - left[i] -1) * v[i] );
    
    int mx = 0;
    for(int i=0; i<v.size(); i++)
        mx = max(mx, ans[i]);

    return mx;
}


int MAR(vector<vector<int>> m)
{
    vector<int> v;
    int mx = 0;
    for(int j=0; j<m[0].size(); j++)
        v.push_back(m[0][j]);
    
    mx = max(mx, MAH(v));   

    for(int i=1; i<m.size(); i++)
    {
        for(int j=0; j< m[0].size(); j++)
        {
            if(m[i][j] == 1)
                v[j] += m[i][j];
            else
                v[j] = 0;
        }
        mx = max(mx, MAH(v));
    }
    return mx;
}

void solve()
{   
    vi v = {6,2,5,4,5,1,6};
    vvi m ={{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
    int ans = MAR(m);
    debug(ans);

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
