#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Enter the number of Fibonacci terms you want to generate: ";
    cin >> n;
    
    int first = 0, second = 1, next;
    
    cout << "Fibonacci Series up to " << n << " terms: " << endl;
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << " ";
    }
    
    cout << endl;
    
    return 0;
}
