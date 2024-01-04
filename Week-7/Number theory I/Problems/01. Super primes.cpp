/*
Problem statement:

A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
*/

#include <iostream>
#include <unordered_set>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countSuperPrimes(int N) {
    int superPrimeCount = 0;
    for (int num = 2; num <= N; ++num) {
        unordered_set<int> distinctPrimes;
        int temp = num;
        for (int i = 2; i * i <= temp; ++i) {
            if (temp % i == 0 && isPrime(i)) {
                distinctPrimes.insert(i);
                while (temp % i == 0) {
                    temp /= i;
                }
            }
        }
        if (temp > 1) {
            distinctPrimes.insert(temp);
        }
        if (distinctPrimes.size() == 2) {
            ++superPrimeCount;
        }
    }
    return superPrimeCount;
}

int main() {
    int N;
    // cout << "Enter the value of N: ";
    cin >> N;
    int result = countSuperPrimes(N);
    cout<<result;
    // cout << "The count of super-prime numbers between 1 and " << N << " (inclusive) is: " << result << endl;
    return 0;
}
