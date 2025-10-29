#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int solveRecurrence(int n, int depth = 0) {
    int j = 0;
    for (int i = 0; i < depth; i++) j++;
    cout << "J : " << j << "\r";

    if (n <= 1)
        return 1;  
    int left = solveRecurrence(n / 2, depth + 1);
    int right = solveRecurrence(n / 2, depth + 1);
    return left + right + n;
}

int main() {
    int n = 16; 
    cout << "Recursion tree for T(n) = 2T(n/2) + n\n";
    cout << "--------------------------------------\n";
    int result = solveRecurrence(n);
    cout << "--------------------------------------\n";
    cout << "Result: " << result << "\n";

    cout << "\nTime Complexity Validation:\n";
    for (int size : {1, 2, 4, 8, 16, 32, 64}) {
        auto start = high_resolution_clock::now();
        solveRecurrence(size, 0);
        auto end = high_resolution_clock::now();
        double duration = duration_cast<microseconds>(end - start).count();
        cout << "n = " << size << " -> time = " << duration << " µs\n";
    }
}
