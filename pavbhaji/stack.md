# Stacks

## 1. Intro & Identification

Follwing topics based problems have similar problem patterns :

- Stack
- Heap
- Back-tracking
- DP (Dyn. Progg.)

In case of stack :
**7 PARENT Questions as follows :**

- Nearest Greater to left
- Nearest Greater to right -> (_Next largest element_)
- Nearest Smaller to left -> (_Next smallest element_)
- Nearest Smaller to right
- _Stock Span Problem_
- Maximum Area of Histogram
- _Maximum area of Rectangle in a Binary Matrix_

**6 Conceptual Problems :**

- Rain Water Trapping
- Implementing a Min. Stack
- Implement stack using Heap
- The celebrity problem
- Longest valid parenthesis
- Iterative _Tower of Hanoi_

## Identification

- Array hoga mostly
- Q. with array are mostly based on : Stacks or Heap
  - Heap generally deals with feels of sorting
- Brute force of this types of problems : is different from normal
  - _Dependant_ O(n^2) Loops
    ```C++
    for (int i=0 ;i<n; i++)
        for(int j=0; j<i; j++)
    ```
  - **4** such possible cases :
    ```C++
    j -> 0 to i ; j++
    j -> i to 0 ; j--
    j -> i to n ; j++
    j -> n to i ; j--
    ```
- Therefore, on finding such cases : There exists an improvised version using STACKS

_**TRICK :**_   
Direction of O(n^2) Brute force is : 
```
           ->
          -->
         --->
        ---->
       ----->
      ------>
    -------->  
```
Therfore, for O(n) stack, the direction is 
```
<---------
```
-------

## 2. NGR

_Focus more on **approach** than the problem solution_

#### Problem :

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Eg: ar[] = {1, 3, 0, 0, 1, 2, 4}  
Ans = {3, 4, 1, 1, 2, 4, -1}

### Identification

Brute Force :
for each i, j goes from i+1 to n; till it finds an element greater than i and then breaks.
So, we have dependant loop in Brute Force => Stack Lagaoo...

### Stack Use

Eg: ar[] = {1, 3, 2, 4}  
Ans = {3, 4, 4, -1}

 * Suppose we are at '3' : 
 * Array contents need to be put in stack in reverse order *(as we check for '0' first and Stack works LIFO)*
 * Now pop stack till a greater element is found ; if stack goes empty w/o finding an larger element (no greater element on RIGHT side) ; output = -1
 * Starting a i = n-1; '4' is at end and Stack has its right array. Since its empty, ans = -1 for '4'
 * Push 4 in stack
 * Now see for i = n-2; stack top = '4' is greater , so ans = '4' and push '2' in stack.
 * Now stack is  : 4 > 2 >|  ,  now we get answer after popping '2'. ans = '4'  and push 3 in stack
  * _'2' can be safely removed as we know that the element ot push into stack later is more than that_
  * Stack is : 4 > 3 >|  ,  now stack top = '3'> '1' so , ans = 3
  *  LOOP DONE => answers recieved in vector in reverse form, so reverse it and return

Time Complexity : **O(n)** , Space Complexity : **O(n)** ;

### CODE : 
```C++
vector<int> NGR (vector<int> v)
{
    vector<int> a;
    stack<int> s;
    for(int i= v.size() - 1; i>=0; i--)
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top() > v[i])
                a.push_back(s.top());

            else //s.top() => v[i]
            {
                while(s.size() > 0 && s.top() <= v[i])
                {
                    s.pop();
                }

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top());
            }
        }

        s.push(v[i]);
    }
    reverse(a.begin(), a.end());
    return a;
}
```

> Diye gaye existing code ko pehchan kar usko improvise or edit krke naya variation solve krna sikho.  
> Nobody expects you to write a great algo or code base from scratch all by yourself

-------------------------------


## 3. NGL (Nearest Greater to Left)

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Given an array of integers, find the closest (not considering distance, but value) greater on left of every element. If an element has no greater on the left side, print -1.

