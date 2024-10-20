#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

// Problem 216:-Combination Sum III
//  Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// APPOACH:- using a set we can sort the numbers and also avoid duplicates
// so i'll be using a set initially and converting it to vector after the computations since thats the return type required

// CODE:-
class Solution
{
public:
    void recursion(set<set<int>> &result, int tot, set<int> &db, int k, int n)
    {
        if (db.size() == k && tot == n)
        {
            result.insert(db); // if the size matches k and the sum matches n push it into the set of sets result
            return;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (db.size() >= k || tot > n)
            { // break if any of the conditions go wrong
                break;
            }
            if (db.find(i) != db.end())
            {
                continue; // if an element already in the set, continue(so that it isnt added to the total in the recursion call)
            }
            else
            {
                db.insert(i);                         // insert into the db set
                recursion(result, tot + i, db, k, n); // add the total to i as new total and run recursion
                db.erase(i);                          // backtracking
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        set<set<int>> result; // easier to satisfy the sorted condition and no duplicate condition
        set<int> db;
        recursion(result, 0, db, k, n);
        vector<vector<int>> resultVector;
        for (const auto &innerSet : result)
        { // conversion of set to vector since vector is the return type
            resultVector.push_back(vector<int>(innerSet.begin(), innerSet.end()));
        }
        return resultVector;
    }
};

// DAILY PROBLEM 1106:- Parsing a Boolean Expression
// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
//  't' that evaluates to true.
//  'f' that evaluates to false.
//  '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
//  '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
//  '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
//  Given a string expression that represents a boolean expression, return the evaluation of that expression.
//  It is guaranteed that the given expression is valid and follows the given rules.

// CODE:-
class Solution
{
public:
    bool parseBoolExpr(string exp)
    {
        stack<char> stk;
        for (char ch : exp)
        {
            if (ch == ',')
                continue;
            if (ch == ')')
            {
                bool t = false, f = false;
                while (stk.top() != '(')
                {
                    t |= stk.top() == 't';
                    f |= stk.top() == 'f';
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                stk.push(op == '!' ? (t ? 'f' : 't') : (op == '&' ? (f ? 'f' : 't') : (t ? 't' : 'f')));
            }
            else
                stk.push(ch);
        }
        return stk.top() == 't';
    }
};

// Problem 24:- swap nodes in pairs
//  Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *fnode = head;
        ListNode *snode = head->next;
        fnode->next = swapPairs(snode->next);
        snode->next = fnode;
        return snode;
    }
};