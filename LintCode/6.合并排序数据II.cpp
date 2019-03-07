class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        if (A.size() == 0) return B;
        if (B.size() == 0) return A;
        int i = 0,
            j = 0,
            k = 0;
        vector<int> result;
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) {
                result.push_back(A[i++]);
            } else {
                result.push_back(B[j++]);
            }
        }
        
        while (i < A.size()) {
            result.push_back(A[i++]);
        }
        while (j < B.size()) {
            result.push_back(B[j++]);
        }
        return result;
    }
};
