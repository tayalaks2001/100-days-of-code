// Question - https://leetcode.com/problems/subdomain-visit-count/

#include<bits/stdc++.h>
using namespace std;

int strToNum(string s){
        int ans = 0;
        for (int i=0; i<s.size(); i++){
            ans = (ans*10) + s[i]-'0';
        }
        return ans;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        unordered_map<string,int> m;
        
        for (string s : cpdomains){
            string num = (string)strtok((char*)s.c_str()," ");
            int count = strToNum(num);
            
            string domain = (string)strtok(NULL, " ");
            vector<string> components;
            char* ptr = strtok((char*)domain.c_str(),".");
            while(ptr != NULL){
                components.push_back((string)ptr);
                ptr = strtok(NULL, ".");
            }
            
            string subdomain = components[components.size()-1];
            m[subdomain] += count;
            for (int i=components.size()-2; i>=0; i--){
                subdomain = components[i] + "." + subdomain;
                m[subdomain] += count;
            }
        }
        
        for (auto it=m.begin(); it!=m.end(); it++){
            string cp = to_string(it->second) + " " + it->first;
            result.push_back(cp);
        }
        
        return result;
    }
