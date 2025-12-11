#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if(n<2)return false;
    for(int i=2;i*i<=n;i++){      
        if(n%i==0)return false;
    }return true;
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

vector<int> primeFactorisation(int n){
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(n>1)ans.push_back(n);
    return ans;
}

vector<bool> sieveOfEratosthenes(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector<int> sieveOfEratosthenesInt(int n){
    vector<int> spf(n+1); // smallest prime factor
    for(int i = 0; i <= n; i++) spf[i] = i;
    for(int i = 2; i*i <= n; i++){
        if(spf[i]==i){ // i is prime
            for(int j = i*i; j <= n; j += i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    return spf;
}

int main(){
    // Test checkPrime function
    int n1 = 12;
    cout << "Is " << n1 << " prime? " << checkPrime(n1) << endl;
    
    // Test primeFactorisation function
    int n = 12;
    vector<int> a = primeFactorisation(n);
    cout << "Prime factors of " << n << ": ";
    for(int num : a){
        cout << num << ' ';
    }
    cout << endl;
    
    // Test sieveOfEratosthenes function
    int limit = 20;
    vector<bool> s = sieveOfEratosthenes(limit);
    cout << "Primes up to " << limit << ": ";
    for(int i = 0; i <= limit; i++){
        if(s[i]) cout << i << " ";
    }
    cout << endl;
    
    // Test sieveOfEratosthenesInt function
    vector<int> d = sieveOfEratosthenesInt(limit);
    cout << "Smallest prime factors: ";
    for(int num : d) cout << num << " ";
    cout << endl;
    
    return 0;
}