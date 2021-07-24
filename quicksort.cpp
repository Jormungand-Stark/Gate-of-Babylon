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
