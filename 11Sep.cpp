// Question - https://leetcode.com/problems/non-overlapping-intervals/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int e = intervals[0][1];
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i][0] < e){
                count++;
                if (intervals[i][1] < e){
                    e = intervals[i][1];
                }
            }
            else{
                e = intervals[i][1];
            }
        }
        return count;
    }
