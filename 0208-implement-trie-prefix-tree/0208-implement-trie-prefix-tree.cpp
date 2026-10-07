struct Node {
    // Each index represents one lowercase English character
    vector<Node*> links = vector<Node*>(26, NULL);

    // True if a complete word ends at this node
    bool flag = false;

    bool isContain(char c) {
        return links[c - 'a'] != NULL;
    }

    void put(char c) {
        links[c - 'a'] = new Node();
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for(char c : word) {
            // Create the node if this character doesn't exist
            if(!curr->isContain(c)) {
                curr->put(c);
            }

            // Move to the next character
            curr = (curr->links)[c - 'a'];
        }

        // Mark the end of the complete word
        curr->flag = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for(char c : word) {
            // Character path doesn't exist
            if(!curr->isContain(c)) {
                return false;
            }

            curr = (curr->links)[c - 'a'];
        }

        // Check whether this path represents a complete word
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(char c : prefix) {
            // Prefix path doesn't exist
            if(!curr->isContain(c)) {
                return false;
            }

            curr = (curr->links)[c - 'a'];
        }

        // Entire prefix exists in the Trie
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */