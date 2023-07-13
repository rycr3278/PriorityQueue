#include "PriorityQueue.h"


PriorityQueue::PriorityQueue() {
    // Constructor code here if needed
}

PriorityQueue::~PriorityQueue() {
    // Destructor code here if needed
}

shared_ptr<vector<pq>> PriorityQueue::InitPriorityQueue() {
    return make_shared<vector<pq>>();
}

void PriorityQueue::Insert(shared_ptr<vector<pq>> queue, string text, float priority) {
    if (!queue){
        return;
    }
    pq element;
    element.text = text;
    element.priority = priority;

    // Insert the element at the end of the queue
    queue->push_back(element);
    heapifyUp(queue, queue->size() - 1);
    
}

string PriorityQueue::Remove(shared_ptr<vector<pq>> queue) {
    if (queue->empty()) {
        return "";
    }

   
    string result = queue->at(0).text;
    queue->at(0) = queue->back();
    queue->pop_back();
    heapifyDown(queue, 0);

    return result;
}

string PriorityQueue::Peek(shared_ptr<vector<pq>> queue) {
    if (queue->empty()) {
        return "";
    }

    return queue->at(0).text;
}

void PriorityQueue::heapifyUp(shared_ptr<vector<pq>> queue, int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && queue->at(parentIndex).priority > queue->at(index).priority) {
        swap(queue->at(parentIndex), queue->at(index));
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void PriorityQueue::heapifyDown(shared_ptr<vector<pq>> queue, int index) {
    int size = queue->size();
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;

    if (leftChildIndex < size && queue->at(leftChildIndex).priority < queue->at(smallestIndex).priority) {
        smallestIndex = leftChildIndex;
    }

    if (rightChildIndex < size && queue->at(rightChildIndex).priority < queue->at(smallestIndex).priority) {
        smallestIndex = rightChildIndex;
    }

    if (smallestIndex != index) {
        swap(queue->at(index), queue->at(smallestIndex));
        heapifyDown(queue, smallestIndex);
    }
}