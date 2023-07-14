#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    // No need to add anything here
}

PriorityQueue::~PriorityQueue() {
    // No need to add anything here
}

shared_ptr<pq> PriorityQueue::InitPriorityQueue() {
    return  shared_ptr<pq>(new pq); // Allocate memory for a pq structure using smart pointers
}

void PriorityQueue::Insert(shared_ptr<pq> queue, string text, float priority) {
    pq newElement;
    newElement.text = text;
    newElement.priority = priority;
    array.push_back(newElement); // Insert the new element at the end of the vector

    // Perform heapify-up to maintain the heap property
    int currentIndex = array.size() - 1;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (array[currentIndex].priority <= array[parentIndex].priority)
            break;
        swap(array[currentIndex], array[parentIndex]);
        currentIndex = parentIndex;
    }
}

string PriorityQueue::Remove(shared_ptr<pq> queue) {
    if (array.empty())
        return "";

    // Remove the highest priority element from the root of the heap
    string removedText = array[0].text;
    array[0] = array.back();
    array.pop_back();

    // Perform heapify-down to maintain the heap property
    int currentIndex = 0;
    int size = array.size();
    while (true) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int largestIndex = currentIndex;

        if (leftChildIndex < size && array[leftChildIndex].priority > array[largestIndex].priority)
            largestIndex = leftChildIndex;

        if (rightChildIndex < size && array[rightChildIndex].priority > array[largestIndex].priority)
            largestIndex = rightChildIndex;

        if (largestIndex == currentIndex)
            break;

        swap(array[currentIndex], array[largestIndex]);
        currentIndex = largestIndex;
    }

    return removedText;
}

string PriorityQueue::Peek(shared_ptr<pq> queue) {
    if (array.empty())
        return "";
    return array[0].text; // Return the text of the highest priority element (root of the heap)
}
