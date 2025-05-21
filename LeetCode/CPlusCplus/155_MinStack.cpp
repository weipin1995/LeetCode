/*

155. Min Stack

Design a stack class that supports the push, pop, top, and getMin operations.

- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

Each function should run in O(1) time.


Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]
Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1


Constraints:
-2^31 <= val <= 2^31 - 1.
pop, top and getMin will always be called on non-empty stacks.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    
    MinStack() {

    }

    void push(int val) {
        stk.push(val);

        if (minStk.empty()) {
            minStk.push(val);
        } else {
            minStk.push(min(val, minStk.top()));
        }
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};


void runExample(const string& label) {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    minStack.getMin(); // return 0
    minStack.pop();
    minStack.top();    // return 2
    minStack.getMin(); // return 1

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: [\"MinStack\", \"push\", 1, \"push\", 2, \"push\", 0, \"getMin\", \"pop\", \"top\", \"getMin\"]\n";

    // Print Output Vector<int>
    cout << "Output: [null,null,null,null,0,null,2,1]\n";
}

int main() {
    runExample("Example 1");

    return 0;
}