Eg: ar[] = {1, 3, 2, 4}  
Ans = {-1, -1, 3, -1}

### Identification

Brute Force :
for each i in 0 to n , j goes from i-1 to 0 ; till it finds an element greater than i and then breaks.
So, we have dependant loop in Brute Force => Stack Lagaoo...

### Stack Use

Eg: ar[] = {1, 3, 2, 4}  
Ans = {-1, -1, 3, -1}

 * Initially, stack = >|
 * ans = -1 as stack empty; push '1' in stack
 * Stack = 1 >|  , now '1' is less than '3', so stack goes empty ans = -1, and  '3' is then pushed
 * Stack = 3 >|  , now '2' < '3' => ans = 3; push '2'
 * Stack = 3 > 2 >| , now no element in stack is more than '4' => stack goes empty , ans = -1 ; push '4'
 * LOOP DONE ; ans is stored in vector / array ; output correspondingly 

### CHANGES : 
 - Direction is Left to Right
 - Ans Vector should not be reversed

### CODE : 
```C++
vector<int> NGL (vector<int> v)
{
    vector<int> a;
    stack<int> s;
    for(int i= 0; i< v.size(); i++) // ONLY CHANGE FROM PREV VERSION
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top() > v[i])
                a.push_back(s.top());

            else //s.top() <= v[i]
            {
                while(s.size() > 0 && s.top() <= v[i])
                {
                    s.pop();
                }

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top());
            }
        }

        s.push(v[i]);
    }
    return a;
}
```  
-------------------------------
## 4. NSL (Nearest Smaller to Left)

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Given an array of integers, find the closest (not considering distance, but value) smaller on left of every element. If an element has no smaller on the left side, print -1.

Eg: ar[] = {4, 5, 2, 10, 8}  
Ans      = {-1, 4, -1, 2, 2}

### Identification

Brute Force :
for each i in 0 to n , j goes from i-1 to 0 ; till it finds an element *smaller* than i and then breaks.
So, we have dependant loop in Brute Force => Stack Lagaoo...

### Stack Use

Eg: ar[] = {4, 5, 2, 10, 8}  
Ans      = {-1, 4, -1, 2, 2}

 * Traversal of the solutin is almost similiar. 
 * Therefore, *SKIPPED* ...   


### CHANGES : 
 - look for smaller instead of greater 

### CODE : 
```C++
vector<int> NSL (vector<int> v)
{
    vector<int> a;
    stack<int> s;
    for(int i= 0; i< v.size(); i++) 
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top() < v[i])  // CHANGE FROM PREV VERSION
                a.push_back(s.top());

            else //s.top() >= v[i]
            {
                while(s.size() > 0 && s.top() <= v[i])  // CHANGE FROM PREV VERSION
                {
                    s.pop();
                }

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top());
            }
        }

        s.push(v[i]);
    }
    return a;
}
```
--------------------------------

## 5. NSR (Nearest Smaller to Right)

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Given an array of integers, find the closest (not considering distance, but value) smaller on right of every element. If an element has no smaller on the right side, print -1.

Eg: ar[] = {4, 5, 2, 10, 8}  
Ans      = {2, 2, -1, 8, -1}

### Identification

Brute Force :
for each i in 0 to n , j goes from i+1 to n-1 ; till it finds an element *smaller* than i and then breaks.
So, we have dependant loop in Brute Force => Stack Lagaoo...

### Stack Use

Eg: ar[] = {4, 5, 2, 10, 8}  
Ans      = {2, 2, -1, 8, -1}

 * Since we start at '4' , first thing we compare for is '5'. But stack uses LIFO => we traverse in REVERSE Direction
 * Traversal of the solutin is almost similiar. 
 * Therefore, *SKIPPED* ...


### CHANGES : 
 - Direction of Loop : Right to Left
 - Reverse vector before returning


