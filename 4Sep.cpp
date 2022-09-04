// Question - https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
        unordered_map<char,int> toMatch;
        unordered_map<char,int> currWindow;
        
        for (char c : t){
            toMatch[c] += 1;
        }
        
        int start = 0, matched = 0;
        int minWindowLen = INT_MAX, minWindowStart = -1;
        for (int i=0; i<s.size(); i++){
            if (toMatch.find(s[i]) != toMatch.end()){
                if (currWindow[s[i]]<toMatch[s[i]])
                    matched++;
                currWindow[s[i]]++;
            }
            
            if (matched == t.size()){
                // cout<<"found at: "<<start<<" "<<i<<endl;
                while (toMatch.find(s[start])==toMatch.end() or currWindow[s[start]]>toMatch[s[start]]){
                    if (toMatch.find(s[start]) != toMatch.end())
                        currWindow[s[start]]--;
                    start++;
                }
                if (minWindowLen > i-start+1){
                    minWindowLen = i-start+1;
                    minWindowStart = start;
                }
                currWindow[s[start]]--;
                start++;
                // cout<<start<<" "<<i<<endl;
                matched--;
            }
        }
        
        if (minWindowStart == -1){
            return "";
        }
        string ans(s.begin()+minWindowStart, s.begin()+minWindowStart+minWindowLen);
        return ans;
        return s;
    }
