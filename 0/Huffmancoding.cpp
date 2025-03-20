#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};singly
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman Codes
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->data != '$') { // Leaf node contains a character
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and return encoded values
unordered_map<char, string> huffmanCoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Step 1: Create leaf nodes for all characters and insert into minHeap
    for (size_t i = 0; i < chars.size(); i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the Huffman Tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with sum of frequencies
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    // Step 3: Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(minHeap.top(), "", huffmanCodes);

    return huffmanCodes;
}

// Driver code
int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    unordered_map<char, string> huffmanCodes = huffmanCoding(chars, freq);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCodes) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
