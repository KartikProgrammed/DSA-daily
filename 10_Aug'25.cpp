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

//869. Reordered Power of 2

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
// Return true if and only if we can do this so that the resulting number is a power of two.

//Approach:
// 1. Generate all powers of 2 up to 10^9 and store them
// 2. For each power of 2, convert it to a string and sort the digits
// 3. Convert the input number to a string, sort its digits, and check if it matches any of the sorted powers of 2

//Code:
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string curr=to_string(n);
        sort(curr.begin(),curr.end());

        for(int i=0;i<31;i++){
            int temp=1<<i;
            string tempstr=to_string(temp);
            sort(tempstr.begin(),tempstr.end());
            if(tempstr==curr){
                return true;
            }
        }
        return false;
    }
};