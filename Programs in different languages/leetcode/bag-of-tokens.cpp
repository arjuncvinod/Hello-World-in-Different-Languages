// question link - https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        vector<int> scores;
        sort(tokens.begin(), tokens.end());
        int powerNeeded = 0;
        int lastPlayedIndex = -1;
        map<int, int> marker;
        for(int i=0; i<tokens.size(); i++) {
            if(power>= tokens[i]) {
                score++;
                power -= tokens[i];
                marker[tokens[i]] = 1;
                lastPlayedIndex = i;
            } else {
                powerNeeded += tokens[i];
            }
        }
        int testScore = score;
        scores.push_back(score);
        if(testScore >= 1) {
            for(int i=tokens.size()-1; i>0; i--) {
                if(marker[tokens[i]] == 0) {                    
                    testScore--;
                    power += tokens[i];
                    int testPower = power;
                    int newTestScore = testScore;
                    for(int j=lastPlayedIndex+1; j<i; j++) {
                        if (testPower >= tokens[j]) {
                            newTestScore++;
                            testPower-= tokens[j];
                        } else {
                            break;
                        }
                    }
                    if(newTestScore < scores[scores.size()-1]) {
                        break;
                    }
                    scores.push_back(newTestScore);
                }
            }
        }
        return scores[scores.size()-1];
        
    }
};