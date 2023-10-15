
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Save the length of the mountain array
        int n = mountainArr.length();

        // 1. Find the index of the peak element
        int s = 1;
        int e = n - 2;
        while (s != e) {
            int mid = (s + e) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        int peakIndex = s;

        // 2. Search in the strictly increasing part of the array
        s = 0;
        e = peakIndex;
        while (s != e) {
            int mid = (s + e) / 2;
            if (mountainArr.get(mid) < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        // Check if the target is present in the strictly increasing part
        if (mountainArr.get(s) == target) {
            return s;
        }

        // 3. Otherwise, search in the strictly decreasing part
        s = peakIndex + 1;
        e = n - 1;
        while (s != e) {
            int mid = (s + e) / 2;
            if (mountainArr.get(mid) > target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        // Check if the target is present in the strictly decreasing part
        if (mountainArr.get(s) == target) {
            return s;
        }

        // Target is not present in the mountain array
        return -1;
    }
};
