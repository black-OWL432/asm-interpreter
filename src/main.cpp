/**
CCP6124 Object-oriented Programming and Data Structures Trimester 2610
Virtual Machine and Assembly Language Interpreter

T11L Assignment Group I
LEE CHONG CHUN				252UC254YW		LEE.CHONG.CHUN1@student.mmu.edu.my
KONG WAI XIN				
MAKHLOUF, MAYAS				
MOHAMMED A. T. SHAKSHAK		
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// self implemented STL container

template <typename T> class Vector;
template <typename T> class Stack;
template <typename T> class Queue;

template <typename T>
class Vector {
private:
	T* data;
	int size;
	int capacity;

	void resize() {
		int newCapacity = capacity * 2;
		T* newData = new T[newCapacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

public:
	Vector() : data(nullptr), size(0), capacity(0) {}

	Vector(int initialCapacity) : data(nullptr), size(0), capacity(0) {
		if (initialCapacity > 0) {
			data = new T[initialCapacity];
			capacity = initialCapacity;
		}
	}

	~Vector() {
		delete[] data;
	}

	void pushBack(const T& value) {
		if (size >= capacity) {
			if (capacity == 0) {
				capacity = 2;
				data = new T[capacity];
			} else {
				resize();
			}
		}
		data[size++] = value;
	}

	void popBack() {
		if (size > 0) {
			size--;
		}
	}

	T& get(int index) {
		return data[index];
	}

	void set(int index, const T& value) {
		data[index] = value;
	}

	int getSize() const {
		return size;
	}

	bool isEmpty() const {
		return size == 0;
	}

	T& operator[](int index) {
		return data[index];
	}

	void clear() {
		size = 0;
	}
};

template <typename T>
class Stack {
private:
	T* data;
	int topIndex;
	int capacity;

public:
	Stack() : data(NULL), topIndex(-1), capacity(0) {}

	Stack(int cap) : data(NULL), topIndex(-1), capacity(cap) {
		data = new T[capacity];
	}

	~Stack() {
		delete[] data;
	}

	void push(const T& value) {
		// todo
	}

	T pop() {
		// todo
	}

	T& peek() {
		// todo
	}

	bool isEmpty() const {
		// todo
	}

	bool isFull() const {
		// todo
	}

	int getSize() const {
		// todo
	}
};

template <typename T>
class Queue {
private:
	T* data;
	int frontIndex;
	int rearIndex;
	int count;
	int capacity;

public:
	Queue() : data(NULL), frontIndex(0), rearIndex(0), count(0), capacity(0) {}

	Queue(int cap) : data(NULL), frontIndex(0), rearIndex(0), count(0), capacity(cap) {
		data = new T[capacity];
	}

	~Queue() {
		delete[] data;
	}

	void enqueue(const T& value) {
		// todo
	}

	T dequeue() {
		// todo
	}

	T& peek() {
		// todo
	}

	bool isEmpty() const {
		// todo
	}

	bool isFull() const {
		// todo
	}

	int getSize() const {
		// todo
	}
};

// Operation class
class Operation {
protected:
	string opcode;
	string arg1;
	string arg2;

public:
	Operation() {}

	Operation(string opcode, string arg1, string arg2) {
		this->opcode = opcode;
		this->arg1 = arg1;
		this->arg2 = arg2;
	}

	virtual ~Operation() {}
};

std::string trim(const std::string& str) {
    //           MOV
	// ^0........^first
    int first = str.find_first_not_of(" \t\r\n");
    if (first == -1) return ""; // string contains only whitespace

    // MOV         
	//   ^last....^end
    int last = str.find_last_not_of(" \t\r\n");

	//      MOV      -> now become only MOV
	// first^ ^last
    return str.substr(first, last - first + 1);
}

// Entry point
int main(int argc, char* argv[]) {
	string fileName;
	Vector<Operation> program;

	if (argc < 2) {
		cout << "Enter filename: ";
		cin >> fileName;
	} else {
		fileName = argv[1];
	}

	ifstream fd(fileName);
	if (!fd.is_open()) {
		cout << "Error: Could not open file " << fileName << endl;
		return 1;
	}

	string line;
	while (getline(fd, line)) {
		// Remove comment if exists
		int commentIdx = line.find(';');
		if (commentIdx != -1) {
			// MOV R1, 5 ; this is a comment
			// ^0........^commentIdx
			line = line.substr(0, commentIdx);
		}

		line = trim(line);
		if (line.empty()) continue;

		// Find opcode/arg separator
		int space = line.find_first_of(" \t");
		if (space == -1) {
			// condition for no arg found
			program.pushBack(Operation(line, "", ""));
			continue;
		}

		// condition MOV R1, 5
		// opcode = "MOV"
		// args = "R1, 5"
		string opcode = trim(line.substr(0, space));
		string args = trim(line.substr(space + 1));

		int comma = args.find(',');
		string arg1, arg2;
		if (comma == -1) {
			// condition PUSH R0
			// arg1 = "R0"
			arg1 = args;
			arg2 = "";
		} else {
			// condition MOV R1, 5
			// arg1 = "R1"
			// arg2 = "5"
			arg1 = trim(args.substr(0, comma));
			arg2 = trim(args.substr(comma + 1));
		}

		program.pushBack(Operation(opcode, arg1, arg2));
	}

	fd.close();

	// todo

	return 0;
}
