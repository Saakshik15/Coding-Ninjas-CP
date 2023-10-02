//problem: Covert string to integer

#include <cstring>
#include <iostream>
using namespace std;

int strToInt(char input[], int n) {
    // Base case
    if (n == 0) return 0;

    // Convert the remaining substring to an integer and add the last digit
    return (input[n - 1] - '0') + 10 * strToInt(input, n - 1);
}

int stringToNumber(char input[]) {
    int len = strlen(input);
    return strToInt(input, len);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}


