// Question - https://leetcode.com/problems/implement-trie-prefix-tree/

class node {
public:
    char data;
    unordered_map<char,node*> m;
    bool terminal;
    
    node(char d){
        data = d;
        terminal = false;
    }
};

class Trie {
public:
    node* root;
    
    Trie() {
        root = new node('\0');
    }
    
    void insert(string word) {
        node* temp = root;
        int idx = 0;
        while (idx < word.size() and (temp->m).find(word[idx]) != (temp->m).end()){
            temp = (temp->m)[word[idx++]];
        }
        if (idx == word.size()){
            temp->terminal = true;
            return;
        }
        while (idx < word.size()){
            (temp->m).insert({word[idx], new node(word[idx])});
            temp = (temp->m)[word[idx++]];
        }
        temp->terminal = true;
    }
    
    bool search(string word) {
        node* temp = root;
        int idx = 0;
        while (idx < word.size() and (temp->m).find(word[idx]) != (temp->m).end()){
            temp = (temp->m)[word[idx++]];
        }
        
        return (idx == word.size() and temp->terminal == true);
    }
    
    bool startsWith(string prefix) {
        node* temp = root;
        int idx = 0;
        while (idx < prefix.size() and (temp->m).find(prefix[idx]) != (temp->m).end()){
            temp = (temp->m)[prefix[idx++]];
        }
        
        return (idx == prefix.size());
    }
};
