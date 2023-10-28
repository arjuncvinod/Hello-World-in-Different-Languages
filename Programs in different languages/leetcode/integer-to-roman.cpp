// question link - https://leetcode.com/problems/integer-to-roman


class Solution {
public:
    unordered_map<int, string> mapper;
    
    string intToRoman(int num) {
    mapper[1] = "I";
    mapper[4] = "IV";
    mapper[5] = "V";
    mapper[9] = "IX";
    mapper[10] = "X";
    mapper[40] = "XL";
    mapper[50] = "L";
    mapper[90] = "XC";
    mapper[100] = "C";
    mapper[400] = "CD";
    mapper[500] = "D";
    mapper[900] = "CM";
    mapper[1000] = "M";
    mapper[2000] = "MM";
    mapper[3000] = "MMM";
    string res = "";
    int n = num;
    int len = 0;
    while(n % 10 != 0) {
        len++;
        n = n/10;
    }
    // cout<<"len of num = "<<len<<endl;
    vector<int> digits;
    n = num;
    if (len == 1) {
        digits.push_back(n);
    } else {
        while(n != 0) {
            int p = pow(10,len);
            int i;
            if(p == 1) {
                i = n / p;
            }
            else {
                i = n % p;
                i = n - i;    
            }
            digits.push_back(i);
            len--;
            n = n - i;
        }
    }
        
        for(int i=0; i<digits.size(); i++) {
            if(digits[i] != 0) {
                int no = digits[i];
                while(no != 0) {
                    int j = no;
                    while(mapper[j] == "") {
                        j--;
                    }
                    res += mapper[j];
                    no = no - j;
                }
                
            }
        }cout<<endl;
        
    return res;
    }
};