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

//342. Power of Four
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

// Approach:
// 1. Check if n is greater than 0.
// 2. Check if n is divisible by 4 in a loop until n becomes 1.
// 3. If n becomes 1, return true; otherwise, return false.

// Code:
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4!=0){
                return false;
            }
            n/=4;
        }
        if(n!=1){
            return false;
        }
        return true;
    }
};