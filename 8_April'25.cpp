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

//3396. Minimum Number of Operations to Make Elements in Array Distinct
// You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:
// Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
// Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

//APPROACH:-
//Calculate the no. of unique elements from back
//now compute the operations

//CODE:-
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        int size=0;
        for(int i=nums.size()-1;i>=0;i--){
            map[nums[i]]++;
            if(map[nums[i]]>1){
                break;
            }
            else{
                size++;
            }
        }
        int op=nums.size()-size;
        return (op+2)/3;
    }
};