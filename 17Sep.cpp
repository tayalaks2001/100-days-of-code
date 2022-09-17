// Question - https://leetcode.com/problems/palindrome-pairs/

class node {
public:
    char val;
    int terminal;
    unordered_map<char, node*> m;
    vector<int> indices;
    
    node(char val){
        this->val = val;
        terminal = -1;
    }
};

class Trie {
public:
    node* root;
    
    Trie(){
        root = new node('\0');
    }
    
    void addWords(vector<string> &words){
        for (int i=0; i<words.size(); i++){
            node* temp = root;
            for (int j=words[i].size()-1; j>=0; j--){
                if (temp->m.find(words[i][j]) == temp->m.end()){
                    temp->m[words[i][j]] = new node(words[i][j]);
                }
                temp->indices.push_back(i);
                temp = temp->m[words[i][j]];
            }
            temp->terminal = i;
        }
    }
    
    node* lastNode(string &word){
        node* temp = root;
        for (int i=word.size()-1; i>=0; i--){
            if (temp->m.find(word[i]) == temp->m.end())
                return nullptr;
            temp = temp->m[word[i]];
        }
        return temp;
    }
};

class Solution {
public:
    bool palindromic(string &s, int start, int end){
        while (start < end){
            if (s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;
    
        Trie t;
        t.addWords(words);
        for (int i=0; i<words.size(); i++){
            node* temp = t.root;
            if (temp->terminal != -1 and temp->terminal != i and palindromic(words[i],0,words[i].size()-1)){
                pairs.push_back({i, temp->terminal});
            }
            bool reachedEnd = true;
            for (int j=0; j<words[i].size(); j++){
                if (temp->m.find(words[i][j]) == temp->m.end()){
                    reachedEnd = false;
                    break;
                }
                temp = temp->m[words[i][j]];
                if (temp->terminal != -1 and temp->terminal != i and palindromic(words[i],j+1,words[i].size()-1)){
                    pairs.push_back({i,temp->terminal});
                }
            }
                    
            if (reachedEnd){
                for (int idx : temp->indices){
                    if (palindromic(words[idx], 0, words[idx].size()-words[i].size()-1)){
                        pairs.push_back({i,idx});
                    }
                }
            }
        }
        
        return pairs;
    }
};
