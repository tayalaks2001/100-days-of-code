// Question - https://leetcode.com/problems/encode-and-decode-strings/

class Codec {
    int len = 8;
public:
    string getBinary(int n){
        string res;
        while (n){
            res.push_back('0'+n%2);
            n /= 2;
        }
        for (int i=res.size(); i<len; i++)
            res.push_back('0');
        reverse(res.begin(), res.end());
        return res;
    }
    
    int getNum(string bin){
        int n = 0;
        for (int i=0; i<len; i++){
            n = n*2 + (bin[i] == '1');
        }
        return n;
    }
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string s : strs){
            string length = getBinary(s.size());
            res += length + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while (i < s.size()){
            string lengthBin(s.begin()+i, s.begin()+i+8);
            int length = getNum(lengthBin);
            string next(s.begin()+i+8, s.begin()+i+8+length);
            res.push_back(next);
            i = i+8+length;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
