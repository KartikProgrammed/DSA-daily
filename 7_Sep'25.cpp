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

using namespace std;


// 1304. Find N Unique Integers Sum up to Zero

// Given an integer n, return any array containing n unique integers such that they add up to 0.


//Approach:-
//Just iterate until you reach n-1 and then add counterpart of the sum you accumulated so far


//CODE:-
class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1){
            return {0};
        }
        vector<int> res(n);
        int curr=0;
        for(int i=1;i<=n-1;i++){
            res[i-1]=i;
            curr+=i;
        }
        res[n-1]=(-1*curr);
        return res;
    }
};