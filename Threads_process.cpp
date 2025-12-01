// C++ THREADS & SYNCHRONIZATION - COMPLETE GUIDE WITH WORKING EXAMPLES
// Thread creation: function pointer, lambda, functor, non-static member
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
using namespace std;

// ============================================================================
// TOPIC 1: BASIC THREAD CREATION & JOIN
// Explanation: Creating threads and using join() to wait for completion
// join() blocks the calling thread until the thread finishes execution
// ============================================================================
void simpleCount(){
    for(int i=1; i<=5; i++){
        cout << "Counting: " << i << endl;
    }
}

void run(int x){
    while(x-->0){
        cout<<"sai"<<endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
}

// ============================================================================
// TOPIC 2: THREAD DETACH vs JOIN
// Explanation: detach() makes thread run independently, join() waits for it
// joinable() checks if thread can be joined or detached
// ============================================================================

// ============================================================================
// TOPIC 3: MUTEX (MUTUAL EXCLUSION)
// Explanation: Prevents race conditions using .lock() and .unlock()
// Race condition: Multiple threads accessing shared data simultaneously
// Works on: load, increment, store operations
// ============================================================================
mutex mtx_basic;
int saving=0;

void addamount(int x){
    mtx_basic.lock();
    saving+=x;
    mtx_basic.unlock();
}

// ============================================================================
// TOPIC 4: TRY_LOCK
// Explanation: try_lock() attempts to lock without blocking
// If lock is already taken, it returns false immediately instead of waiting
// Useful when you don't want thread to wait indefinitely
// ============================================================================
mutex mtx_try;
int counter=0;

void countWithTryLock(){
    for(int i=0;i<=1000000;i++){
        // First arrival locks, second arrival waits for unlock
        // If lock is already taken, try_lock() returns false
        if(mtx_try.try_lock()){
            counter++;
            mtx_try.unlock();
        }
    }
}

// ============================================================================
// TOPIC 5: TIMED_MUTEX (try_lock_for, try_lock_until)
// Explanation: Tries to acquire lock for a specified time duration
// try_lock_for(): waits for given duration
// try_lock_until(): waits until specific time point
// ============================================================================
timed_mutex mtx_timed;
int passs=0;

void pas(int i){
    if(mtx_timed.try_lock_for(chrono::seconds(1))){
        passs++;
        cout<<"thread "<<i<<" entered\n";
        this_thread::sleep_for(chrono::seconds(2));
        mtx_timed.unlock();
    }else{
        cout<<"thread "<<i<<" not entered\n";
    }
}

// ============================================================================
// TOPIC 6: RECURSIVE_MUTEX
// Explanation: Same thread can lock the mutex multiple times
// Must unlock same number of times as locked
// ============================================================================
recursive_mutex mtx_recursive;
int recursive_counter = 0;

void recursiveFunction(int depth){
    if(depth <= 0) return;
    mtx_recursive.lock();
    recursive_counter++;
    cout << "Depth: " << depth << ", Counter: " << recursive_counter << endl;
    recursiveFunction(depth - 1); // Same thread locks again
    mtx_recursive.unlock();
}

// ============================================================================
// TOPIC 7: LOCK_GUARD
// Explanation: RAII wrapper for mutex - automatic lock/unlock
// Locks on construction, unlocks on destruction (scope exit)
// Exception safe - no need to manually unlock
// ============================================================================
mutex mtx_guard;
int guard_counter = 0;

void countWithLockGuard(){
    for(int i=0; i<100000; i++){
        lock_guard<mutex> lock(mtx_guard); // Auto lock
        guard_counter++;
    } // Auto unlock when lock goes out of scope
}

// ============================================================================
// TOPIC 8: UNIQUE_LOCK
// Explanation: More flexible than lock_guard
// Can defer locking, try_lock, unlock before scope ends
// Supports defer_lock, try_to_lock, adopt_lock
// ============================================================================
mutex mtx_unique;
int unique_counter = 0;

void countWithUniqueLock(){
    unique_lock<mutex> lock(mtx_unique, defer_lock); // Don't lock immediately
    // Do some work without lock
    lock.lock(); // Manual lock when needed
    for(int i=0; i<100000; i++){
        unique_counter++;
    }
    lock.unlock(); // Can unlock before scope ends
}

// ============================================================================
// TOPIC 9: std::lock() - LOCK MULTIPLE MUTEXES
// Explanation: Locks multiple mutexes at once, avoiding deadlock
// try_lock(m1,m2,m3,m4) - locks all or none
// ============================================================================
mutex m1, m2, m3, m4;
int multi_lock_data = 0;

void multiLockExample(){
    lock(m1, m2, m3, m4); // Lock all at once - deadlock safe
    multi_lock_data++;
    m1.unlock();
    m2.unlock();
    m3.unlock();
    m4.unlock();
}
// ==============================================================================
// TOPIC 10: CONDITION VARIABLE
// Explanation: Allows threads to wait for a specific condition to be met
// notify_one(): wakes up one waiting thread
// notify_all(): wakes up all waiting threads
// wait(): blocks thread until notified AND condition is true
// Real-world example: ATM withdraw waits until money is deposited
// ============================================================================
condition_variable cv;
mutex m;
long balance = 0;

void addmoney(int x){
    lock_guard<mutex> lock(m);  // Auto lock/unlock
    balance += x;
    cout << "Amount added: " << x << " | Balance: " << balance << endl;
    cv.notify_one();  // Notify one waiting thread that condition changed
}

void withdraw(int x){
    unique_lock<mutex> ma(m);  // unique_lock needed for condition_variable
    // Wait until balance is non-zero
    cv.wait(ma, []{ return (balance != 0) ? true : false; });
    
    if(balance >= x){
        balance -= x;
        cout << "Withdraw amount: " << x << " | Remaining: " << balance << endl;
    } else {
        cout << "Insufficient balance for withdrawal of " << x << endl;
    }
}

// ============================================================================
// TOPIC 11: DEADLOCK PREVENTION
// Explanation: Deadlock occurs when two or more threads wait for each other
// Prevention strategies:
// 1. Lock ordering: Always acquire locks in same order
// 2. std::lock(): Lock multiple mutexes atomically
// 3. try_lock(): Non-blocking lock attempt
// 4. Timeout: Use timed_mutex with try_lock_for()
// Example: Thread1 locks A then B, Thread2 locks B then A = DEADLOCK!
// Solution: Both lock A then B, or use std::lock(A, B)
// ============================================================================

// ============================================================================
// TOPIC 12: ASYNC & FUTURE
// Explanation: async() runs function asynchronously, returns future object
// launch::async - creates new thread immediately
// launch::deferred - lazy evaluation, runs when .get() is called
// future.get() - blocks and retrieves the result
// Use case: Parallel computation, splitting work across threads
// ============================================================================
long long findodd(long long start, long long end){
    long long sum = 0;
    cout << "Finding odd numbers from " << start << " to " << end << endl;
    for(long long i = start; i <= end; i++){
        if(i & 1)  // Check if odd using bitwise AND
            sum += i;
    }
    return sum;
}

long long findeven(long long start, long long end){
    long long sum = 0;
    cout << "Finding even numbers from " << start << " to " << end << endl;
    for(long long i = start; i <= end; i++){
        if(!(i & 1))  // Check if even
            sum += i;
    }
    return sum;
}

// ============================================================================
// TOPIC 13: PRODUCER-CONSUMER PATTERN
// Explanation: Classic synchronization problem
// Producer: Creates/adds items to shared buffer
// Consumer: Removes/processes items from shared buffer
// Uses: mutex (protect buffer) + condition_variable (signal when ready)
// ============================================================================
mutex buffer_mtx;
condition_variable buffer_cv;
int buffer[10];
int buffer_count = 0;

void producer(int id){
    for(int i = 0; i < 5; i++){
        unique_lock<mutex> lock(buffer_mtx);
        // Wait if buffer is full
        buffer_cv.wait(lock, []{ return buffer_count < 10; });
        
        buffer[buffer_count++] = i;
        cout << "Producer " << id << " produced: " << i << " | Buffer count: " << buffer_count << endl;
        
        buffer_cv.notify_all();  // Notify consumers
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(int id){
    for(int i = 0; i < 5; i++){
        unique_lock<mutex> lock(buffer_mtx);
        // Wait if buffer is empty
        buffer_cv.wait(lock, []{ return buffer_count > 0; });
        
        int item = buffer[--buffer_count];
        cout << "Consumer " << id << " consumed: " << item << " | Buffer count: " << buffer_count << endl;
        
        buffer_cv.notify_all();  // Notify producers
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

// ============================================================================
// TOPIC 14: SLEEP vs WAIT
// Explanation:
// sleep_for(): Thread sleeps for duration, releases CPU but holds locks
//             - Use: Delays, throttling, periodic tasks
//             - Example: 9-5 job, PC locked while sleeping
// 
// wait(): Thread waits on condition_variable, releases lock while waiting
//        - Use: Waiting for specific condition/event
//        - Example: Interview waiting room, notified when it's your turn
// ============================================================================
// ============================================================================
// MAIN - UNCOMMENT SECTIONS TO TEST EACH TOPIC
// ============================================================================
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // cout << "\n========== TESTING ALL THREADING TOPICS ==========\n\n";
    
    // TOPIC 1: Basic Thread Creation & Join
    cout << "=== TOPIC 1: Basic Thread & Join ===\n";
    auto start_time=chrono::high_resolution_clock::now();
    thread t1(simpleCount);
    cout << "User can still type while counting...\n";
    t1.join(); // Wait for thread to finish
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    cout << "Time: " << duration << " ms\n\n";

    // TOPIC 2: Thread Detach vs Join
    cout << "=== TOPIC 2: Thread Detach & Joinable ===\n";
    thread t2(run,3);
    cout<<"main thread continues\n";
    if(t2.joinable())
        t2.join(); // Can use t2.detach() to run independently
    cout<<"after wait\n\n";

    // TOPIC 3: Mutex Basic Lock/Unlock
    cout << "=== TOPIC 3: Mutex Lock/Unlock ===\n";
    saving = 0;
    thread t3(addamount,10);
    thread t4(addamount,20);
    t3.join();
    t4.join();
    cout<<"Total Saving: "<<saving<<"\n\n";

    // TOPIC 4: Try Lock
    cout << "=== TOPIC 4: Try Lock ===\n";
    counter = 0;
    thread t5(countWithTryLock);
    thread t6(countWithTryLock);
    t5.join();
    t6.join();
    cout<<"Counter with try_lock: "<<counter<<"\n\n";
    
    // TOPIC 5: Timed Mutex
    cout << "=== TOPIC 5: Timed Mutex ===\n";
    passs = 0;
    thread t7(pas,1);
    thread t8(pas,2);
    t7.join();
    t8.join();
    cout<<"Pass count: "<<passs<<"\n\n";

    // TOPIC 6: Recursive Mutex
    cout << "=== TOPIC 6: Recursive Mutex ===\n";
    recursive_counter = 0;
    thread t9(recursiveFunction, 3);
    t9.join();
    cout<<"Recursive counter: "<<recursive_counter<<"\n\n";

    // TOPIC 7: Lock Guard
    cout << "=== TOPIC 7: Lock Guard ===\n";
    guard_counter = 0;
    thread t10(countWithLockGuard);
    thread t11(countWithLockGuard);
    t10.join();
    t11.join();
    cout<<"Guard counter: "<<guard_counter<<"\n\n";

    // TOPIC 8: Unique Lock
    cout << "=== TOPIC 8: Unique Lock ===\n";
    unique_counter = 0;
    thread t12(countWithUniqueLock);
    thread t13(countWithUniqueLock);
    t12.join();
    t13.join();
    cout<<"Unique counter: "<<unique_counter<<"\n\n";

    // TOPIC 9: Multiple Mutex Lock
    cout << "=== TOPIC 9: Lock Multiple Mutexes ===\n";
    multi_lock_data = 0;
    thread t14(multiLockExample);
    thread t15(multiLockExample);
    t14.join();
    t15.join();
    cout<<"Multi-lock data: "<<multi_lock_data<<"\n\n";

    cout << "========== ALL TOPICS DEMONSTRATED ==========\n";
    
    thread t1(withdraw,100);
    thread t2(addmoney,100);
    t1.join();
    t2.join();


    long long start=0,end=1900000000;
    future<long long>oddsum=async(launch::async,findodd,start,end);
    cout<<oddsum.get();

    return 0;
}