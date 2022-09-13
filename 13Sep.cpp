// Question - https://leetcode.com/problems/alien-dictionary/

#define us unordered_set<char>

class Graph {
public:
    unordered_map<char,unordered_set<char> > m;
    us nodes;
    
    void addEdge(char pre, char post){
        m[pre].insert(post);
        nodes.insert(pre);
        nodes.insert(post);
    }
    
    void print(){
        for (auto p : m){
            cout<<p.first<<": ";
            for (char c : p.second){
                cout<<c<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    bool helper(char curr, string &ordering, us &stack, us &visited){
        if (visited.find(curr) != visited.end())
            return true;
        
        visited.insert(curr);
        if (stack.find(curr) != stack.end())
            return false;
        stack.insert(curr);
        for (char nbr : m[curr]){
            if (stack.find(nbr) != stack.end()){
                return false;
            }
            if (!helper(nbr, ordering, stack, visited))
                return false;
        }
        stack.erase(curr);
        ordering.push_back(curr);
        return true;
    }
    
    pair<string,bool> getOrdering(){
        string ordering;
        us stack;
        us visited;
        
        for (char c : nodes){
            if (visited.find(c)==visited.end()){
                // call helper
                if(!helper(c, ordering, stack, visited)){
                    return {"",false};
                }
            }
        }
        
        reverse(ordering.begin(), ordering.end());
        return {ordering,true};
    }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        Graph g;
        unordered_set<char> chars;
        for (int i=0; i<words.size(); i++){
            for (char c : words[i]){
                chars.insert(c);
            }
        }
        for (int i=0; i<words.size(); i++){
            for (int j=i+1; j<words.size(); j++){
                int it1=0, it2=0;
                while(it1<words[i].size() and it2<words[j].size()){
                    if (words[i][it1] != words[j][it2])
                        break;
                    it1++, it2++;
                }
                
                if (it1<words[i].size() and it2<words[j].size()){
                    g.addEdge(words[i][it1], words[j][it2]);   
                }
                else if (words[i].size() > words[j].size()){
                    return "";
                }
            }
        }
        
        // g.print();
        pair<string,bool> orderPair = g.getOrdering();
        if (!orderPair.second)
            return orderPair.first;
        
        string order = orderPair.first;
        for (char c : order){
            chars.erase(c);
        }
        
        if (chars.size() > 0){
            for (char c : chars){
                order.push_back(c);
            }
        }
        return order;
    }
};
