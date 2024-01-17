**Find Median from Data Stream**

Problem Statement 123) The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = 
#define MAX_HEAP (2*100010) 

typedef struct { 
    int *root; 
    int size; 
    short (*comparator)(int a, int b);
    int end; /*always points to first open spot*/
} Heap;  

typedef struct {
    Heap *l; 
    Heap *r;
} MedianFinder;

Heap *heap_create(int mode); 
short min_comparator(int val1, int val2); 
short max_comparator(int val1, int val2); 
short insert(Heap *h, int val, short (*comp)(int a, int b)); 
int deletion(Heap *h, short (*comp)(int a, int b)); 
short push(Heap *heap, int val); 
int poll(Heap *heap);

MedianFinder* medianFinderCreate() {
    MedianFinder *med = malloc(sizeof(MedianFinder)); 
    med->l = heap_create(1); 
    med->r = heap_create(0); 
    return med;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(!obj) 
        return; 
    Heap *l = obj->l; 
    Heap *r = obj->r; 
    
    push(l,num); 
    push(r,poll(l)); 
    if(l->size < r->size) 
        push(l,poll(r)); 
    
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(!obj) 
        return 0.0;  
    
    Heap *l = obj->l; 
    Heap *r = obj->r;
    double med = 0.0; 
    
    if(l->size == r->size) 
        med = ((double) peek(l) + (double) peek(r))/2; 
    else 
        med = peek(l);
    
    return med;
}

void medianFinderFree(MedianFinder* obj) {
    if(!obj) 
        return;  
    
    free(obj->l->root); 
    free(obj->r->root); 
    free(obj->l); 
    free(obj->r); 
    
} 

Heap *heap_create(int mode) { 
    Heap *heap = malloc(sizeof(Heap)); 
    heap->root = calloc(sizeof(int), MAX_HEAP); 
    heap->size = 0; 
    heap->end = 0;  
    heap->comparator = !mode ? min_comparator : max_comparator;
    return heap;
}  

short min_comparator(int val1, int val2) { /*ret -1 if val1 less than val2, 1 greater, 0 if equal*/
    return val1 == val2 ? 0 : (val1>val2 ? 1 : -1);
} 

short max_comparator(int val1, int val2) { /*ret 1 if val1 less than val2, -1 greater, 0 if equal*/
    return -1*(val1 == val2 ? 0 : (val1>val2 ? 1 : -1));
} 

short insert(Heap *h, int val, short (*comp)(int a, int b)) { 
    if(h->size >= MAX_HEAP)
        return 0; 
    
    int *heap = h->root;  
    int curr = (h->end)++; 
    int par = (curr-1)/2;
    heap[curr] = val; 
    
    while(par>=0 && comp(heap[curr],heap[par]) == -1) {  
        int tmp = heap[par]; 
        heap[par] = heap[curr]; 
        heap[curr] = tmp;  
        
        curr = par;
        par = (curr-1)/2;
    } 
    
    (h->size)++;
    return 1;
} 

int deletion(Heap *h, short (*comp)(int a, int b)) { 
    
    int *heap = h->root; 
    int last = (h->end)-1; 
    int curr = 0;   
    int left = 2*curr+1; 
    int right = 2*curr+2; 
    int head = heap[0]; 
    
    heap[curr] = heap[last]; 
    
    while(right <= last && (comp(heap[curr],heap[left]) == 1 ||  
           comp(heap[curr],heap[right]) == 1)) {  
        
        int swap = 0;  
        
        if(comp(heap[curr],heap[left]) == 1 && comp(heap[curr],heap[right]) == 1)   
            swap = comp(heap[left],heap[right]) == -1 ? left : right; 
        
        else if(comp(heap[curr],heap[left]) == 1)  
            swap = left;  
        
        else  
            swap = right;   
        
        int tmp = heap[swap]; 
        heap[swap] = heap[curr]; 
        heap[curr] = tmp;
        
        curr = swap;
        left = 2*curr+1; 
        right = 2*curr+2;
    } 
    
    (h->end)--; 
    (h->size)--;
    return head;
} 

short push(Heap *heap, int val) { /*0 for min, 1 for max*/
    if(!heap) 
        return 0; 
    return insert(heap,val,heap->comparator);
}

int poll(Heap *heap) {  /*0 for min, 1 for max */ 
    assert(heap != NULL); 
    return deletion(heap,heap->comparator);  
} 

int peek(Heap *heap) { 
    return (heap->root)[0];
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/

--------------------------------------------------------------Explanation:-
Key Structures:

Heap: A data structure that maintains a partial ordering of elements, used here to efficiently manage the numbers in the stream.
MedianFinder: A struct that uses two heaps to track the smaller and larger halves of the numbers, enabling efficient median calculation.
Key Functions:

heap_create: Creates a min-heap or max-heap based on the mode parameter.
min_comparator, max_comparator: Comparator functions for min-heaps and max-heaps, respectively.
insert, deletion: Insert and remove elements from a heap, maintaining heap properties.
push, poll, peek: Wrappers for insert and deletion, providing simpler interfaces.
MedianFinder Functions:

medianFinderCreate: Creates a MedianFinder object with two heaps: a max-heap for the smaller half and a min-heap for the larger half.
medianFinderAddNum: Adds a number to the MedianFinder by:
Inserting it into the max-heap (smaller half).
Moving the largest element from the max-heap to the min-heap (larger half).
Rebalancing the heaps if their sizes differ by more than 1.
medianFinderFindMedian: Returns the median by:
Directly returning the top element of the max-heap if the heaps have equal sizes.
Averaging the tops of both heaps if the sizes differ by 1.
medianFinderFree: Frees the memory allocated for the MedianFinder object.
Key Concepts:

Heap-Based Median Finding: Leverages two heaps to divide the numbers into two halves, enabling efficient median calculation in logarithmic time.
Balancing Heaps: The medianFinderAddNum function ensures the heaps' sizes differ by at most 1 to maintain a balanced representation of the numbers.
Median Calculation: The median is found directly from the top elements of the heaps, or their average, depending on the heap sizes.
