/**
CCP6124 Object-oriented Programming and Data Structures Trimester 2610
Virtual Machine and Assembly Language Interpreter

T11L Assignment Group I
LEE CHONG CHUN				252UC254YW		LEE.CHONG.CHUN1@student.mmu.edu.my
KONG WAI XIN				
MAKHLOUF MAYAS				252UC251RE		MAKHLOUF.MAYAS@student.mmu.edu.my
MOHAMMED A. T. SHAKSHAK		
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// self implemented STL container

template <typename T> class sVector;
template <typename T> class sStack;
template <typename T> class sQueue;

/**
 * @class sVector
 * @brief Self implementation of STL Vector compatible class
*/
template <typename T>
class sVector {
private:
	T* data;
	int size;
	int capacity;

	/**
	 * @brief Resizes the vector when capacity is reached
	 */
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
	/**
	 * @brief Default constructor for sVector
	 */
	sVector() : data(nullptr), size(0), capacity(0) {}

	/**
	 * @brief Constructor for sVector with initial capacity
	 * @param initialCapacity The initial capacity of the vector
	 */
	sVector(int initialCapacity) : data(nullptr), size(0), capacity(0) {
		if (initialCapacity > 0) {
			data = new T[initialCapacity];
			capacity = initialCapacity;
		}
	}

	/**
	 * @brief Destructor
	 */
	~sVector() {
		delete[] data;
	}

	/**
	 * @brief Adds an element to the end of the vector
	 * @param value The value to be added
	 */
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

	/**
	 * @brief Removes the last element from the vector
	 */
	void popBack() {
		if (size > 0) {
			size--;
		}
	}

	/**
	 * @brief Returns a reference to the element at the specified index
	 * @param index The index of the element to return
	 * @return Reference to the element at the specified index
	 */
	T& get(int index) {
		return data[index];
	}

	/**
	 * @brief Sets the value of the element at the specified index
	 * @param index The index of the element to set
	 * @param value The value to set
	 */
	void set(int index, const T& value) {
		data[index] = value;
	}

	/**
	 * @brief Returns the size of the vector
	 * @return The size of the vector
	 */
	int getSize() const {
		return size;
	}

	/**
	 * @brief Checks if the vector is empty
	 * @return True if the vector is empty, false otherwise
	 */
	bool isEmpty() const {
		return size == 0;
	}

	/**
	 * @brief Returns a reference to the element at the specified index
	 * @param index The index of the element to return
	 * @return Reference to the element at the specified index
	 */
	T& operator[](int index) {
		return data[index];
	}

	/**
	 * @brief Clears the vector
	 */
	void clear() {
		size = 0;
	}
};

/**
 * @class sStack
 * @brief Self implementation of STL Stack compatible class
 */
template <typename T>
class sStack {
private:
	T* data;
	int topIndex;
	int capacity;

public:
	/**
	 * @brief Default constructor for sStack
	 */
	sStack() : data(NULL), topIndex(-1), capacity(0) {}

	/**
	 * @brief Constructor for sStack with initial capacity
	 * @param initialCapacity The initial capacity of the stack
	 */
	sStack(int cap) : data(NULL), topIndex(-1), capacity(cap) {
		data = new T[capacity];
	}

	/**
	 * @brief Destructor
	 */
	~sStack() {
		delete[] data;
	}

	/**
	 * @brief Pushes a value onto the top of the stack
	 * @param value The value to push
	 */
	void push(const T& value) {
		if (topIndex >= capacity - 1) {
			return;
		}
		data[++topIndex] = value;
	}

	/**
	 * @brief Removes and returns the value at the top of the stack
	 * @return The value at the top of the stack
	 */
	T pop() {
		if (isEmpty()) {
			exit(1);
		}
		return data[topIndex--];
	}

	/**
	 * @brief Returns a reference to the value at the top of the stack
	 * @return Reference to the value at the top of the stack
	 */
	T& peek() {
		return data[topIndex];
	}

	/**
	 * @brief Checks if the stack is empty
	 * @return True if the stack is empty, false otherwise
	 */
	bool isEmpty() const {
		return topIndex == -1;
	}

