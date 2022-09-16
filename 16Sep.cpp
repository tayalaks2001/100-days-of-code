// Question - https://leetcode.com/problems/sliding-window-maximum/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<pair<int,int> > window;
        vector<int> maxWindow;
        
        for (int i=0; i<k; i++){
            while (!window.empty() and window.back().second <= nums[i]){
                window.pop_back();
            }
            window.push_back({i,nums[i]});
        }
        maxWindow.push_back(window.front().second);
        
        for (int i=k; i<nums.size(); i++){
            while (!window.empty() and window.front().first <= i-k){
                window.pop_front();
            }
            while (!window.empty() and window.back().second <= nums[i]){
                window.pop_back();
            }
            
            window.push_back({i,nums[i]});
            maxWindow.push_back(window.front().second);
        }
        
        return maxWindow;
    }
