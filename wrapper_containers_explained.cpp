#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// ============================================================================
// CUSTOM IMPLEMENTATIONS - Stack with Vector
// ============================================================================

class MyStackVector {
private:
    vector<int> data;
    
public:
    void push(int x) {
        data.push_back(x);  // O(1) - add to end
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back();  // O(1) - remove from end
        }
    }
    
    int top() {
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

// ============================================================================
// CUSTOM IMPLEMENTATIONS - Stack with Deque
// ============================================================================

class MyStackDeque {
private:
    deque<int> data;
    
public:
    void push(int x) {
        data.push_back(x);  // O(1) - add to end
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back();  // O(1) - remove from end
        }
    }
    
    int top() {
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

// ============================================================================
// CUSTOM IMPLEMENTATIONS - Queue with Deque
// ============================================================================

class MyQueueDeque {
private:
    deque<int> data;
    
public:
    void push(int x) {
        data.push_back(x);  // O(1) - add to back
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_front();  // O(1) - remove from front
        }
    }
    
    int front() {
        return data.front();
    }
    
    int back() {
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

// ============================================================================
// CUSTOM IMPLEMENTATIONS - Priority Queue with Vector (Max Heap)
// ============================================================================

class MyPriorityQueueVector {
private:
    vector<int> data;
    
    // Helper: Move element up (for insertion)
    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] > data[parent]) {
                swap(data[index], data[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    
    // Helper: Move element down (for deletion)
    void bubbleDown(int index) {
        int size = data.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && data[left] > data[largest]) {
                largest = left;
            }
            if (right < size && data[right] > data[largest]) {
                largest = right;
            }
            
            if (largest != index) {
                swap(data[index], data[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
    
public:
    void push(int x) {
        data.push_back(x);
        bubbleUp(data.size() - 1);  // O(log n)
    }
    
    void pop() {
        if (!data.empty()) {
            data[0] = data.back();
            data.pop_back();
            if (!data.empty()) {
                bubbleDown(0);  // O(log n)
            }
        }
    }
    
    int top() {
        return data[0];
    }
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

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
    // EXAMPLE 1A: CUSTOM STACK WITH VECTOR
    // ============================================================================

    cout << "\n--- CUSTOM STACK WITH VECTOR ---\n";
    cout << "MyStackVector uses vector internally:\n";
    cout << "push(x) → data.push_back(x)\n";
    cout << "pop()   → data.pop_back()\n";
    cout << "top()   → data.back()\n\n";
    
    MyStackVector stackVec;
    stackVec.push(10);
    stackVec.push(20);
    stackVec.push(30);
    cout << "Pushed 10, 20, 30\n";
    cout << "Size: " << stackVec.size() << "\n";
    cout << "Top: " << stackVec.top() << "\n";
    stackVec.pop();
    cout << "After pop, Top: " << stackVec.top() << " (Size: " << stackVec.size() << ")\n";
    cout << "✅ Vector-based stack works!\n\n";

    // ============================================================================
    // EXAMPLE 1B: CUSTOM STACK WITH DEQUE
    // ============================================================================

    cout << "\n--- CUSTOM STACK WITH DEQUE ---\n";
    cout << "MyStackDeque uses deque internally:\n";
    cout << "push(x) → data.push_back(x)\n";
    cout << "pop()   → data.pop_back()\n";
    cout << "top()   → data.back()\n\n";
    
    MyStackDeque stackDeque;
    stackDeque.push(100);
    stackDeque.push(200);
    stackDeque.push(300);
    cout << "Pushed 100, 200, 300\n";
    cout << "Size: " << stackDeque.size() << "\n";
    cout << "Top: " << stackDeque.top() << "\n";
    stackDeque.pop();
    cout << "After pop, Top: " << stackDeque.top() << " (Size: " << stackDeque.size() << ")\n";
    cout << "✅ Deque-based stack works!\n\n";

    cout << "📌 Both Vector and Deque give O(1) for push/pop at end!\n\n";

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
    // EXAMPLE 2A: CUSTOM QUEUE WITH DEQUE
    // ============================================================================

    cout << "\n--- CUSTOM QUEUE WITH DEQUE ---\n";
    cout << "MyQueueDeque uses deque internally:\n";
    cout << "push(x) → data.push_back(x)  (add to BACK)\n";
    cout << "pop()   → data.pop_front()   (remove from FRONT)\n";
    cout << "front() → data.front()\n\n";
    
    MyQueueDeque queueDeque;
    queueDeque.push(5);
    queueDeque.push(10);
    queueDeque.push(15);
    queueDeque.push(20);
    cout << "Pushed 5, 10, 15, 20\n";
    cout << "Size: " << queueDeque.size() << "\n";
    cout << "Front: " << queueDeque.front() << ", Back: " << queueDeque.back() << "\n";
    cout << "Pop front: " << queueDeque.front() << "\n";
    queueDeque.pop();
    cout << "After pop, Front: " << queueDeque.front() << " (Size: " << queueDeque.size() << ")\n";
    cout << "✅ FIFO works! (5 goes in first, comes out first)\n";
    cout << "✅ Deque is PERFECT for queue (O(1) at both ends!)\n\n";

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

    cout << "WITH WRAPPER (STL Priority Queue - Hides heap):\n";
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
    // EXAMPLE 3A: CUSTOM PRIORITY QUEUE WITH VECTOR (MAX HEAP)
    // ============================================================================

    cout << "\n--- CUSTOM PRIORITY QUEUE WITH VECTOR (MAX HEAP) ---\n";
    cout << "MyPriorityQueueVector uses vector + bubble up/down:\n";
    cout << "push(x) → add to end, bubble up        O(log n)\n";
    cout << "pop()   → remove root, move last to root, bubble down  O(log n)\n";
    cout << "top()   → return root (max element)\n\n";
    
    MyPriorityQueueVector pqVec;
    pqVec.push(5);
    pqVec.push(3);
    pqVec.push(7);
    pqVec.push(1);
    pqVec.push(9);
    cout << "Pushed 5, 3, 7, 1, 9\n";
    cout << "Heap structure maintained internally!\n";
    cout << "Top (max): " << pqVec.top() << "\n";
    cout << "Pop order: ";
    while (!pqVec.empty()) {
        cout << pqVec.top() << " ";
        pqVec.pop();
    }
    cout << "← Max heap order!\n";
    cout << "✅ Vector-based max heap works!\n\n";

    // ============================================================================
    // COMPARISON TABLE - ALL CONTAINERS
    // ============================================================================

    cout << "\n\n=== COMPREHENSIVE COMPARISON ===\n";
    cout << "┌─────────────────────┬──────────────────────┬────────────┬──────────────┐\n";
    cout << "│ Container           │ Wraps What?          │ Push/Pop   │ Use Case     │\n";
    cout << "├─────────────────────┼──────────────────────┼────────────┼──────────────┤\n";
    cout << "│ MyStackVector       │ vector               │ O(1)/O(1)  │ LIFO (LIFO)  │\n";
    cout << "│ MyStackDeque        │ deque                │ O(1)/O(1)  │ LIFO (LIFO)  │\n";
    cout << "│ stack (STL)         │ deque (default)      │ O(1)/O(1)  │ LIFO (LIFO)  │\n";
    cout << "├─────────────────────┼──────────────────────┼────────────┼──────────────┤\n";
    cout << "│ MyQueueDeque        │ deque                │ O(1)/O(1)  │ FIFO (FIFO)  │\n";
    cout << "│ queue (STL)         │ deque (default)      │ O(1)/O(1)  │ FIFO (FIFO)  │\n";
    cout << "├─────────────────────┼──────────────────────┼────────────┼──────────────┤\n";
    cout << "│ MyPriorityQueueVec  │ vector (heap)        │ O(logn)/.. │ Sorting      │\n";
    cout << "│ priority_queue (STL)│ vector (heap)        │ O(logn)/.. │ Sorting      │\n";
    cout << "└─────────────────────┴──────────────────────┴────────────┴──────────────┘\n";

    // ============================================================================
    // WHY EACH CONTAINER CHOICE
    // ============================================================================

    cout << "\n\n=== WHY THESE CONTAINER CHOICES? ===\n";
    cout << R"(
STACK with VECTOR:
  ✅ push_back() at end = O(1)
  ✅ pop_back() at end = O(1)
  ❌ No need for front operations
  
STACK with DEQUE:
  ✅ push_back() at end = O(1)
  ✅ pop_back() at end = O(1)
  ✅ Better memory efficiency for large stacks
  
QUEUE with DEQUE:
  ✅ push_back() at back = O(1)
  ✅ pop_front() at front = O(1)
  ❌ Vector would need O(n) shift for front removal!
  ✅ DEQUE IS PERFECT FOR QUEUE!
  
PRIORITY QUEUE with VECTOR:
  ✅ Vector allows heap structure
  ✅ bubbleUp() maintains max-heap property
  ✅ bubbleDown() maintains max-heap property
  ✅ O(log n) for both push and pop
)";

    // ============================================================================
    // KEY TAKEAWAY
    // ============================================================================

    cout << "\n\n=== KEY TAKEAWAY ===\n";
    cout << R"(
WRAPPING = Taking a container and HIDING it

CONTAINER CHOICES:
──────────────────
1. STACK
   - Can use: vector OR deque
   - Both work fine (operations at back only)
   
2. QUEUE
   - MUST use: deque
   - Why? Need O(1) at BOTH ends (front and back)
   - Vector would be O(n) for front removal!
   
3. PRIORITY QUEUE
   - MUST use: vector + heap
   - Why? Heap property needs random access
   - Deque doesn't provide good heap performance

MEMORY LAYOUT:
──────────────
Vector:   [data contiguous in memory] - fast for sequential access
Deque:    [multiple blocks] - fast for both ends operations
Heap:     [tree structure in array] - organized by priority

ANALOGY:
────────
Stack = Parking lot, only access top (vector or deque both work)
Queue = Line at bank, add to back, remove from front (NEED DEQUE!)
Priority = Hospital queue (critical patients first) (NEED HEAP!)
)";

    return 0;
}

/*
SUMMARY:
═════════

All STL containers are WRAPPERS:
✅ stack wraps vector or deque
✅ queue wraps deque
✅ priority_queue wraps vector (as heap)

WHY WRAP?
─────────
1. SAFETY: Hide internal structure
2. ENFORCE RULES: LIFO, FIFO, max/min first
3. SIMPLICITY: Just push(), pop(), top()
4. EFFICIENCY: Optimized operations

CONTAINER CHOICE MATTERS:
─────────────────────────
Stack + Vector = ✅ Works (push_back, pop_back)
Stack + Deque = ✅ Works (push_back, pop_back)
Queue + Vector = ❌ NO! (pop_front would be O(n))
Queue + Deque = ✅ Perfect! (push_back O(1), pop_front O(1))
PriorityQueue + Vector = ✅ Perfect! (heap structure)
PriorityQueue + Deque = ❌ Bad (random access not efficient)

KEY INSIGHT: Different containers have different strengths!
Use the RIGHT container for the RIGHT wrapper!
*/
