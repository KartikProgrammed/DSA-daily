#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

// 2657. Find the Prefix Common Array of Two Arrays
// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

//APPROACH:-
//maintain an array of len n+1 since A,B are permutation array
//count frequencies for each map element and pushback the freq/2 if %2==0

//CODE:-
class Solution {
public:
    int prefcommon(vector<int> map){
        int count=0;
        for(int i=0;i<map.size();i++){
            if(map[i]!=0 && map[i]%2==0){
                count+=map[i]/2;
            }
        }
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> map(A.size()+1,0);
        vector<int> res;
        for(int i=0;i<A.size();i++){
            map[A[i]]++;
            map[B[i]]++;
            res.push_back(prefcommon(map));
        }
        return res;
    }
};

//APPROACH:-
//same approach but checking side by side reducing 1 for loop

//CODE:- (Beats 100%)
class Solution {
public:
    // int prefcommon(vector<int> map){
    //     int count=0;
    //     for(int i=0;i<map.size();i++){
    //         if(map[i]!=0 && map[i]%2==0){
    //             count+=map[i]/2;
    //         }
    //     }
    //     return count;
    // }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> map(A.size()+1,0);
        vector<int> res;
        int count=0;
        for(int i=0;i<A.size();i++){
            map[A[i]]++;
            if(map[A[i]]!=0 && map[A[i]]%2==0){
                count+=map[A[i]]/2;
            }
            map[B[i]]++;
            if(map[B[i]]!=0 && map[B[i]]%2==0){
                count+=map[B[i]]/2;
            }
            res.push_back(count);
        }
        return res;
    }
};