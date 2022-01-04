# Sliding Window

-   Array based, 
-   Avoid repetitive addition type of problem, 
-   related to Contiguous elements

### Identification : 

Keywords like : 

-   Subarray
-   Window (Window Size) / Condn.
-   Largest/ Smallest , Sum

### Two types : 

-   Fixed Size : *Easy* 
-   Variable Size : *Medium*

## Problem List : 


Fixed Window Size : 
-   Max/Min subarray of size k
-   1st -ve in every window of size k
-   Count occurence of Anagram
-   Max of all subarray of size k
-   Max of min for every window size

Variable Window Size :
-   Largest/Smallest Subarray of sum k
-   Largest substring of k distinct characters
-   Length of Largest SUbstring with NO repeating Characters
-   Pick Toy Problem
-   Minimum Window Substring

--------------------

## Max subarray of size k

> Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

```C++
int max_sum_window(int arr[], int n, int k)
{
    int sum=0;
    int i=0, j=0;
    int mx = INT_MIN;
    
    while(j<arr.size())
    {
        sum += arr[j];

        if(j-i+1 < k) //window not yet made
        {
            j++;
        }
        else
        {
            // calculations
            mx = max(mx, sum); 
            // slide the window
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return mx;
}
```

---------------------

## 1st -ve in every window of size k

> Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

```C++

vi first_neg_int(vi arr, int n, int k)
{
    int i=0, j=0;
    vi ans;
    queue<int> q;
    while(j<n)
    {
        if(arr[j] < 0)
            q.push(arr[j]);

        if(j-i+1 < k) //window not yet made
            j++;
        else
        {
            // calculations
            if(q.size() == 0)
                ans.pb(0);
            
            else 
            {
                ans.pb(q.front());
                if(arr[i] == q.front())
                    q.pop();
            }
            // slide the window
            i++; j++;
        }
    }
    return ans;
}
```

------------------

## Count Occurrences Of Anagrams 

-   Sliding window length = length of given pattern string
> Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

**Code pattern until now**
```C++

while(j<n)
{
    //base calcultions

    //make window
    if(j-i+1<k)
        j++;
    
    else // (j-i+1==k)
    {
        // ans calculations
        // calculations to remove i and maintain window size
        // slide
    }
}

```

-   Calculating anagrams = `n!` -> BAD
-   Need to compare only that the strings have same number of corresponding alphabets. Therefore, CAN USE `maps`.
-   Now to compare maps, we do in reverse count manner, and maintain the number of discripancies in the maps using a `count` variable. 

Steps

1.  Make `map` for the Pattern string
2.  `count=map.size()`
3.  while loop ...
4.  Base Calculations : check if `ar[j]` is in map. If yes then dec corresponding count; if that count is `0`, reduce `count`.
5.  Ans is incremented if we find `count=0` for a window
6.  For sliding, if `ar[i]` was in the window, but now its slided out; increase the corresponding count in the `map`.

```C++
int count_anagram_occr(string t, string p)
{
    int l = p.size();
    int n = t.size();
    int i=0, j=0;
    int ans=0;

    map<char,int> mp;
    for(int k=0; k<n; k++)
        mp[p[i]]++;
    
    int cnt = mp.size();   
    int k = p.size(); 

    while(j<n)
    {
        //base calculations
        mp[t[j]]--;

        if(mp[t[j]] == 0)
            count--;
        
        if(j - i + 1 < k) // make window
            j++;
        else 
        {
            // ans calculations
            if(count==0)
                ans++;
            
            //slide window
            if(m.find(t[i]) != m.end())
            {
                m[t[i]]++;
                // this letter was fully found earlier but now it may not be,  as its slided out
                if(m[t[i]] == 1) 
                    count++;
            }
            i++; j++;
        }
    }

    return ans;
}

```

------------
## Maximum of all subarrays of size k

> Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

-   Find max in the first window and then go on comparing as we slide ...
-   But keeping track of only the mmax wont help (in case the max is slided out). Therefore, we keep the candidates that can become max in future in a queue.

```C++
vector<int> max_all_subarr(vector<int> arr, int n, int k)
{
    deque<int> q;
    int i=0, j=0;
    vector<int> ans;

    while(j<n)
    {
        //base calc
        //push ar[j] in q; but before it, remove unneccary vals in q
        while(!q.empty() && q.back()<arr[j])
            q.pop_back();

        q.push_back(arr[j]);

        // window
        if(j-i+1 < k)
            j++;
        else
        {
            ans.push_back(q.front());

            if(q.front() == arr[i])
                q.pop_front();

            i++; j++;
        }    
    }

    return ans;
}
```
------------------
## *Variable Size Sliding Window*

