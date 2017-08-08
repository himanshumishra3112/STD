#include <iostream>
#include <stdio.h>
using namespace std;

class Queue {
	private:
		unsigned int _capacity;
		int _size;
		int _front;
		int _rear;
		int* _array;
	public:
		Queue(unsigned int iCapacity): _capacity(iCapacity), _size(0), _front(0), _rear(iCapacity - 1) {
			_array = new int[iCapacity];
		}
		~Queue() {
			delete [] _array;
		}
		void enqueue(int iElement) {
			if(isFull() == true) {
				return;
			}
			_rear = (_rear + 1)% _capacity;
			_array[_rear] = iElement;
			_size++;
		}
		int dequeue() {
			if(isEmpty() == true) {
				return 1;
			}
			int aElement = _array[_front];
			_front = (_front + 1)% _capacity;
			_size--;
			return aElement;
		}
		bool isFull() {
			return (_size == _capacity);
		}
		bool isEmpty() {
			return (_size == 0);
		}
		void printQueue() {
			for(int i = 0; i< _capacity; i++) {
				cout << _array[i] << "<--";
			}
			cout << endl;
		}
		int front() {
			return _array[_front];
		}
		int rear() {
			return _array[_rear];
		}
};

int main() {
	Queue* aQueue = new Queue(5);
	cout << "Enqueue: 10" << endl; aQueue->enqueue(10);
	cout << "Enqueue: 20" << endl; aQueue->enqueue(20);
	cout << "Enqueue: 30" << endl; aQueue->enqueue(30);
	cout << "Enqueue: 40" << endl; aQueue->enqueue(40);
	cout << "Enqueue: 50" << endl; aQueue->enqueue(50);
	cout << "Dequeued: " << aQueue->dequeue() << endl;
	cout << "Front: " << aQueue->front() << endl;
	cout << "Rear: " << aQueue->rear() << endl;
	cout << "Enqueue: 50" << endl; aQueue->enqueue(50);
	cout << "Front: " << aQueue->front() << endl;
	cout << "Rear: " << aQueue->rear() << endl;
	cout << "Dequeued: " << aQueue->dequeue() << endl;
	cout << "Enqueue: 50" << endl; aQueue->enqueue(50);
	cout << "Front: " << aQueue->front() << endl;
	cout << "Rear: " << aQueue->rear() << endl;
}
