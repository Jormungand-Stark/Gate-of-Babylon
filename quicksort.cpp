//flag参与置换
void quicksort(vector<int>& arr, int left, int right){
  if(left > right){
    return;
  }
  int i = left;
  int j = right;
        
  int flag = arr[i];
  while(i!=j){
    while(i<j && arr[j]>=arr[i] ){
      j--;
    }
    swap(arr[i], arr[j]);
    while(i<j && arr[i]<=arr[j]){
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
    while(i<j && arr[j]>=flag){
      j--;
    }
    while(i<j && arr[i]<=flag){
      i++;
    }
    swap(arr[i], arr[j]);
  }
  swap(arr[i], arr[left]);
  quicksort(arr, left, i-1);
  quicksort(arr, i+1, right);
}
