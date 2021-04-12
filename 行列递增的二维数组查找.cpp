#include <vector>

using namespace std;

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0){
      return false;
    }

    int row = matrix.size();
    int col = matrix[0].size();
    int i = 0;
    int j = col - 1;

    while (i < row && j >= 0) {
      int temp = matrix[i][j];
      if(temp == target){
        return true;
      }
      else{
        if (temp > target) {
          j--;
        }
        else{
          i++;
        }
      }
    }

    return false;
  }
};
