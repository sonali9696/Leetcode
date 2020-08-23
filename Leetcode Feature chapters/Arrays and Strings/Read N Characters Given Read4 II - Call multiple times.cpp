/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    char buf4[4];
    int pos4 = 0, n4 = 0;
    
    int read(char *buf, int n) {
        int i = 0;
        while(i < n)
        {
            if(n4 == 0) 
            {
                n4 = read4(buf4);
                if(n4 == 0) break;
            }
            
            while(i<n && pos4 < n4)
                buf[i++] = buf4[pos4++];
            
            if(pos4 >= n4)
            {
                pos4 = 0;
                n4 = 0;
            }
            
        }
        
        return i;
    }

};