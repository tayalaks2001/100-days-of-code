// Question - https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Approach 1 - Trie
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

class WordDictionary {
    node* root;
    
    bool searchHelper(string &word, node* searchFrom, int idx = 0){
        if (idx == word.size())
            return searchFrom->terminal;
        
        for (int i=idx; i<word.size(); i++){
            if (word[i] == '.'){
                for(auto it=searchFrom->m.begin(); it != searchFrom->m.end(); it++)
                    if (searchHelper(word,it->second,i+1))
                        return true;
                return false;
            }
            
            if (searchFrom->m.find(word[i]) == searchFrom->m.end())
                return false;
            
            searchFrom = searchFrom->m[word[i]];
        }
        
        return searchFrom->terminal;
    }
    
public:
    WordDictionary() {
        root = new node('\0');
    }
    
    void addWord(string word) {
        node* temp = root;
        for (int i=0; i<word.size(); i++){
            if (temp->m.find(word[i]) == temp->m.end()){
                temp->m[word[i]] = new node(word[i]);
            }
            temp = temp->m[word[i]];
        }
        temp->terminal = true;
    }
    
    bool search(string word) {
        return searchHelper(word,root);
    }
};



// Approach 2 - Hashing (set) -> better
class WordDictionary {
public:
    WordDictionary()
    {
        _words.resize(26);
    }

    void addWord(const string& word) {
        _words[word.size()].insert(word);
    }

    bool search(const string& word) {
        if (word.find('.') == string::npos) return _words[word.size()].find(word) != _words[word.size()].end();

        for (const auto& w : _words[word.size()])
        {
            bool match {true};
            for (size_t i = 0; i < word.size(); ++i)
            {
                if(word[i] == '.') continue;
                if (word[i] != w[i]) 
                {
                    match = false;
                    break;
                }
            }
            if(match) { return true;}
            
        }
        return false;
    }

private:
    vector<unordered_set<string>> _words;
}; 
