// Question - https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

class Solution {
public:
    int readBefore;
    char* buf4;
    int lastRead;
    
    Solution(){
        readBefore = 0;
        buf4 = (char*)malloc(sizeof(char) * 5);
        lastRead = 0;
    }
    
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int newRead, charsRead = 0;
        if (readBefore%4 != 0){
            for (int i=readBefore%4; i<lastRead; i++){
                if (charsRead == n)
                    break;
                buf[charsRead++] = buf4[i];
            }
        }
        
        while(charsRead < n){
            newRead = read4(buf4);
            lastRead = newRead;
            if (newRead == 0)
                break;
            for (int i=0; i<newRead; i++){
                if (charsRead == n)
                    break;
                buf[charsRead++] = buf4[i];
            }
        }
        readBefore += charsRead;
        return charsRead;
    }
};
