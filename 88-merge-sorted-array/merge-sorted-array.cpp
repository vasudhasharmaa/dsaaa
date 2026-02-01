class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // create a temporary vector
        vector<int> temp;

        int i = 0, j = 0;

        // merge logic from your code
        while (i < m && j < n) {
            if (nums1[i] != nums2[j] && nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                temp.push_back(nums2[j]);
                j++;
            }
            else {
                temp.push_back(nums1[i]);
                temp.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        // copy remaining elements from nums1
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }

        // copy remaining elements from nums2
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }

        // copy back into nums1
        for (int k = 0; k < temp.size(); k++) {
            nums1[k] = temp[k];
        }
    }
};
