//problem: find the sum of digits of a given number using recursion

#include <iostream>
using namespace std;

int sumOfDigits(int n) {

  //base case
    if(n==0) return 0;
  //recursive call
    return n%10 + sumOfDigits(n/10);
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;

  return 0;
}



