// Question - https://www.hackerrank.com/challenges/non-divisible-subset/problem?isFullScreen=true

// Evenly divisible by k only means perfectly divisible by k, doesn't mean divisible and quotient is even (wasted an hour on this)

int nonDivisibleSubset(int k, vector<int> s) {
    unordered_map<int,vector<int>> m;
    for (int i : s){
        m[i%k].push_back(i);
    }
    int count = 0;
    for (auto p : m){
        if (p.second.size() == 0)
            continue;
            
        if (p.first == 0){
            count++;
        }
        else if (k%2 == 0 and p.first == k/2){
            count++;
        }
        else{
            int mod1 = p.first, mod2 = k-p.first;
            if (m.find(mod2) == m.end()){
                count += p.second.size();
            }
            else{
                count += max(m[mod1].size(), m[mod2].size());
                m[mod2].clear();
            } 
        }
        m[p.first].clear();
    }
    
    return count;
}

