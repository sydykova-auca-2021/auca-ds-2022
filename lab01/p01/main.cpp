#include <iostream>

using namespace std;

int main() 
{   
    #ifdef AUCA_DEBUG
        cout << "author: Aziza Sydykova\n";
    #endif
        cout << "Hello, C++ " << __cplusplus << "!\n";
}