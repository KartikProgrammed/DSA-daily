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
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

// 2145. Count the Hidden Sequences
// You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].
// You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.
// For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
// [3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
// [5, 6, 3, 7] is not possible since it contains an element greater than 6.
// [1, 2, 3, 4] is not possible since the differences are not correct.
// Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.


// APPROACH:-
//Brute force

//CODE:-
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int res=0;
        for(int i=lower;i<=upper;i++){
            bool succ=true;
            int prev=i;
            for(int j=0;j<differences.size();j++){
                int next=prev+differences[j];
                if(next>upper || next<lower){
                    succ=false;
                    break;
                }
                prev=next;
            }
            if(succ){
                res++;
            }
        }
        return res;
    }
};

//APPROACH:-
//Optimized brute force, using maths

//CODE:-
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int maxval=0;
        int minval=0;
        int curr=0;
        for(int i=0;i<differences.size();i++){
            curr=curr+differences[i];
            maxval=max(curr,maxval);
            minval=min(curr,minval);
            if((upper-maxval)-(lower-minval)+1<=0){
                return 0;
            }
        }
        return (upper-maxval)-(lower-minval)+1;
    }
};