```
Earlier :
    Window size -> Given
    Sum         -> Maximize
    
Now :
    Sum         -> Given
    Window size -> Maximize
```

-   In this case, we are done first time when we get the required conditon satisfied for first time.
-   (Instead of window size, we make window by the condition)

## Largest Subarray of Sum k

```C++
int larg_subar_sum(vector<int> arr, int k)
{
    int i=0,j=0;
    int sum = 0;
    int mx = INT_MIN;

    while (j<arr.size())
    {
        // basic calc.
        sum+=arr[j];
        // make window
        if(sum < k)
            j++;
        // window spotted
        else if(sum == k)
        {
            mx = max(mx, j-i+1);
            j++;    // to find next candidates for max ans
        }
        // maintain window
        else
        {
            while (sum>k)
            {
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}
```

> Note : Sliding won't work for NEG. INTs in here. HashMaps required for such questions.
-----------------

## General Format for Variable sliding window

```C++
while (j<arr.size())
{
    // basic calc.

    // make window
    if(condition < k)
        j++;

    // suitable window (candidate) spotted
    else if(condition == k)
    {
        // calc. for getting the ans
        j++;    // to find next candidates
    }
    // maintain window
    else
    {
        while (condition>k)
        {
            // remove calc. done for the i
            i++;
        }
        j++;
    }
}
```
---------------

## Longest Substring With K Unique Characters

>   Given a string you need to print the size of the longest possible substring that has exactly k unique characters.

-   Map is used instead of set to count for the unique values since we also need thier count as we move `i` and `j` across because there might be mutliple occurences of the values.
-   Rest is similar to the Anagram problem done previously.

```C++
int lrgst_k_uniq_substr(string s, int k)
{
    int n = s.size();
    int i=0, j=0;
    int ans = INT_MIN;
    map<char, int> mp;

    while (j<n)
    {
        mp[s[j]]++;

        if(mp.size() < k)
            j++;
        else if(mp.size() == k)
        {
            ans = max(ans, j-i+1);
            j++;    // to find next candidates
        }
        else
        {
            while (mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}
```
------------------------

## Longest Substring With Without Repeating Characters

>   Given a string s, find the length of the longest substring without repeating characters.

-   Super similar to previous one.
-   Only change is that we `don't have a condition` (k). Therefore, think..
-   We notice that the condition is as follows :
    -   All unique chars => mp.size() == window size
    -   therefore replace `k` in the prev. problem with window size`(j-i+1)`
-   Done.

```C++
int lrgst_uniq_substr(string s)
{
    int n = s.size();
    int i=0, j=0;
    int ans = INT_MIN;
    map<char, int> mp;


    while (j<n)
    {
        mp[s[j]]++;

        if(mp.size() > (j-i+1))
            j++;

        else if(mp.size() == (j-i+1))
        {
            ans = max(ans, j-i+1);
            j++;    
        }
        else
        {
            while (mp.size() < (j-i+1))
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
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
```

-   Alternatively faster soln without sliding window : 

```C++
int lengthOfLongestSubstring(string s) 
{
    vector<int> mp(256, -1);
    int maxLen = 0, start = -1;

    for (int i = 0; i != s.length(); i++) 
    {
        if (mp[s[i]] > start)
            start = mp[s[i]];

        mp[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    return maxLen;
}
```
`start` remembers the place till where the string is not required (useless). The vector is 256 for the ASCII chars in the strings and initialized as -1.

Another Nice DP based short code solution is [here](https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1730/Shortest-O(n)-DP-solution-with-explanations).

-------------

## Pick Toys

>   John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.  
> Example:   
> Input : 1 , abaccab
> Output : 


*Problem yet to be found on the internet*. ADD if FOUND. 

-   Basically the problem is same as the one of those done before...
-   Main task is to find a sub-string that has a max of 2 unique values (or chars)
-   This is a specific case of *Longest Substring With K Unique Characters* where we have `k=2`.

----------------------------------------

### ---------------------------------------------------END OF NOTES---------------------------------------------------

Author : [Amish Ashish Saxena](www.github.com/amishsaxena)  
Content referred from Aditya Verma's Youtube Playlist.