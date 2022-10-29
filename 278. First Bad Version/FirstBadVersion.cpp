// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n-1;
        int middle = left + (right-left)/2;
        int firstBadVersion = n;
        do
        {
            if(isBadVersion(middle+1))
            {
                firstBadVersion = middle+1;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
            
            middle = left + (right-left)/2;
            
        } while (left<=right);
        
        return firstBadVersion;
    }
};
