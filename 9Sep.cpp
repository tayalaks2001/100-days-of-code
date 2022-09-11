// Question - https://leetcode.com/problems/meeting-rooms-ii/

int minMeetingRooms(vector<vector<int>>& intervals) {
        int curr = 0, maxm = 1;
        map<int,int> m;
        for (int i=0; i<intervals.size(); i++){
            int s=intervals[i][0], e=intervals[i][1];
            m[s]++;
            m[e]--;
        }
        
        for (auto p : m){
            curr += p.second;
            maxm = max(maxm,curr);
        }
        return maxm;
    }
