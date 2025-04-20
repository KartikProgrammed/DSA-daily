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

//781. Rabbits in Forest
// There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
// Given the array answers, return the minimum number of rabbits that could be in the forest.

//APPROACH:-
//Count the number of rabbits with the same color and return the minimum number of rabbits that could be in the forest

//CODE:-
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        for(int i=0;i<answers.size();i++){
            map[answers[i]+1]++;
        }
        int res=0;
        for(auto &it:map){
            int rem=it.second%it.first;
            int div=it.second/it.first;
            if(rem==0){
                res+=it.first*div;
            }
            else{
                res+=it.first*div+it.first;
            }
        }
        return res;
    }
};