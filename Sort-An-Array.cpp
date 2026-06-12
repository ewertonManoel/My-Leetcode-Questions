void insertionSort(vector<int>& vect, int l, int r) {
    for(int i = l + 1; i <= r; i++) {
        int key = vect[i];
        int j = i - 1;
        while(j >= l && key < vect[j]) {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = key;
    }
}

void heapify(vector<int>& vect, int n, int i, int offset) {
    while(true) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l < n && vect[l + offset] > vect[largest + offset]) largest = l;
        if(r < n && vect[r + offset] > vect[largest + offset]) largest = r;

        if(largest != i) {
            swap(vect[i + offset], vect[largest + offset]);
            i = largest;
        }
        else break;
    }
}

void heapSort(vector<int>& vect, int l, int r) {
    int n = (r - l) + 1;
    for(int i = n / 2 - 1; i >= 0; i--) heapify(vect, n, i, l);
    for(int j = n - 1; j > 0; j--) {
        swap(vect[l], vect[j + l]);
        heapify(vect, j, 0, l);
    }
}

void introSort(vector<int>& vect, int l, int r, int depth) {
    int size = (r - l) + 1;

    if(size <= 16) {
        insertionSort(vect, l, r);
        return;
    }

    if(depth <= 0) {
        heapSort(vect, l, r);
        return;
    }

    int pivot_index = l + rand() % (r - l + 1);
    int pivot = vect[pivot_index];

    int i = l;
    int lt = l;
    int gt = r;

    while(i <= gt) {
        if(vect[i] < pivot) {
            swap(vect[i], vect[lt]);
            lt++;
            i++;
        }
        else if(vect[i] > pivot) {
            swap(vect[i], vect[gt]);
            gt--;
        }
        else i++;
    }

    introSort(vect, l, lt - 1, depth - 1);
    introSort(vect, gt + 1, r, depth - 1);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if(r <= l) return nums;
        int depth = 2 * __lg(n);
        introSort(nums, l, r, depth);
        return nums;
    }
};