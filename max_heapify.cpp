// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] < harr[i])
        largest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        largest = r;
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MinHeapify(largest);
    }
}