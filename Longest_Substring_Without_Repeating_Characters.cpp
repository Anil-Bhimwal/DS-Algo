class Solution {
public:
    int lengthOfLongestSubstring(string str) {
    int n = str.size(); 
    int len_now = 1;  
    int max_len = 1; 
      
    int* visited = new int[sizeof(int) * 256]; 
    int pre_index; 

    for (int i = 0; i < 256; i++) 
        visited[i] = -1; 
    visited[str[0]] = 0; 
    for (int i = 1; i < n; i++) { 
        pre_index = visited[str[i]]; 
        if (pre_index == -1 || i - len_now > pre_index) 
            len_now++; 
        else { 
            if (len_now > max_len) 
                max_len = len_now; 
  
            len_now = i - pre_index; 
        } 
        visited[str[i]] = i; 
    } 
  
    if (len_now > max_len) 
        max_len = len_now; 
    delete []visited; // free memory allocated for visited 
    return max_len; 
    }
};