#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// ============================================================================
// WRAPPERS THAT HIDE OTHER CONTAINERS & ITERATIONS
// ============================================================================

/*
CONCEPT: Some classes are wrappers around OTHER containers (like vector, list)
They HIDE how the data is stored and HOW you iterate through it!
*/

// ============================================================================
// Custom Wrapper Class (moved before main)
// ============================================================================

class MyStack {
private:
    vector<int> data;  // HIDDEN container!
    
public:
    void push(int x) {
        data.push_back(x);
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
};

int main() {
    // =========================================================================
    // EXAMPLE 1: STACK - Wrapper around Vector/Deque
    // ============================================================================

    cout<< "\n\n=== EXAMPLE 1: STACK ===\n";
    cout << "A Stack WRAPS a vector/deque and HIDES the iteration!\n\n";
    cout << "WITHOUT WRAPPER (Raw Vector):\n";
    cout << "vector<int> v = {1, 2, 3, 4, 5};\n";
    vector<int> rawVec = {1, 2, 3, 4, 5};
    cout << "You can access: v[0]=" << rawVec[0] << ", v[2]=" << rawVec[2] << ", v[4]=" << rawVec[4] << "\n";
    cout << "You can iterate ANY direction, access ANY element\n";
    cout << "❌ PROBLEM: Chaos! No rules!\n\n";

    cout << "WITH WRAPPER (Stack - Hides everything):\n";
    cout << "stack<int> s;\n";
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Pushed 1, 2, 3\n";
    cout << "You can ONLY pop from top!\n";
    cout << "Pop: " << s.top() << "\n";
    s.pop();
    cout << "Pop: " << s.top() << "\n";
    s.pop();
    cout << "Pop: " << s.top() << "\n";
    s.pop();
    cout << "✅ BENEFIT: Strict LIFO rule! No chaos!\n";
    cout << "❌ You CAN'T iterate, CAN'T access middle, CAN'T modify\n\n";

    // ============================================================================
    // EXAMPLE 2: QUEUE - Wrapper around Deque
    // ============================================================================

    cout << "\n=== EXAMPLE 2: QUEUE ===\n";
    cout << "Queue WRAPS a deque and HIDES the iteration!\n\n";

    cout << "WITHOUT WRAPPER (Raw Deque):\n";
    cout << "deque<int> dq = {10, 20, 30, 40};\n";
    cout << "You can do ANYTHING!\n";
    cout << "dq[1] = 999;        // Modify any element\n";
    cout << "cout << dq[2];      // Access any element\n";
    cout << "for (auto x : dq) {\n";
    cout << "    cout << x << " << " ";  // Iterate any way\n";
    cout << "}\n";
    cout << "❌ Confusing! No rules!\n\n";

    cout << "WITH WRAPPER (Queue - Hides deque):\n";
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Pushed 10, 20, 30, 40\n";
    cout << "Front: " << q.front() << "\n";
    cout << "Pop: " << q.front() << "\n";
    q.pop();
    cout << "Front (now): " << q.front() << "\n";
    cout << "✅ BENEFIT: Strict FIFO rule!\n";
    cout << "❌ You CAN'T iterate, CAN'T access middle\n\n";

    // ============================================================================
    // EXAMPLE 3: PRIORITY QUEUE - Wrapper around Vector/Heap
    // ============================================================================

    cout << "\n=== EXAMPLE 3: PRIORITY QUEUE ===\n";
    cout << "Priority Queue WRAPS a heap and HIDES the iteration!\n\n";

    cout << "WITHOUT WRAPPER (Raw Vector):\n";
    cout << "vector<int> v = {5, 3, 7, 1, 9};\n";
    vector<int> rawVec2 = {5, 3, 7, 1, 9};
    cout << "Print in order: ";
    for (int x : rawVec2) cout << x << " ";
    cout << "← Random order, no structure!\n\n";

    cout << "WITH WRAPPER (Priority Queue - Hides heap):\n";
    priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(7);
    pq.push(1);
    pq.push(9);
    cout << "Pushed 5, 3, 7, 1, 9\n";
    cout << "Pop in order: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "← Automatically sorted (max to min)!\n";
    cout << "✅ BENEFIT: Automatic sorting!\n";
    cout << "❌ You CAN'T iterate, CAN'T see structure\n\n";

    // ============================================================================
    // EXAMPLE 4: Custom Wrapper - LIFO List (Stack-like)
    // ============================================================================

    cout << "\n=== EXAMPLE 4: CUSTOM WRAPPER ===\n";

    cout << "I created MyStack that wraps a vector\n";
    cout << "The vector is HIDDEN (private)\n\n";

    MyStack myStack;
    myStack.push(100);
    myStack.push(200);
    myStack.push(300);
    cout << "Pushed 100, 200, 300\n";
    cout << "Top: " << myStack.top() << "\n";
    myStack.pop();
    cout << "After pop, top: " << myStack.top() << "\n";
    cout << "✅ Vector hidden! Only stack operations allowed!\n";

    // ============================================================================
    // COMPARISON TABLE
    // ============================================================================

    cout << "\n\n=== COMPARISON ===\n";
    cout << "┌─────────────────┬──────────────────┬─────────────────────────┐\n";
    cout << "│ Container       │ Wraps What?      │ Hides What?             │\n";
    cout << "├─────────────────┼──────────────────┼─────────────────────────┤\n";
    cout << "│ vector          │ Raw memory       │ Nothing (full access)   │\n";
    cout << "│ stack           │ vector/deque     │ Iteration, random access│\n";
    cout << "│ queue           │ deque            │ Iteration, random access│\n";
    cout << "│ priority_queue  │ vector (heap)    │ Iteration, heap structure│\n";
    cout << "│ MyStack (custom)│ vector           │ The underlying vector   │\n";
    cout << "└─────────────────┴──────────────────┴─────────────────────────┘\n";

    // ============================================================================
    // KEY TAKEAWAY
    // ============================================================================

    cout << "\n\n=== KEY TAKEAWAY ===\n";
    cout << R"(
WRAPPING = Taking a container (vector, deque, heap) and HIDING it
HIDING ITERATION = User can't loop through or access elements directly

WHY?
─────
1. SAFETY: Can't accidentally break the data structure
2. RULES: Forces specific operations (LIFO for stack, FIFO for queue)
3. EFFICIENCY: Automatically maintains structure (heap for priority_queue)
4. SIMPLICITY: User just calls push(), pop(), top() - that's it!

ANALOGY:
────────
Think of a vending machine:
- OUTSIDE: Buttons (push, pop, top)
- INSIDE: Hidden mechanism (vector/deque)
- RULES: Can't reach inside and grab what you want
- RESULT: Safe, predictable, efficient!
)";

    return 0;
}

/*
SUMMARY:
═════════

Stack, Queue, Priority Queue = WRAPPERS
They wrap other containers (vector, deque) INSIDE them
They HIDE the wrapped container
They HIDE how to iterate

Why?
- Enforce specific rules (LIFO, FIFO, heap property)
- Prevent user from breaking the structure
- Make the interface simple (just a few methods)

Real analogy:
- Vector = Open shelf (you can grab anything)
- Stack = Closed box with one hole on top (only pop from top)
- Queue = Closed box with holes on both ends (pop from front, push to back)
- Priority Queue = Smart box (automatically sorts by priority)

All are wrappers! All hide their internals!
*/
