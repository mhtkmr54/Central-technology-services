/*
 * Complete the function below.
 */
int binarySearch(int first, int last, vector<int> arr, int search) {
   int r = last;
    int l = first;
    int x = search; 
    if (r >= l){
        int mid = l + (r - l)/2;
        if (arr[mid] == x) {
            return arr[mid];
        }
        if (arr[mid] < x){
            return binarySearch(l, mid-1,arr, x);
        } 
        else{
            return binarySearch( mid+1, r,arr, x);
        }
    }
   return -1;
}



bool compare(int a, int b){
    return a > b;
}

int maxElement(vector < int > arr) {
   sort(arr.begin(), arr.end(), compare);
   int n = arr.size();
   if (n < 3){
       return -1;
   }
   for(int i = 0; i < arr.size(); i++){
       int max_el = arr[i];
       cout << "max el " << max_el << endl;
       for(int i = 0; i < arr.size() - 1 ; i++) {
            int search = max_el - arr[i+1];
            cout << " search for " << search << " " << "complement of " << arr[i+1] << endl;
            if(search <= arr[i+1]) {
                int index = binarySearch( i + 2, n - 1, arr, search);
                cout << "index " << index << endl; 
                if( index == -1 ) {
                    cout << "nein" << endl;
                }else{
                    return max_el;
                }
            }
       }
   }
  return -1;
}


