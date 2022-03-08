# Two Pointers

-   Used to solve array problems very efficiently
-   Finding two numbers in an array that satisfy a certain condition
-   Can be either ` directly ` or ` indirectly `
-   *the two-pointer technique uses a comparison of an objective function that measures a candidate’s value to rule out vast swathes of potential solutions*


### In order to use two-pointer technique, one should identify / verify the following :  

-   Need for sreaching 2/more items? Can the problem be recdeced to something like this (inderectly)
-   Does there exist an initialization of two pointers such that the rest of the algorithm can function properly for all cases?
-   Presence of a `Func` to evaluate the *Goodness* of current locations of the pointers
-   Some logic to maximize the above *Goodness*
-   Moving of the pointers **Should not** eliminate valid solutions
-   Need to *pre-process* array before using 2-pointers ?? (sorting,etc)
-   **Speed** of the pointers. Fast/Slow , Left/Right
-   Pointers are *updated* together or one by one at a time?
-   Can redundant solution candidates be removed for *Speed-ups*
-   Use of Data-Structures to help in this?
-   Extension to **3-or-more** Pointers. How to manage the relations between them...
-   If managing three or more pointers is not possible or very complex, can it be reduced to multiple two-pointer problems?

## Basic Example : 




---------------------------
### Classic problems:

-   Remove Duplicates from Sorted Array
-   Two Sum II - Input array is sorted
-   Reverse Words in a String II
-   Rotate Array
-   Valid Palindrome
-   Container With Most Water
-   Product of Array Except Self
-----------------------------