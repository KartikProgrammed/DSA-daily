#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 2843. Count Symmetric Integers
// You are given two positive integers low and high.
// An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
// Return the number of symmetric integers in the range [low, high].

//APPROACH:-
//consider every no. b/w low and high and test for symmetry

//CODE:-
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        while(low<=high){
            string curr=to_string(low);
            int len=curr.length();
            if(len%2!=0){
                low++;
                continue;
            }
            int pre=0;
            int suf=0;
            for(int i=0;i<len/2;i++){
                pre+=curr[i];
                suf+=curr[(len/2)+i];
            }
            if(pre==suf){
                count++;
            }
            low++;
        }
        return count;
    }
};