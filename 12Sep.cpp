// Question - https://leetcode.com/problems/prefix-and-suffix-search/

class node {

public:
    char val;
    unordered_map<char,node*> m;
    vector<int> indices;
    bool terminal;
    
    node(char val){
        this->val = val;
        terminal = false;
    }
};

class WordFilter {
public:
    node* inorder;
    node* revorder;
    vector<string> words;

    WordFilter(vector<string>& words) {
        inorder = new node('\0');
        revorder = new node('\0');
        
        for (int idx = 0; idx<words.size(); idx++){
            string word = words[idx];
            this->words.push_back(word);
            
            node* temp = inorder;
            for (int i=0; i<word.size(); i++){
                temp->indices.push_back(idx);
                if (temp->m.find(word[i]) == temp->m.end()){
                    temp->m[word[i]] = new node(word[i]);
                }
                temp = temp->m[word[i]];
            }
            temp->indices.push_back(idx);
            temp->terminal = true;
            
            temp = revorder;
            reverse(word.begin(), word.end());
            for (int i=0; i<word.size(); i++){
                temp->indices.push_back(idx);
                if (temp->m.find(word[i]) == temp->m.end()){
                    temp->m[word[i]] = new node(word[i]);
                }
                temp = temp->m[word[i]];
            }
            temp->indices.push_back(idx);
            temp->terminal = true;
        }
    }
    
    int f(string pref, string suf) {
        
        node* prefMatching = inorder;
        for (int i=0; i<pref.size(); i++){
            if (prefMatching->m.find(pref[i]) == prefMatching->m.end())
                return -1;
            prefMatching = prefMatching->m[pref[i]];
        }
        if (prefMatching->indices.size() == 0)
            return -1;
        
        node* sufMatching = revorder;
        for (int i=suf.size()-1; i>=0; i--){
            if (sufMatching->m.find(suf[i]) == sufMatching->m.end())
                return -1;
            sufMatching = sufMatching->m[suf[i]];
        }
        if (sufMatching->indices.size() == 0)
            return -1;
        
        int i = prefMatching->indices.size()-1, j = sufMatching->indices.size()-1;
        while (i>=0 and j>=0){
            int a = prefMatching->indices[i], b = sufMatching->indices[j];
            if (a == b)
                return a;
            else if (a > b){
                i--;
            }
            else{
                j--;
            }
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
