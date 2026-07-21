#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char character;
    int frequency;
    Node *left, *right;
    
    Node(char ch, int freq) {
        character = ch;
        frequency = freq;
        left = right = nullptr;
    }
};

// Comparison structure for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Generate Huffman codes by traversing the tree
void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) return;
    
    // If leaf node, store the code
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }
    
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Calculate weighted path length
int calculateWeightedPathLength(map<char, string>& huffmanCodes, map<char, int>& frequencies) {
    int wpl = 0;
    for (auto& pair : huffmanCodes) {
        char ch = pair.first;
        string code = pair.second;
        wpl += code.length() * frequencies[ch];
    }
    return wpl;
}

void huffmanCoding(char characters[], int frequencies[], int n) {
    // Create a priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    // Create leaf nodes and add to priority queue
    for (int i = 0; i < n; i++) {
        pq.push(new Node(characters[i], frequencies[i]));
    }
    
    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        
        Node* right = pq.top();
        pq.pop();
        
        // Create internal node with combined frequency
        Node* internal = new Node('$', left->frequency + right->frequency);
        internal->left = left;
        internal->right = right;
        
        pq.push(internal);
    }
    
    // Root of Huffman Tree
    Node* root = pq.top();
    
    // Generate Huffman codes
    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    
    // Display results
    cout << "\n=== Huffman Coding ===" << endl;
    cout << "\nCharacter | Frequency | Huffman Code" << endl;
    cout << "----------|-----------|-------------" << endl;
    
    map<char, int> freqMap;
    for (int i = 0; i < n; i++) {
        freqMap[characters[i]] = frequencies[i];
        cout << "    " << characters[i] << "     |     " 
             << frequencies[i] << "     |     " 
             << huffmanCodes[characters[i]] << endl;
    }
    
    // Calculate and display weighted path length
    int wpl = calculateWeightedPathLength(huffmanCodes, freqMap);
    cout << "\nWeighted Path Length: " << wpl << endl;
    
    cout << "\nTime Complexity: O(n log n) where n is the number of characters" << endl;
    cout << "  - Building the heap: O(n)" << endl;
    cout << "  - Extracting min and inserting: O(log n) for n-1 iterations" << endl;
}

int main() {
    // Test case: Chars:A B C D E F; Frequencies:45 13 12 16 9 5
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequencies[] = {45, 13, 12, 16, 9, 5};
    int n = 6;
    
    huffmanCoding(characters, frequencies, n);
    
    return 0;
}
