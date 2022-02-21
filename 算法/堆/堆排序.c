void heapify(int *arr, int n, int i){
    //i 是待调整的节点下标
    int largest = i; // i当作最大的
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;
    if(lson < n && arr[largest] < arr[lson]) largest = lson;
    if(rson < n && arr[largest] < arr[rson]) largest = rson;
    if(largest != i){
        int tmp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = tmp;
        heapify(arr, n, largest);
    }
}

void init_heap(int *arr, int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
}

void heap_sort(int *arr, int n){
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}