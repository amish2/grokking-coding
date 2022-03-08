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
#define INC(x, y) FOR(1, x, y)

typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

#ifdef AMISH_DEBUG
#include "/home/amish/code/setup/amish_debug.h"
#else
#define debug(...)
#endif

//***********************CODE GOES BELOW************************

int larg_subar_sum(vector<int> arr, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MIN;

    while (j < arr.size())
    {
        sum += arr[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++; // to find next candidates for max ans
        }
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int lrgst_uniq_substr(string s)
{
    int n = s.size();
    int i = 0, j = 0;
    int ans = INT_MIN;
    map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() > (j - i + 1))
            j++;

        else if (mp.size() == (j - i + 1))
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() < (j - i + 1))
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

void twoSum(vector<int> &v, int t)
{
	int n = v.size();
    mpii m;
	F(i,n) m[v[i]]++;
	
	int rem = -1;
	vector<int> ans(2);
	debug(m);
	F(i,n)
	{
		rem = t - v[i];
		debug(rem);
		if(rem == v[i])
		{
			if(m[rem] > 1)
			{
				ans[0] = i;
				v.erase(v.begin() + i);
				debug(v);
				ans[1] = find(v.begin(), v.end(), rem) - v.begin() + 1;
				break;
				// return ans;
			}
		}
		else
		{
			if(m.find(rem) != m.end())
			{
				ans[0] = i;
				ans[1] = find(v.begin(), v.end(), rem) - v.begin();
				break;
				// return ans;
			}
		}
	}
	debug(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    // #ifdef AMISH_DEBUG
    cin.tie(NULL);
    // #endif

    int n = 7;
    // vi b = {12, -1, -7, 8, -15, 30, 16, 28};
    vi b = {3,3};
    // int k = 5;
    int k = 6;
    string s = "pwwkew";
    // int ans = larg_subar_sum(b,k);
    // int ans = lrgst_uniq_substr(s);
    // cout << ans;
    twoSum(b,k);
    return 0;
}
