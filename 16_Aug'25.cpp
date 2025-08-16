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

//1323. Maximum 69 Number

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Approach:
// 1. Convert the integer to a string to manipulate its digits.
// 2. Iterate through the string and change the first '6' to '9'.
// 3. Convert the string back to an integer and return it.

// Code:
class Solution {
public:
    int maximum69Number (int num) {
        if(num<10){
            return 9;
        }
        string nums=to_string(num);
        for(int i=0;i<nums.length();i++){
            if(nums[i]=='6'){
                nums[i]='9';
                break;
            }
        }
        return stoi(nums);
    }
};