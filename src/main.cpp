/**
CCP6124 Object-oriented Programming and Data Structures Trimester 2610
Virtual Machine and Assembly Language Interpreter

T11L Assignment Group I
LEE CHONG CHUN				252UC254YW		LEE.CHONG.CHUN1@student.mmu.edu.my
KONG WAI XIN				
MAKHLOUF MAYAS				252UC251RE      MAKHLOUF.MAYAS@student.mmu.edu.my
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




// ==========================================
// MAKHLOUF MAYAS 	252UC251RE
// ==========================================

// 1. Abstract Base Class for all instructions
class Instruction {
public:
    // Virtual function to be overridden by derived classes
    virtual void execute() = 0; 
    
    // Virtual destructor is important in C++ for base classes
    virtual ~Instruction() {} 
};

// 2. Arithmetic Instructions (ADD, SUB, MUL, DIV, INC, DEC)
class ArithmeticInstruction : public Instruction {
private:
    string opcode;
    string destRegister;
    string sourceRegister;

public:
    // Constructor
    ArithmeticInstruction(string op, string dest, string source = "") {
        opcode = op;
        destRegister = dest;
        sourceRegister = source;
    }

    // Overriding the execute function
    void execute() override {
        // // TODO: Person 2 - Replace these mock values with actual Register objects
        signed char destValue = 100;  
        signed char sourceValue = 100; 
        
        // Temporary mock flags
        bool flag_OF = false;
        bool flag_UF = false;
        bool flag_ZF = false;
        bool flag_CF = false;

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
            result = (int)destValue + 1; // INC only uses destination
        } 
        else if (opcode == "DEC") {
            result = (int)destValue - 1; // DEC only uses destination
        }

        // --- Flags Update ---
        if (result > 127) {
            flag_OF = true;
            flag_CF = true; // Exceeds 8-bit capacity
        } 
        else if (result < -128) {
            flag_UF = true;
            flag_CF = true; // Exceeds 8-bit capacity
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

// 3. IO Instructions (INPUT, DISPLAY)
class IOInstruction : public Instruction {
private:
    string opcode;
    string targetRegister;

public:
    // Constructor
    IOInstruction(string op, string target) {
        opcode = op;
        targetRegister = target;
    }

    // Overriding the execute function
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

            // Push the value and save it on the stack
            destValue = (signed char)userInput;

            if (destValue == 0) {
                flag_ZF = true;
            }

            // Dummy print to verify that the flags are working
            cout << "[System] INPUT stored in " << targetRegister << " -> " << (int)destValue << endl;
            cout << "Flags -> OF: " << flag_OF << " | UF: " << flag_UF << " | ZF: " << flag_ZF << endl;
        } 
        else if (opcode == "DISPLAY") {
            // Print the stack value directly to the screen
            cout << (int)destValue << endl;
        }
    }
};

//================================

//================================

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



