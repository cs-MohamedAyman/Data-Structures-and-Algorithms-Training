#include <bits/stdc++.h>
using namespace std;

struct node {
    int freq;
    string symbol;
    node* left;
    node* right;
    string huff;

    node(int freq=0, string symbol="", node* left=NULL, node* right=NULL, string huff="") {
        this->freq = freq;
        this->symbol = symbol;
        this->left = left;
        this->right = right;
        this->huff = huff;
    }
};

void print_nodes(node* curr, map<string, string> &codes, string val = "") {
    string new_val = val + curr->huff;
    if (curr->left)
        print_nodes(curr->left, codes, new_val);
    if (curr->right)
        print_nodes(curr->right, codes, new_val);
    if (!curr->left && !curr->right) {
        cout << curr->symbol << " -> " << new_val << '\n';
		string curr_symbol = "";
		curr_symbol += curr->symbol;
		codes[curr_symbol] = new_val;
	}
}

node* huffman_codes(map<char, int> freq) {
	auto comp = [](auto& x, auto& y){return x->freq > y->freq;};
	priority_queue<node*, vector<node*>, decltype(comp)> nodes(comp);
	for (auto i : freq) {
		string curr_symbol = "";
		curr_symbol += i.first;
        node* curr = new node(i.second, curr_symbol);
		nodes.push(curr);
    }
	while (nodes.size() > 1) {
		node* left = nodes.top();
		nodes.pop();
		node* right = nodes.top();
		nodes.pop();
		left->huff = "0";
		right->huff = "1";
		node* new_node = new node(left->freq+right->freq, 
								  left->symbol+right->symbol, 
								  left, 
								  right);
		nodes.push(new_node);
	}
	node* root = nodes.top();
    return root;
}

string encoding(string s, map<string, string> &codes) {
    string encoded_string = "";
    for (int i = 0; i < s.size(); i++) {
		string curr_si = "";
		curr_si += s[i];
		encoded_string += codes[curr_si];
	}
    return encoded_string;
}

int main() {
	string s = "aafffafffcccaffffbeeefffffbbcccfffffccceeeefffdddeeeeeffccffddfffbbbbbbdddafffffddddeeeeffffcdffffff";
    map<char, int> freq;
	for (auto i : s) freq[i] ++;
	node* root = huffman_codes(freq);
	map<string, string> codes;
	print_nodes(root, codes);
    string encoded_string = encoding(s, codes);
	cout << "Encoded huffman data:\n" << encoded_string << '\n';
}
