#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2601. Prime Subtraction Operation
// You are given a 0-indexed integer array nums of length n.

// You can perform the following operation as many times as you want:

// Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
// Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

// A strictly increasing array is an array whose each element is strictly greater than its preceding element.

//CODE:-
//FAILS AT TC 588 :( problem:- doesnt change random elements instead goes from 0-end
class Solution {
public:
    bool isSorted(vector<int> nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    int miniPrime(int n) {
        if (n <= 2) {
            return -1;
        }
        for (int num = n - 1; num > 1; num--) {
            bool isPrime = true;
            for (int i = 2; i <= std::sqrt(num); i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return num;
            }
        }
        return -1;
    }
    bool primeSubOperation(vector<int>& nums) {
        if(isSorted(nums)){
            return true;
        }
        for(int i=0;i<nums.size();i++){
            if(miniPrime(nums[i])==-1){
                continue;
            }
            int diff=miniPrime(nums[i]);
            nums[i]=nums[i]-diff;
            if(isSorted(nums)){
                return true;
            }
        }
        return false;
    }
};

//CODE:- works & beats 100%
#include <vector>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 
            71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
            151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
            233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 
            317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
            419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 
            503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 
            607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 
            701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 
            811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 
            911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
        };

        int n = nums.size();
        int l = 0, h = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                l = nums[i] - (nums[i + 1] - 1);
                h = nums[i];
                int p = getPrime(primes, l, h);
                if (p == h) {
                    return false;
                } else {
                    nums[i] = nums[i] - p;
                }
            }
        }
        return true;
    }

private:
    int getPrime(const vector<int>& primes, int l, int h) {
        for (int prime : primes) {
            if (l <= prime && prime < h) {
                return prime;
            }
        }
        return h;
    }
};