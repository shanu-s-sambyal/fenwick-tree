#include <iostream>
#include <vector>
#include "fenwick_tree.cpp"

using namespace std;

int main() {
    cout << "==================================================\n";
    cout << "      Fenwick Tree (Binary Indexed Tree) Demo      \n";
    cout << "==================================================\n\n";

    // Example array from README (1-based indexing)
    // A = [3, 2, -1, 6, 5, 4, -3, 3]
    vector<long long> arr = {3, 2, -1, 6, 5, 4, -3, 3};
    int n = arr.size();

    cout << "Initializing Fenwick Tree of size " << n << "...\n";
    FenwickTree ft(n);

    cout << "Inserting initial elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  A[" << (i + 1) << "] = " << arr[i] << "\n";
        ft.update(i + 1, arr[i]);
    }
    cout << "\n";

    cout << "--- Initial Queries ---\n";
    cout << "Prefix sum of first 4 elements (expecting 10): " << ft.query(4) << "\n";
    cout << "Prefix sum of first 7 elements (expecting 16): " << ft.query(7) << "\n";
    cout << "Prefix sum of first 8 elements (expecting 19): " << ft.query(8) << "\n";
    cout << "Range query [3, 6] (expecting 14): " << ft.rangeQuery(3, 6) << "\n";
    cout << "Range query [5, 7] (expecting 6): " << ft.rangeQuery(5, 7) << "\n\n";

    cout << "--- Performing Update ---\n";
    cout << "Adding 5 to A[3] (index 3)...\n";
    ft.update(3, 5);
    arr[2] += 5; // A[3] becomes 4

    cout << "Prefix sum of first 4 elements now (expecting 15): " << ft.query(4) << "\n";
    cout << "Range query [3, 6] now (expecting 19): " << ft.rangeQuery(3, 6) << "\n\n";

    cout << "==================================================\n";
    return 0;
}