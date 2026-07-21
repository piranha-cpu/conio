# CIT 3106: Greedy Algorithms Lab

This repository contains implementations of three classic greedy algorithms in C++.

## Programs Included

### 1. Coin Change (coin_change.cpp)
Implements the coin change problem using denominations {200, 100, 50, 20, 10, 5, 1}.
- **Test Case**: Amount = 389
- **Time Complexity**: O(n) where n is the number of denominations

### 2. Fractional Knapsack (fractional_knapsack.cpp)
Implements the fractional knapsack problem using value/weight ratio greedy approach.
- **Test Case**: Capacity = 50, Items: (10,60), (20,100), (30,120)
- **Time Complexity**: O(n log n) due to sorting

### 3. Huffman Coding (huffman_coding.cpp)
Implements Huffman coding using a priority queue and binary tree.
- **Test Case**: Characters: A B C D E F, Frequencies: 45 13 12 16 9 5
- **Time Complexity**: O(n log n)

## How to Compile and Run

```bash
# Compile each program
g++ coin_change.cpp -o coin_change
g++ fractional_knapsack.cpp -o fractional_knapsack
g++ huffman_coding.cpp -o huffman_coding

# Run each program
./coin_change
./fractional_knapsack
./huffman_coding
```

## Screenshots

### Coin Change Output
[Add screenshot here showing the output for amount 389]

### Fractional Knapsack Output
[Add screenshot here showing the knapsack solution]

### Huffman Coding Output
[Add screenshot here showing the Huffman codes and weighted path length]

## Analysis

Each program demonstrates the greedy algorithm approach:
- **Coin Change**: Selects the largest denomination first
- **Fractional Knapsack**: Selects items with highest value/weight ratio
- **Huffman Coding**: Builds optimal prefix codes by combining lowest frequency nodes

## Author

[Your Name]  
CIT 3106: Design and Analysis of Algorithms
