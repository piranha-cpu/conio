#include <iostream>
using namespace std;

void coinChange(int amount) {
    int denominations[] = {200, 100, 50, 20, 10, 5, 1};
    int n = 7;
    int totalCoins = 0;
    
    cout << "\n=== Coin Change Problem ===" << endl;
    cout << "Amount: " << amount << endl;
    cout << "\nSelected Coins:" << endl;
    
    for (int i = 0; i < n; i++) {
        if (amount >= denominations[i]) {
            int count = amount / denominations[i];
            totalCoins += count;
            
            cout << "Coin " << denominations[i] << ": " << count << " coin(s)";
            amount = amount % denominations[i];
            cout << " -> Remaining balance: " << amount << endl;
        }
    }
    
    cout << "\nTotal Coins Used: " << totalCoins << endl;
    cout << "\nTime Complexity: O(n) where n is the number of denominations" << endl;
}

int main() {
    int amount = 389; // Test case
    
    coinChange(amount);
    
    return 0;
}
