#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size()) {
                return intersect(nums2, nums1);
            }

            unordered_map<int, int> m;
            for (int x: nums1) {
            m[x]++;
            }

            int len = nums2.size();
            vector<int> ret;
            for (int i = 0; i < len; i++) {
                if (m.count(nums2[i])) {
                    if (m[nums2[i]] != 0) {
                        ret.push_back(nums2[i]);
                        m[nums2[i]]--;
                    }
                }
            }

            return ret;
        }
};