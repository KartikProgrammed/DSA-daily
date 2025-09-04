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


//3516. Find Closest Person

// You are given three integers x, y, and z, representing the positions of three people on a number line:
// x is the position of Person 1.
// y is the position of Person 2.
// z is the position of Person 3, who does not move.
// Both Person 1 and Person 2 move toward Person 3 at the same speed.
// Determine which person reaches Person 3 first:
// Return 1 if Person 1 arrives first.
// Return 2 if Person 2 arrives first.
// Return 0 if both arrive at the same time.
// Return the result accordingly.


//Approach:-
//calculate the distance of both persons from person 3
//compare the distances and return the result accordingly

//CODE:-
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distA=abs(x-z);
        int distB=abs(y-z);
        if(distA==distB){
            return 0;
        }
        return distA<distB?1:2;
    }
};