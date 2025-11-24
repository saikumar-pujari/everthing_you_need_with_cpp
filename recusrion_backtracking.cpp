#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// BASIC RECURSION FUNCTIONS
// ============================================================================

/**
 * Print numbers from n to 1 in descending order
 * Time: O(n), Space: O(n) - recursion stack
 */
void fun(int n){
    if(n<1)return;
    cout<<n<<" ";
    fun(n-1);
}

/**
 * Calculate factorial of n (n!)
 * Time: O(n), Space: O(n)
 */
int fact(int n){
    if(n<1)return 1;
    return n*fact(n-1);
}

/**
 * Calculate sum of numbers from 1 to n
 * Time: O(n), Space: O(n)
 */
int sumofn(int n){
    if(n<1)return 0;
    return n+sumofn(n-1);
}

/**
 * Calculate nth Fibonacci number
 * Time: O(2^n), Space: O(n) - can be optimized with memoization
 */
int fab(int n){
    if(n==0||n==1)return n;
    return fab(n-1)+fab(n-2);
}

// ============================================================================
// ARRAY RECURSION FUNCTIONS
// ============================================================================

/**
 * Check if array is sorted in ascending order
 * Time: O(n), Space: O(n)
 */
bool isorted(vector<int>&arr,int n){
    if(n==0||n==1)return true;
    return arr[n-1]>=arr[n-2]&&isorted(arr,n-1);
}

/**
 * Binary search in sorted array using recursion
 * Time: O(log n), Space: O(log n)
 * Returns 1-indexed position or -1 if not found
 */
int binarysearch(vector<int>&arr,int target,int low,int high){
    if(low>high)return -1;
    int mid=low+(high-low)/2;
    if(arr[mid]==target)return mid+1;
    else if(arr[mid]<target)return binarysearch(arr,target,mid+1,high);
    else if(arr[mid]>target) return binarysearch(arr,target,low,mid-1);
    return -1;
}

/**
 * Count total digits in a number
 * Time: O(log n), Space: O(log n)
 */
int countdigit(int n){
    if(n==0)return 0;
    return 1+countdigit(n/10);
}

/**
 * Reverse a string using recursion
 * Time: O(n), Space: O(n)
 */
string revserastring(string& name, int idx){
    if(idx<0)return "";
    return name[idx]+revserastring(name,idx-1);
}

// ============================================================================
// BACKTRACKING - SUBSETS AND COMBINATIONS
// ============================================================================

/**
 * Print all subsets of an array (Power Set)
 * Time: O(2^n), Space: O(n) - for recursion depth
 */
void printsubset(vector<int>&arr,vector<int>&ans,int i){
    if(i==arr.size()){
        for(int num:ans){
            cout<<num<<" ";
        }cout<<endl;return;
    }
    ans.push_back(arr[i]);
    printsubset(arr,ans,i+1);
    ans.pop_back();
    printsubset(arr,ans,i+1);
}

/**
 * Find all unique combinations that sum to target (handles duplicates)
 * Time: O(2^n), Space: O(n)
 */
void solve(int start, vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(path);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue;  // Skip duplicates
        if (nums[i] > target) break;

        path.push_back(nums[i]);
        solve(i + 1, nums, target - nums[i], path, ans);
        path.pop_back();
    }
}

// ============================================================================
// BACKTRACKING - SUBSET SUM
// ============================================================================

/**
 * Helper function to check if subset with given sum exists
 * Time: O(2^n), Space: O(n)
 */
bool subsetsum(int start,vector<int>&arr,int target){
    if(target==0)return true;
    if(start==arr.size()||target<0)return false;
    if(subsetsum(start+1,arr,target-arr[start]))return true;
    return subsetsum(start+1,arr,target);
}

/**
 * Check if array has a subset with given sum
 * Time: O(2^n), Space: O(n)
 */
bool issubetsum(vector<int>& arr,int target){
    return subsetsum(0,arr,target);
}

/**
 * Find all subsets with target sum
 * Time: O(2^n), Space: O(n)
 */