	/**
	 * @brief Checks if the stack is full
	 * @return True if the stack is full, false otherwise
	 */
	bool isFull() const {
		return topIndex >= capacity - 1;
	}

	/**
	 * @brief Returns the number of elements in the stack
	 * @return The number of elements in the stack
	 */
	int getSize() const {
		return topIndex + 1;
	}
};

/**
 * @class sQueue
 * @brief Self implementation of STL Queue compatible class
 */
template <typename T>
class sQueue {
private:
	T* data;
	int frontIndex;
	int rearIndex;
	int count;
	int capacity;

public:
	/**
	 * @brief Default constructor for sQueue
	 */
	sQueue() : data(NULL), frontIndex(0), rearIndex(0), count(0), capacity(0) {}

	/**
	 * @brief Constructor for sQueue with initial capacity
	 * @param initialCapacity The initial capacity of the queue
	 */
	sQueue(int cap) : data(NULL), frontIndex(0), rearIndex(0), count(0), capacity(cap) {
		data = new T[capacity];
	}

	/**
	 * @brief Destructor
	 */
	~sQueue() {
		delete[] data;
	}

	/**
	 * @brief Adds an element to the rear of the queue
	 * @param value The value to add
	 */
	void ensQueue(const T& value) {
		if (count >= capacity) {
			return;
		}
		data[rearIndex] = value;
		rearIndex = (rearIndex + 1) % capacity;
		count++;
	}

	/**
	 * @brief Removes and returns the value at the front of the queue
	 * @return The value at the front of the queue
	 */
	T desQueue() {
		if (isEmpty()) {
			exit(1);
		}
		T value = data[frontIndex];
		frontIndex = (frontIndex + 1) % capacity;
		count--;
		return value;
	}

	/**
	 * @brief Returns a reference to the value at the front of the queue
	 * @return Reference to the value at the front of the queue
	 */
	T& peek() {
		return data[frontIndex];
	}

	/**
	 * @brief Checks if the queue is empty
	 * @return True if the queue is empty, false otherwise
	 */
	bool isEmpty() const {
		return count == 0;
	}

	/**
	 * @brief Checks if the queue is full
	 * @return True if the queue is full, false otherwise
	 */
	bool isFull() const {
		return count >= capacity;
	}

	/**
	 * @brief Returns the number of elements in the queue
	 * @return The number of elements in the queue
	 */
	int getSize() const {
		return count;
	}
};

/**
 * @class Memory
 * @brief Implements the memory of the assembler
 */
class Memory {
private:
	static const int MEMORY_SIZE = 64;
    signed char cells[MEMORY_SIZE];

public:
    /**
	 * @brief Constructor for Memory
	 */
    Memory() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            cells[i] = 0;
        }
    }

    /**
	 * @brief Writes a value to the specified address in memory
	 * @param address The address to write to
	 * @param val The value to write
	 */
    void write(int address, signed char val) {
        if (address >= 0 && address < MEMORY_SIZE) {
            cells[address] = val;
        }
    }

    /**
	 * @brief Reads a value from the specified address in memory
	 * @param address The address to read from
	 * @return The value at the specified address
	 */
    signed char read(int address) const {
        if (address >= 0 && address < MEMORY_SIZE) {
            return cells[address];
        }
        return 0;
    }

    /**
	 * @brief Resets the memory to all zeros
	 */
    void reset() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            cells[i] = 0;
        }
    }
};

/**
 * @brief Abstract Base Class for all instructions
 */
class Instruction {
public:
	/**
	 * @brief Virtual function to be overridden by derived classes
	 */
	virtual void execute() = 0; 
	
	/**
	 * @brief Virtual destructor
	 */
	virtual ~Instruction() {} 
};

/**
 * @class ArithmeticInstruction
 * @brief arithmetic operations for ADD, SUB, MUL, DIV, INC, DEC instructions
 */
