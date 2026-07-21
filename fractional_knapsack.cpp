#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

// Comparison function to sort by value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate value/weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    
    // Sort items by ratio in descending order
    sort(items, items + n, compare);
    
    cout << "\n=== Fractional Knapsack Problem ===" << endl;
    cout << "Knapsack Capacity: " << capacity << endl;
    cout << "\nItems after sorting by value/weight ratio:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << (i + 1) << " - Weight: " << items[i].weight 
             << ", Value: " << items[i].value 
             << ", Ratio: " << items[i].ratio << endl;
    }
    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    
    cout << "\nSelected Items:" << endl;
    
    for (int i = 0; i < n; i++) {
        if (remainingCapacity >= items[i].weight) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            cout << "Item " << (i + 1) << ": 100% (Full item) - Value added: " 
                 << items[i].value << endl;
        } else if (remainingCapacity > 0) {
            // Take fraction of the item
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "Item " << (i + 1) << ": " << (fraction * 100) 
                 << "% (Fraction) - Value added: " << (items[i].value * fraction) << endl;
            remainingCapacity = 0;
            break;
        }
    }
    
    cout << "\nTotal Value in Knapsack: " << totalValue << endl;
    cout << "\nTime Complexity: O(n log n) due to sorting, where n is the number of items" << endl;
}

int main() {
    // Test case: Capacity=50; Items:(10,60),(20,100),(30,120)
    int capacity = 50;
    Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };
    int n = 3;
    
    fractionalKnapsack(capacity, items, n);
    
    return 0;
}
