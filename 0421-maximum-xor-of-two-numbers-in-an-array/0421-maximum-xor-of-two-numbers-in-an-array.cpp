struct Node {
    vector<Node*> links = vector<Node*>(2, NULL);

    bool isContain(int bit) {
        return links[bit] != NULL;
    }

    Node* nextNode(int bit) {
        return links[bit];
    }

    void put(int bit) {
        links[bit] = new Node();
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(!node->isContain(bit)) {
                node->put(bit);
            }

            node = node->nextNode(bit);
        }
    }
    
    int getMaxXor(int num) {
        Node* node = root;

        int maxi = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->isContain(1 - bit)) {
                maxi = maxi | (1 << i);

                node = node->nextNode(1 - bit);
            }
            else {
                node = node->nextNode(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;

        Trie trie;

        for(int& num : nums) {
            trie.insert(num);
        }

        for(int& num : nums) {
            ans = max(ans, trie.getMaxXor(num));
        }

        return ans;
    }
};