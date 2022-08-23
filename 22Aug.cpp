// Question - mplement a data structure to count the number of strings with a given prefix. Assume a large number of prefix counts will be requested for the same dictionary

class node {
    public:
    char data;
    unordered_map<char,node*> m;
    bool terminal;
    int count;
    
    node(char d){
        data = d;
        terminal = false;
        count = 0;
    }
};

class Solution {
    node* root;
public:
    Solution(){
        root = new node('\0');
    }
    
    void insert(string word){
        node* t = root;
        for (int i=0; i<word.size(); i++){
            t->count++;
            if (t->m.find(word[i]) == t->m.end())
                t->m[word[i]] = new node(word[i]);
            t = t->m[word[i]];
        }
        
        t->terminal = true;
        t->count++;
    }
    
    int prefixCount(vector<string>& words, string prefix) {
        for (string w : words)
            insert(w);
        
        node* t = root;
        for (int i=0; i<prefix.size(); i++){
            if (t->m.find(prefix[i]) == t->m.end())
                return 0;
            t = t->m[prefix[i]];
        }
        return t->count;
    }
};
