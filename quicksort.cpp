//flag参与置换
void quicksort(vector<int>& arr, int left, int right){
  if(left > right){
    return;
  }
  int i = left;
  int j = right;
        
  int flag = arr[i];
  while(i!=j){
    while(arr[j]>=arr[i] && i<j){
      j--;
    }
    swap(arr[i], arr[j]);
    while(arr[i]<=arr[j] && i<j){
      i++;
    }
    swap(arr[i], arr[j]);
  }
  quicksort(arr, left, i-1);
  quicksort(arr, i+1, right);
}


//另一种，flag不参与置换，最后归位flag。
void  quicksort ( vector < int >&  arr , int  left , int  right ){
  if(left > right){
    return;
  }
  int i = left;
  int j = right;
        
  int flag = arr[i];
  while(i!=j){
    while(arr[j]>=flag && i<j){
      j--;
    }
    while(arr[i]<=flag && i<j){
      i++;
    }
    swap(arr[i], arr[j]);
  }
  swap(arr[i], arr[left]);
  quicksort(arr, left, i-1);
  quicksort(arr, i+1, right);
}
