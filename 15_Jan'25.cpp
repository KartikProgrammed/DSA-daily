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

//2429. Minimize XOR
// Given two positive integers num1 and num2, find the positive integer x such that:

// x has the same number of set bits as num2, and
// The value x XOR num1 is minimal.
// Note that XOR is the bitwise XOR operation.

// Return the integer x. The test cases are generated such that x is uniquely determined.

// The number of set bits of an integer is the number of 1's in its binary representation.


//APPROACH:-
//set unset bits

//CODE:-
class Solution {
public:
    bool isSet(int &num,int bit){
        return num&(1<<bit);
    }
    bool setBit(int &num,int bit){
        return num|= (1<<bit);
    }
    bool unsetBit(int &num,int bit){
        return num&= ~(1<<bit);
    }

    int countset(int num){
        int count=0;
        while(num>0){
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int x=num1;
        int currbits=countset(num1);
        int reqbits=countset(num2);
        int bit=0;
        if(currbits==reqbits){
            return num1;
        }
        if(currbits<reqbits){
            while(currbits<reqbits){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    currbits++;
                }
                bit++;
            }
        }
        else if(currbits>reqbits){
            while(currbits>reqbits){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    currbits--;
                }
                bit++;
            }
        }
        return x;
    }
};