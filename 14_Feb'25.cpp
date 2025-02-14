#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//1352. Product of the Last K Numbers
// Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

// Implement the ProductOfNumbers class:

// ProductOfNumbers() Initializes the object with an empty stream.
// void add(int num) Appends the integer num to the stream.
// int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
// The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

//APPROACH:-
//create an array and push elements whatever are added
//compute the product of last k elements

//CODE:- 
class ProductOfNumbers {
    private:
        vector<int> vec;
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            vec.push_back(num);
        }
        
        int getProduct(int k) {
            int res=1;
            int st=vec.size()-k;
            for(int i=st;i<vec.size();i++){
                res*=vec[i];
            }
            return res;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

//APPROACH 2:-
//compute the product of k last elements while adding new elements
//the vec would be used to store the product this time

//CODE:-
class ProductOfNumbers {
    private:
        vector<int> vec;
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            for(int i=0;i<vec.size();i++){
                vec[i]=vec[i]*num;
            }
            vec.push_back(num);
        }
        
        int getProduct(int k) {
            int st=vec.size()-k;
            return vec[st];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */