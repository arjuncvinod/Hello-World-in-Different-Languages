// question link - https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    
    
    bool isPalindrome(string str){
        int length = str.length();
        if(length % 2 == 0) {
            for(int i=0; i<length/2; i++) {
                if(str[i] != str[length-i-1]) {
                    return false;
                }
            }
        } else {
            for(int i=0; i<(length-1)/2; i++) {
                if(str[i] != str[length-i-1]) {
                    return false;
                }
            }
        }
        return true;
        
    }
    
    string breakPalindrome(string palindrome) {
        unordered_map<char, int> mapper;
        int num = 0;
        vector<int> res;
        string result = "";
        if(palindrome.length() == 1){
            return result;
        }
        for(int i=1; i<27; i++) {
            mapper[char(96+i)] = i;
        }
        for(int i=0; i<palindrome.length(); i++) {
            res.push_back(mapper[palindrome[i]]);
        }
        int positionToUpdate = 0;
        while(1) {
            while (res[positionToUpdate] - 1 == 0){
                positionToUpdate++;   
                if(positionToUpdate >= palindrome.length()) {
                    result = palindrome.substr(0,palindrome.length()-1);
                    result += "b";
                    return result;
                }
            }
            if(positionToUpdate > palindrome.length()) {
                return "";
            }
            res[positionToUpdate] = 1;
            for(int i=0; i<res.size(); i++){
                result += char(res[i]+96);
            }
            if(!isPalindrome(result)) {
                break;
            }
        }
        return result;
    }
};