class ArithmeticInstruction : public Instruction {
private:
	string opcode;
	string destRegister;
	string sourceRegister;

public:
	/**
	 * @brief Constructor for ArithmeticInstruction
	 * @param op The opcode of the instruction
	 * @param dest The destination register
	 * @param source The source register
	 */
	ArithmeticInstruction(string op, string dest, string source = "") {
		opcode = op;
		destRegister = dest;
		sourceRegister = source;
	}

	/**
	 * @brief Executes the arithmetic instruction
	 */
	void execute() override {
		// // TODO: Person 2 - Replace these mock values with actual Register objects
		signed char destValue = 100;  
		signed char sourceValue = 100; 
		
		// Temporary mock flags
		bool flag_OF = false;		// overflow
		bool flag_UF = false;		// underflow
		bool flag_ZF = false;		// zero
		bool flag_CF = false;		// carry

		int result = 0;

		// --- Math Logic ---
		if (opcode == "ADD") {
			result = (int)destValue + (int)sourceValue;
		} 
		else if (opcode == "SUB") {
			result = (int)destValue - (int)sourceValue;
		} 
		else if (opcode == "MUL") {
			result = (int)destValue * (int)sourceValue;
		} 
		else if (opcode == "DIV") {
			if (sourceValue == 0) {
				cout << "Error: Division by zero!" << endl;
				return; // Stop execution to prevent crash
			}
			result = (int)destValue / (int)sourceValue;
		} 
		else if (opcode == "INC") {
			result = (int)destValue + 1; 	// INC only uses destination
		} 
		else if (opcode == "DEC") {
			result = (int)destValue - 1;	// DEC only uses destination
		}

		// --- Flags Update ---
		if (result > 127) {
			flag_OF = true;
			flag_CF = true;		// Exceeds 8-bit capacity
		} 
		else if (result < -128) {
			flag_UF = true;
			flag_CF = true;		// Exceeds 8-bit capacity
		}

		// Truncate to 8-bit
		destValue = (signed char)result;

		if (destValue == 0) {
			flag_ZF = true;
		}

		// --- Print Output ---
		cout << "Executing: " << opcode << " " << destRegister;
		if (sourceRegister != "") cout << ", " << sourceRegister;
		cout << endl;
		
		cout << "--- Math Result ---" << endl;
		cout << "Result Value: " << (int)destValue << endl;
		cout << "Flags -> OF: " << flag_OF << " | UF: " << flag_UF << " | ZF: " << flag_ZF << " | CF: " << flag_CF << endl;
		cout << "-------------------\n" << endl;
	}
};

/**
 * @class IOInstruction
 * @brief I/O instructions for INPUT, DISPLAY instructions
 */
class IOInstruction : public Instruction {
private:
	string opcode;
	string targetRegister;

public:
	/**
	 * @brief Constructor for IOInstruction
	 * @param op The opcode of the instruction
	 * @param target The target register
	 */
	IOInstruction(string op, string target) {
		opcode = op;
		targetRegister = target;
	}

	/**
	 * @brief Executes the I/O instruction
	 */
	void execute() override {
		// // TODO: Person 2 - Replace these mock values with actual Register objects
		signed char destValue = 42; // Dummy value for testing the DISPLAY instruction
		bool flag_OF = false;
		bool flag_UF = false;
		bool flag_ZF = false;

		if (opcode == "INPUT") {
			cout << "?";
			int userInput;
			cin >> userInput; // Wait for user input

			// Check the LEDs based on the input
			if (userInput > 127) {
				flag_OF = true;
			} 
			else if (userInput < -128) {
				flag_UF = true;
			}

			// Push the value and save it on the sStack
			destValue = (signed char)userInput;

			if (destValue == 0) {
				flag_ZF = true;
			}

			// Dummy print to verify that the flags are working
			cout << "[System] INPUT stored in " << targetRegister << " -> " << (int)destValue << endl;
			cout << "Flags -> OF: " << flag_OF << " | UF: " << flag_UF << " | ZF: " << flag_ZF << endl;
		} 
		else if (opcode == "DISPLAY") {
			// Print the sStack value directly to the screen
			cout << (int)destValue << endl;
		}
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
	sVector<Operation> program;

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
			arg2 = "" ;
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
