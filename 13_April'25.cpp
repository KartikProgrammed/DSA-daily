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

//1922. Count Good Numbers
// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

//APPROACH:-
//even positions have 5 choices and odd have 4 
//multiply and find exponentially 

//CODE:-
class Solution {
public:
    const int M=1e9+7;
    long long exppower(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=exppower(a,b/2);
        long long result=(half*half) % M;

        if(b%2==1){
            result=(result*a)%M;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd=exppower(5,(n+1)/2);
        long long even=exppower(4,n/2);

        return ((long long)odd*even) %M;
    }
};