void findSubsets(int idx, vector<int>& arr, int target,
                 vector<int>& path, vector<vector<int>>& ans) {

    if (idx == arr.size()) {
        if (target == 0) ans.push_back(path);
        return;
    }
    
    path.push_back(arr[idx]);
    findSubsets(idx + 1, arr, target - arr[idx], path, ans);
    path.pop_back();
    findSubsets(idx + 1, arr, target, path, ans);
}

/**
 * Count total subsets with given sum
 * Time: O(2^n), Space: O(n)
 */
int countSubsets(int idx, vector<int>& arr, int target) {
    if (target == 0) return 1;
    if (idx == arr.size() || target < 0) return 0;

    int pick  = countSubsets(idx+1, arr, target-arr[idx]);
    int skip  = countSubsets(idx+1, arr, target);

    return pick + skip;
}

// ============================================================================
// BACKTRACKING - COMBINATION SUM II (with duplicates)
// ============================================================================

/**
 * Find all unique combinations that sum to target (with duplicates in input)
 * Time: O(2^n), Space: O(n)
 */
void solveCombSum2(int start,vector<int>&nums,vector<int>&path,vector<vector<int>>&allsubsets,int target){
    if(target==0){
        allsubsets.push_back(path);
        return;
    }
    for(int i=start;i<nums.size();i++){
        if(i>start&&nums[i]==nums[i-1])continue;
        if(nums[i]>target)break;

        path.push_back(nums[i]);
        solveCombSum2(i+1,nums,path,allsubsets,target-nums[i]);
        path.pop_back();
    }
}

// ============================================================================
// BACKTRACKING - COMBINATION SUM III
// ============================================================================

/**
 * Find k numbers (1-9) that sum to target
 * Time: O(C(9,k)), Space: O(k)
 */
void solveCombSum3(int start, int k, int target, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() == k) {
        if (target == 0) ans.push_back(path);
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > target) break;

        path.push_back(i);
        solveCombSum3(i + 1, k, target - i, path, ans);
        path.pop_back();
    }
}

// ============================================================================
// BACKTRACKING - GENERATE PARENTHESES
// ============================================================================

/**
 * Generate all valid combinations of balanced parentheses
 * Time: O(4^n / sqrt(n)), Space: O(n)
 */
void solveParenthesis(string &op,int open,int close,vector<string>&ans){
    if(open==0&&close==0){
        ans.push_back(op);
        return;
    }
    if(open>0){
        op.push_back('(');
        solveParenthesis(op,open-1,close,ans);
        op.pop_back();
    }
    if(close>open){
        op.push_back(')');
        solveParenthesis(op,open,close-1,ans);
        op.pop_back();
    }
}

/**
 * Generate n pairs of balanced parentheses
 * Time: O(4^n / sqrt(n)), Space: O(n)
 */
vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string op="";
    op.reserve(2*n);
    solveParenthesis(op,n,n,ans);
    return ans;
}

// ============================================================================
// BACKTRACKING - PERMUTATIONS
// ============================================================================

/**
 * Generate all permutations of array (in-place, no extra space)
 * Time: O(n!), Space: O(n) - recursion depth
 */
void permuations(vector<int>&arr,int start){
    if(start==arr.size()){
        for(int num:arr){
            cout<<num<<" ";
        }cout<<endl;return;
    }
    for(int i=start;i<arr.size();i++){
        swap(arr[start],arr[i]);
        permuations(arr,start+1);
        swap(arr[start],arr[i]);
    }
}

// ============================================================================
// BACKTRACKING - N QUEENS
// ============================================================================

/**
 * Check if placing queen at (row, col) is safe
 * Validates: column, left diagonal, right diagonal
 * Time: O(n), Space: O(1)
 */
