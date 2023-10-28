class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        bool exitFlag = false;
        // x = abs(x);
        cout<<"x is = "<<x<<endl;
        map<int, vector<int>> umap;
        for(int i=0; i<arr.size(); i++) {
            int val = (arr[i]);
            if(umap[abs(val - x)].size() != 0) {
                umap[abs(val - x)].push_back(i);
            } else {
                vector<int> temp;
                temp.push_back(i);
                umap[abs(val- x)] = temp;
            }
        }
        
        for(auto it=umap.begin(); it!=umap.end(); it++) {
            for(int i=0; i<it->second.size(); i++) {
                res.push_back(arr[it->second[i]]);
                if (res.size() == k){
                    exitFlag = true;
                    break;
                }
            }
            if(exitFlag) {
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};