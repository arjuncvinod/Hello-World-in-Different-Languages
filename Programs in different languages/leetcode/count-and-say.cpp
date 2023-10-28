// question link - https://leetcode.com/problems/count-and-say/


class Solution {
public:
    
    string count(int n) {
        unordered_map<string, string> umap;
        unordered_map<int, string> umap2;
        umap["one"] = "1";
        umap["two"] = "2";
        umap["three"] = "3";
        umap["four"] = "4";
        umap["five"] = "5";
        umap["six"] = "6";
        umap["seven"] = "7";
        umap["eight"] = "8";
        umap["nine"] = "9";
        
        umap2[1] = "one";
        umap2[2] = "two";
        umap2[3] = "three";
        umap2[4] = "four";
        umap2[5] = "five";
        umap2[6] = "six";
        umap2[7] = "seven";
        umap2[8] = "eight";
        umap2[9] = "nine";
        if(n == 1) return "1";
        int res = 0;
        string num = "11";
        
        for(int i=2; i<n ; i++) {    
            int freq = 1;
            string res = "";
            int j=0;
            for(j=0; j<num.length()-1; j++) {
                if(num[j] == num [j+1]) {
                    freq++;
                } else {
                    res += umap2[freq] + num[j];
                    
                    freq = 1;
                }
            }
            res += umap2[freq] + num[j];
            // cout<<" " << res<<endl;
            num = "";
            string str = "";
            for(int j=0; j<res.length(); j++) {
                
                if(isdigit(res[j])) {
                    num += umap[str] + res[j];
                    str = "";
                } else {
                    str += res[j];
                }
            }
            // cout<<res<<"  --   "<<num<<endl;
        }
        
        return num;
    }
    
    
    string countAndSay(int n) {
        
        
        return count(n);
    }
};