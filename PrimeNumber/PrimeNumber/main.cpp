//
//  main.cpp
//  PrimeNo
//
//  Created by Avneesh Gupta on 21/11/20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
const int N = 1e5+10;
bool is_prime[N];
void makePrimeList(){
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= N; i++){
        if(is_prime[i]){
            for(int j = i*i; j < N; j += 2*i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
}

bool isPrime(int x) {
    if(x < N) return is_prime[x];
    for(int i = 0; primes[i]*primes[i] <= x; i++){
        if(x%primes[i] == 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    makePrimeList();
    cout<<isPrime(23)<<"\n";
    cout<<isPrime(2323)<<"\n";
    cout<<isPrime(232379239)<<"\n";
    return 0;
}
