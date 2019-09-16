//
// Created by Vergilken on 9/7/19.
//

#ifndef ALGORITHMS_BINARYHEAP_H
#define ALGORITHMS_BINARYHEAP_H

/*
 * A binary heap is a complete binary tree. A binary heap is typically represented as an array.
 * A binary heap is either Min Heap or Max Heap.
 * The root element will be at arr[0]
 * When reaching arr[(i-1)/2], returns the parent node.
 * When reaching arr[(2*i)+1], returns the left child node.
 * When reaching arr[(2*i)+2], returns the right child node.
 */
class BinaryHeap{
public:
    explicit BinaryHeap(size_t _capacity): capacity_(_capacity), heap_size_(0) {
        heap_arr.resize(capacity_);
    }

    void insert_key(int key) {
        if (heap_size_ == capacity_) {
            heap_arr.resize(capacity_ * 2);
        }

        ++heap_size_;
        auto i = heap_size_ - 1;
        heap_arr[i] = key;
        while (i != 0 && heap_arr[parent(i)] > heap_arr[i]) {
           swap(heap_arr[i], heap_arr[parent(i)]);
           i = parent(i);
        }
    }

    void decrease_key(int key, int newValue) {
        if (newValue < heap_arr[key]) {
            heap_arr[key] = newValue;
            while (key != 0 && heap_arr[parent(key)] > heap_arr[key]) {
                swap(heap_arr[key], heap_arr[parent(key)]);
                key = parent(key);
            }
        } else {
            heap_arr[key] = newValue;
            min_heapify(key);
        }
    }

    void delete_key(int key) {
        decrease_key(key, INT_MIN);
        extract_min();
    }

    int extract_min() {
        if (heap_size_ < 1) {
            cerr << "EMPTY HEAP" << endl;
            return INT_MAX;
        } else if (heap_size_ == 1) {
            --heap_size_;
            return heap_arr[0];
        } else {
            int minValue = heap_arr[0];
            heap_arr[0] = heap_arr[heap_size_-1];
            --heap_size_;
            min_heapify(0);
            return minValue;
        }
    }

    void min_heapify(int key) {
        auto l = left_child(key);
        auto r = right_child(key);
        auto smallest = key;
        if (l < heap_size_ && heap_arr[l] < heap_arr[key]) {
            smallest = l;
        }
        if (r < heap_size_ && heap_arr[r] < heap_arr[key]) {
            smallest = r;
        }
        if (smallest != key) {
            swap(heap_arr[key], heap_arr[smallest]);
            min_heapify(smallest);
        }
    }

private:
    size_t capacity_;
    size_t heap_size_;
    vector<int> heap_arr;
    inline static size_t parent(size_t i) {
        return (i-1) / 2;
    }

    inline static size_t left_child(size_t i) {
        return 2 * i + 1;
    }

    inline static size_t right_child(size_t i) {
        return 2 * i + 2;
    }
};
#endif //ALGORITHMS_BINARYHEAP_H
