Selection-Problem
===
Use "quick sort (QS)" and "prune &amp; search (PS)"  to sort the given n numbers in ascending order and pick out the k-th number from the sorted array

# Time complexity (prospect)

| quick sort (QS) | prune &amp; search (PS) |
| --------------- | ----------------------- |
| O(n log n)      | O(n)                    |

# How to run?
1. Environments 
    * c++ compile with g++
    * macOS Catalina 10.15.5
    * c++11 standard
2. Compile
    * `$ g++ -std=c++11 -o quick_sort.exe quick_sort.cpp`
    * `$ g++ -std=c++11 -o prune_and_search.exe prune_and_search.cpp`
3. Execution
    * `$ ./quick_sort.exe data/input.txt`
    * `$ ./prune_and_search.exe data/input.txt`
4. Data generation (optional)
    * `$ python data_generation.py`
    * Input size (i) is  10000 to 30000 in steps 1000
    * Random list(unsorted data) is integers with range [1,20000]

# Input / Output
* Preview input.txt
```cpp
// with n numbers and locate the k-th element
10000 4159
// unsorted data below
8783 16199 7648 14201 12254 3732 13701 840 8477 5175 9408 7595 9652 19317 3908  ...
```

* Preview QS.txt
```cpp
8350 // the number of k-th element
0.002023 // the program execution time
```

# Experimental results
* Quick sort (QS)

| case\N= | 10000       | 11000       | 12000       | 13000       | 14000       | 15000       | 16000       | 17000       | 18000       | 19000       | 20000       | 21000       | 22000       | 23000       | 24000       | 25000       | 26000       | 27000       | 28000       | 29000       | 30000       |
| ------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| case 1  | 0\.000242 s | 0\.000287 s | 0\.000350 s | 0\.000575 s | 0\.000528 s | 0\.000501 s | 0\.000293 s | 0\.000440 s | 0\.000482 s | 0\.000673 s | 0\.000952 s | 0\.000718 s | 0\.000312 s | 0\.000793 s | 0\.000772 s | 0\.000834 s | 0\.000669 s | 0\.000753 s | 0\.000589 s | 0\.000755 s | 0\.000734 s |
| case 2  | 0\.000222 s | 0\.000325 s | 0\.000522 s | 0\.000319 s | 0\.000295 s | 0\.000469 s | 0\.000556 s | 0\.000192 s | 0\.001070 s | 0\.000590 s | 0\.000790 s | 0\.000600 s | 0\.000722 s | 0\.000152 s | 0\.001205 s | 0\.000948 s | 0\.000687 s | 0\.000681 s | 0\.001034 s | 0\.000385 s | 0\.000971 s |
| case 3  | 0\.000241 s | 0\.000281 s | 0\.000448 s | 0\.000203 s | 0\.000697 s | 0\.000633 s | 0\.000644 s | 0\.000851 s | 0\.000664 s | 0\.000611 s | 0\.000643 s | 0\.000354 s | 0\.000724 s | 0\.000789 s | 0\.000530 s | 0\.000836 s | 0\.000856 s | 0\.000749 s | 0\.001103 s | 0\.000549 s | 0\.000682 s |
| Average | 0\.000235 s | 0\.000298 s | 0\.00044 s  | 0\.000366 s | 0\.000507 s | 0\.000534 s | 0\.000498 s | 0\.000494 s | 0\.000739 s | 0\.000625 s | 0\.000795 s | 0\.000557 s | 0\.000586 s | 0\.000578 s | 0\.000836 s | 0\.000873 s | 0\.000737 s | 0\.000728 s | 0\.000909 s | 0\.000563 s | 0\.000796 s |


* Prune and search (PS)

| case\N= | 10000       | 11000       | 12000       | 13000       | 14000       | 15000       | 16000       | 17000       | 18000       | 19000       | 20000       | 21000       | 22000       | 23000       | 24000       | 25000       | 26000       | 27000       | 28000       | 29000       | 30000       |
| ------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| case 1  | 0\.000630 s | 0\.000865 s | 0\.000831 s | 0\.000960 s | 0\.000920 s | 0\.001025 s | 0\.000944 s | 0\.000985 s | 0\.001146 s | 0\.001216 s | 0\.001170 s | 0\.001444 s | 0\.001259 s | 0\.001355 s | 0\.001395 s | 0\.001477 s | 0\.001636 s | 0\.001859 s | 0\.001612 s | 0\.002653 s | 0\.001791 s |
| case 2  | 0\.000681 s | 0\.000704 s | 0\.000858 s | 0\.000811 s | 0\.000904 s | 0\.001005 s | 0\.000966 s | 0\.001023 s | 0\.001050 s | 0\.001298 s | 0\.001200 s | 0\.001643 s | 0\.001332 s | 0\.001306 s | 0\.001532 s | 0\.001454 s | 0\.001895 s | 0\.001579 s | 0\.001597 s | 0\.001972 s | 0\.001962 s |
| case 3  | 0\.000713 s | 0\.000823 s | 0\.000776 s | 0\.000930 s | 0\.001001 s | 0\.000935 s | 0\.000969 s | 0\.001099 s | 0\.001069 s | 0\.001118 s | 0\.001567 s | 0\.001231 s | 0\.001385 s | 0\.001450 s | 0\.001521 s | 0\.001400 s | 0\.001926 s | 0\.001566 s | 0\.002375 s | 0\.001607 s | 0\.001755 s |
| Average | 0\.000675 s | 0\.000797 s | 0\.000822 s | 0\.0009 s   | 0\.000942 s | 0\.000988 s | 0\.00096 s  | 0\.001036 s | 0\.001088 s | 0\.001211 s | 0\.001312 s | 0\.001439 s | 0\.001325 s | 0\.00137 s  | 0\.001483 s | 0\.001444 s | 0\.001819 s | 0\.001668 s | 0\.001861 s | 0\.002077 s | 0\.001836 s |


# References
1. quick sort (main): https://www.geeksforgeeks.org/quickselect-algorithm/
2. prune and search: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/
3. prune and search (concept): https://www.ptt.cc/bbs/Grad-ProbAsk/M.1255803641.A.D78.html
4. prune and search (main): http://mypaper.pchome.com.tw/zerojudge/post/1325695799

###### tags: `Algorithm`
