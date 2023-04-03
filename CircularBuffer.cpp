template<typename T, int capacity> class CircularBuffer {
private:
	T buffer[capacity];
	int head;
	int tail;
	int size;
public:
	CircularBuffer() : head(0), tail(0), size(0) {}

	void push_back(T value) {
		if (size == capacity) {
			buffer[tail] = value;
			tail = (tail + 1) % capacity;
			head = (head + 1) % capacity;
		}
		else {
			buffer[tail] = value;
			tail = (tail + 1) % capacity;
			size++;
		}
	}

	T operator[](int index) {
		return buffer[(head + index) % capacity];
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << buffer[i] << ",";
		}
		cout << endl;
	}
};