bool issafeboard(int row, vector<string>& board, int col, int n) {
    // check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // check left diagonal
    for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // check right diagonal
    for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

/**
 * Solve N-Queens problem using backtracking
 * Time: O(N!), Space: O(n)
 */
void nqueens(int row, vector<string>& board, int n,
             vector<vector<string>>& ans) {

    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (issafeboard(row, board, col, n)) {
            board[row][col] = 'Q';
            nqueens(row + 1, board, n, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nqueens(0, board, n, ans);
    return ans;
}
/**
 * Solve N-Queens and return all solutions
 * Time: O(N!), Space: O(n)
 */

 //string -partitions
bool isPal(string &s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

void dfs(int start, string &s, vector<string> &path, vector<vector<string>> &res) {
    if (start == s.size()) {
        res.push_back(path);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPal(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            dfs(end + 1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    dfs(0, s, path, res);
    return res;
}

//tower of hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << "\n";
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    towerOfHanoi(n - 1, aux, to, from);
}
//meet in middle
bool meetInMiddle(vector<long long>& arr, long long target) {
    int n = arr.size();
    int mid = n / 2;

    vector<long long> left, right;

    // left half
    for (int mask = 0; mask < (1 << mid); mask++) {
        long long sum = 0;
        for (int i = 0; i < mid; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        left.push_back(sum);
    }

    // right half
    int rsize = n - mid;
    for (int mask = 0; mask < (1 << rsize); mask++) {
        long long sum = 0;
        for (int i = 0; i < rsize; i++) {
            if (mask & (1 << i)) sum += arr[mid + i];
        }
        right.push_back(sum);
    }

    sort(right.begin(), right.end());

    // check if any left sum + right sum == target
    for (long long x : left) {
        long long need = target - x;
        if (binary_search(right.begin(), right.end(), need))
            return true;
    }
    return false;
}

// ============================================================================
// MAIN - TEST CASES
// ============================================================================

int main(){
    cout << "========== RECURSION & BACKTRACKING TEST CASES ==========" << endl;

    // Test 1: Print numbers descending
    cout << "\n1. Print 5 to 1: ";
    fun(5);
    cout << endl;

    // Test 2: Factorial
    cout << "2. Factorial of 5: " << fact(5) << endl;

    // Test 3: Sum of numbers
    cout << "3. Sum of 1 to 5: " << sumofn(5) << endl;

    // Test 4: Fibonacci
    cout << "4. Fibonacci(6): " << fab(6) << endl;

    // Test 5: Check if sorted
    vector<int> sortedArr = {1, 2, 3, 4, 5};
    cout << "5. Is [1,2,3,4,5] sorted? " << (isorted(sortedArr, sortedArr.size()) ? "Yes" : "No") << endl;

    // Test 6: Binary Search
    int target = 3;
    cout << "6. Binary search for " << target << " in [1,2,3,4,5]: " << binarysearch(sortedArr, target, 0, sortedArr.size()-1) << endl;

    // Test 7: Count digits
    cout << "7. Digits in 12345: " << countdigit(12345) << endl;

    // Test 8: Reverse string
    string name = "Saikumar";
    cout << "8. Reverse of '" << name << "': " << revserastring(name, name.size()-1) << endl;

    // Test 9: Print all subsets
    cout << "9. All subsets of [1,2,3]:" << endl;
    vector<int> arr1 = {1, 2, 3};
    vector<int> subset_ans;
    printsubset(arr1, subset_ans, 0);

    // Test 10: Subset sum check
    vector<int> arr2 = {3, 34, 4, 12, 5, 2};
    int sum_target = 9;
    cout << "10. Subset with sum " << sum_target << " exists? " << (issubetsum(arr2, sum_target) ? "Yes" : "No") << endl;

    // Test 11: Count subsets with sum
    vector<int> arr3 = {1, 2, 3, 4};
    int target_sum = 5;
    cout << "11. Count subsets of [1,2,3,4] with sum " << target_sum << ": " << countSubsets(0, arr3, target_sum) << endl;

    // Test 12: Generate Parentheses
    cout << "12. Valid parentheses combinations for n=2:" << endl;
    vector<string> parens = generateParenthesis(2);
    for (auto& p : parens) cout << p << " ";
    cout << endl;

    // Test 13: Permutations
    cout << "13. Permutations of [1,2,3]:" << endl;
    vector<int> perm_arr = {1, 2, 3};
    permuations(perm_arr, 0);

    // Test 14: N-Queens
    cout << "14. N-Queens solutions for N=4:" << endl;
    vector<vector<string>> nq_solutions = solveNQueens(4);
    cout << "Total solutions: " << nq_solutions.size() << endl;
    if (nq_solutions.size() > 0) {
        cout << "First solution:" << endl;
        for (auto& row : nq_solutions[0]) {
            cout << row << endl;
        }
    }
    

    cout << "\n========== ALL TESTS COMPLETED ==========" << endl;

    return 0;
}