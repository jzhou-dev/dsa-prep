#include "leet.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> result;
      int start = 0;
      int len = words[0].size()+1;
      int num_words = 1;
      for (int i = 1; i < words.size(); i++) {
        int curr_size = words[i].size()+1;
        if (len+curr_size+num_words-1 > maxWidth) {
          string result = "";
          if (num_words == 1) {
            result+=words[start];
            result+=string(maxWidth-len, ' ');
            start++;
          } else {
            int num_gaps = num_words-1;
            int space = maxWidth-len / num_gaps;
            int overflow = maxWidth-len % num_gaps;
            for (int j = 0; j < num_words; j++) {
              new_line+=words[start];
              if (num_gaps) {
                if (overflow) {
                  new_line+=string(space+1, ' ');
                  overflow--;
                } else {
                  new_line+=string(space, ' ');
                }
                num_gaps--;
              }
              start++;
            }
          }
          result.push_back(new_line);
          len = 0;
          num_words = 0;
        }
        len+=words[i].size();
        num_words++;
      }
      return result;
    }
};
