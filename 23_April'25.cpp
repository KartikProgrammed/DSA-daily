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
#include <numeric>

using namespace std;

// 1399. Count Largest Group
// You are given an integer n.
// Each number from 1 to n is grouped according to the sum of its digits.
// Return the number of groups that have the largest size.

//APPROACH:-
//store the dig sum of all numbers till n in a map 
//find the max size of the group and return the count of groups with that size

//CODE:-
class Solution {
public:
    int digsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> map;
        for(int i=1;i<=n;i++){
            int sm=digsum(i);
            map[sm]++;
        }
        int res=0;
        auto st=map.begin()->first;
        int maxi=INT_MIN;
        for(auto &it:map){
            maxi=max(maxi,it.second);
        }
        for(auto &it:map){
            if(it.second==maxi){
                res++;
            }
        }
        return res;
    }
};