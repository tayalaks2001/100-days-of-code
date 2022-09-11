// Question - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

bool inRange(int &n, int &s, int &e){
        return (n>=s and n<=e);
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int s = points[0][0], e = points[0][1];
        for (int i=1; i<points.size(); i++){
            if (inRange(points[i][0],s,e) or inRange(points[i][1],s,e)){
                s = max(s,points[i][0]);
                e = min(e,points[i][1]);
            }
            else{
                count++;
                s = points[i][0];
                e = points[i][1];
            }
        }
        return count;
    }
