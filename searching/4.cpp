#include <vector>

using namespace std;


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

//         int m = nums1.size(), n = nums2.size();
//         int size = m + n;
//         if (size % 2) {
//             return getMedium(nums1, nums2, size/2);
//         }
//         else {
//             return (double)(getMedium(nums1, nums2, size/2-1) + getMedium(nums1, nums2, size/2)) / 2;
//         }
//     }

//     int getMedium(const vector<int>& nums1, const vector<int>& nums2, const int& s) {
//         int n1 = 0, n2 = 0, min_ele = 0, m = nums1.size(), n = nums2.size();
//         while (n1 + n2 <= s) {
//             if (n1 < m && n2 < n)
//                 min_ele = nums1[n1] < nums2[n2] ? nums1[n1++] : nums2[n2++];
//             else if (n1 >= m) 
//                 min_ele = nums2[n2++];
//             else 
//                 min_ele = nums1[n1++];
//             }
//         return min_ele;
//     }
// };
// O(m+n)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int size = n1 + n2;
        if (size % 2) 
            return (double) getMedium(nums1, nums2, size / 2, 0, n1-1, 0, n2-1);
        else 
            return (double) (getMedium(nums1, nums2, size / 2 - 1, 0, n1-1, 0, n2-1) + getMedium(nums1, nums2, size / 2, 0, n1-1, 0, n2-1)) / 2;
        
        
    }

    int getMedium(const vector<int>& a, const vector<int>& b, const int& h, int a_start, int a_end, int b_start, int b_end) {
                                                            // head position
        if (a_start > a_end) return b[h - a_start];
        if (b_start > b_end) return a[h - b_start];
        
        int a_mid = (a_start + a_end) / 2, b_mid = (b_start + b_end) / 2;
        int a_value = a[a_mid], b_value = b[b_mid];

        if (a_mid + b_mid < h) {
            if (a_value < b_value) 
                return getMedium(a, b, h, a_mid+1, a_end, b_start, b_end);
            
            else
                return getMedium(a, b, h, a_start, a_end, b_start+1, b_end);
        }
        else {
            if (a_value < b_value) 
                return getMedium(a, b, h, a_start, a_end, b_start, b_mid-1);
            
            else
                return getMedium(a, b, h, a_start, a_mid-1, b_start, b_end);
        }

    }

};