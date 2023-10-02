//Problem : Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14"

#include <iostream>
#include "solution.h"
using namespace std;

//function
void replacePi(char input[]) {
    if (input[0] == '\0' || input[1] == '\0') return;
    
    if (input[0] == 'p' && input[1] == 'i') {

        int length = strlen(input);
        for (int i = length; i >= 2; --i) 
            input[i + 2] = input[i];
    
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';

        replacePi(input + 4);
		
    } else {
        replacePi(input + 1);
    }
}

//main code

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
