#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 3011:- Find if array can be Sorted
// You are given a 0-indexed array of positive integers nums.

// In one operation, you can swap any two adjacent elements if they have the same number of 
// set bits
// . You are allowed to do this operation any number of times (including zero).

// Return true if you can sort the array, else return false.

//CODE:-
//Approach:- create a vector for set bits, apply bubble sort technique to check if it is sortable, sort max and then check if it is actually sorted
#include <vector>
using namespace std;

class Solution {
public:
    int setBits(int num) {
        int count = 0;
        for (int i = 31; i >= 0; --i) {
            if ((num >> i) & 1) {
                count++;
            }
        }
        return count;
    }

    bool check(const vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        vector<int> count(nums.size());
        for (int j = 0; j < nums.size(); j++) {
            count[j] = setBits(nums[j]);
        }

        int n = nums.size();
        int k = 0;
        while (k < n) {
            for (int i = 1; i < n; i++) {
                if (count[i] == count[i - 1] && nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);  
                }
            }
            if (check(nums)) {
                return true;
            }
            k++;
        }
        return false;
    }
};