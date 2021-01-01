#include<vector>

class PriorityQueue {

vector<int> pq;

public :

    PriorityQueue() {
    }

    bool isEmpty(){
    return vector.empty();
    }

    int getSize() {
    return pq.size();
    }

    int getMin(){
    if(isEmpty()) return 0;

    return pq[0];
    }


    void insert(int element){
    pq.push_back(element);

    int childindex = pq.size() - 1;
    while(childindex > 0){
    int parentindex = (childindex -1)/2;

    if(pq[parentindex] > pq[childindex]){
        swap(pq[childindex],pq[parentindex]);
    }
    else{
        break;
    }
    childindex = parentindex;
    }
    }

    int deleteMin(){
        if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;



    }

};