### CODE : 
```C++
vector<int> NSL (vector<int> v)
{
    vector<int> a;
    stack<int> s;
    for(int i= v.size(); i >= 0 ; i--) 
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top() < v[i])  // CHANGE FROM PREV VERSION
                a.push_back(s.top());

            else //s.top() >= v[i]
            {
                while(s.size() > 0 && s.top() <= v[i])  // CHANGE FROM PREV VERSION
                {
                    s.pop();
                }

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top());
            }
        }

        s.push(v[i]);
    }
    reverse(a.begin(), a.end());
    return a;
}
```
--------------------------------

## 6. Stock Span Problem

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.  

Eg : ar[] = {100, 80, 60, 70, 60, 75, 85}
Ans       = {1, 1, 1, 2, 1, 4, 6}

### Identification
This seems to be similar to the previous type 1 , as in brute force soltion, for each i in 0 to n; j goes from i-1 to 0; till it finds an element greater than i and then breaks.
So, we have dependant loop in Brute Force => Stack Lagaoo...

### Similarity : NGL
We stop counting when we find the nearest greater on the left.
Therefore, answer for a particular index (say , i) = difference between its index and the index of its NGL.  
 
We maintain a vector that stores the indices of NGL of each element of array. Answer is the corresponding difference with its indices.

* In Stack ,instead of ints, we now store (int, int) pairs that are basically (NGL, index)  

 
### CODE : 
```C++
vector<int> NGL_index(vector<int> v)
{
    vector<int> a;
    stack<pair<int, int>> s;
    for(int i= 0; i< v.size(); i++)
    {
        if(s.size()==0)
            a.push_back(-1);
        
        else if (s.size() > 0)
        {
            if(s.top().first > v[i])  //compare with NGL (first)
                a.push_back(s.top().second);  // push index of the NGL here

            else //s.top() <= v[i]
            {
                while(s.size() > 0 && s.top().first <= v[i]) //compare with NGL (first)
                {
                    s.pop();
                }

                if(s.size() == 0)
                    a.push_back(-1);

                else
                    a.push_back(s.top().second);    // push index of the NGL here
            }
        }

        s.push( make_pair(v[i],i) );  // push pair
    }
    return a;
}
```  
-------------------------------

## 7. Maximum Area of Histogram

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Eg : ar[] = {6,2,5.4,5,1,6}
Ans       = 12

### Similarity
Similar to Stock Span.  
We need to find till where the particulaar columns height is alteast present. Therefore, we need the index of NSL and NSR of current column.  
So, width of that rectangle is (NSR - NSL - 1) and height is value of that column. Store this rect. area for each of the elements and output the maximum.

We need to maintain NSR and NSL for each element of Space required is  O(n).

```C++

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

```

----------------------

## 8. Maximum area of Rectangle in a Binary Matrix

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
```Eg:
Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0
Output :  8 
```

### Similarity : MAH (Max Area of Histogram)
We found are of rect in MAH, similarly here also we need to find the same, just the difference is that we are given a 2D matrix input.

So, now we convert each row into a histogram of its own. The answer will we the max of all the MAH from the histograms we made.
In this case the histograms look like : 
```     
        0 1 1 0
        1 2 2 1
        2 3 3 2
        3 4 0 0
```

Therefore, max MAH is of row 2 which is 8.
```C++
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
```

-----------------------------------------------------------------

## 9. Rain Water Trapping

_Focus more on **approach** than the problem solution_  

-=>  _**LOOK at the SIMILARITY**_ <=-


#### Problem :

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Eg: a[] = {3,0,0,2,0,4}  
Ans = 10


### Similarity : ???

### Observation
We see that the amount of water on top of any building is dependent on the max height of the buildings on the either side of it.  
In fact, it is the difference in the (height of the building) and (the min of (the max height on either side) ).
```C++
W[i] = min(maxR, maxL) - h[i]
```
As in the eg:
```
   0    3   3    1    3  ____
 ____                   |    |
|    |         ____     |    |
|    |        |    |    |    |
|    |________|    |____|    |
```
Therefore we need to find maxR and maxL for each of the element in the array. **Surprise !!! NO STACKS USED**
```C++

```


----------------------
Author : [Amish Saxena](github.com/amishsaxena)
