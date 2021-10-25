class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = (s.size() - 1);
        for (int i = 0; i < end; i++) 
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};
