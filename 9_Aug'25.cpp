#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

// 231. Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

//Approach:
// divide n by 2 until it is no longer divisible by 2.
// If the result is 1, then n is a power of two.

//Code:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2!=0){
                return false;
            }
            n/=2;
        }
        if(n==1){
            return true; 
        }
        return false;
    }
};