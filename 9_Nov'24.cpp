#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 3133:- Minimum Array End
// You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

// Return the minimum possible value of nums[n - 1].

//CODE:-
//APPROACH 1:- 
class Solution {
public:
    long long minEnd(int n, int x) {
        int count=1;
        int num=x; //1st num of the array has to be the x itself
        while(count<n){
            if(((num+1) & x) == x){ //if num+1's AND is == x our num is num+1
                num=num+1;
            }
            else{
                num=(num+1|x); //else take an OR for num+1 and x
            }
            count++;
        }
        return num;
    }
};
//Working Code(same but reduced computations)
class Solution {
public:
    long long minEnd(int n, int x) {
        int count=1;
        long long num=x;
        while(count<n){
            num=(num+1|x);
            count++;
        }
        return num;
    }
};

//Dry run
// example we have x=7 , n=2
// num=7
// so our result arr = [7,_]
// now lets try if 7+1&x==x which is false
// so we take OR of 7+1 which is 8|7 which is 15
// 15 is our new num and our result arr is [7,15] o/p = 15
// why take or? because 
// 1000 - 8
// 0111 - 7
// or
// 1111 - 15
