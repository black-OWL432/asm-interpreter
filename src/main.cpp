/**
CCP6124 Object-oriented Programming and Data Structures Trimester 2610
Virtual Machine and Assembly Language Interpreter

T11L Assignment Group I
LEE CHONG CHUN				252UC254YW		LEE.CHONG.CHUN1@student.mmu.edu.my
KONG WAI XIN				242UC244LP		KONG.WAI.XIN@student.mmu.edu.my
MAKHLOUF MAYAS				252UC251RE		MAKHLOUF.MAYAS@student.mmu.edu.my
MOHAMMED A. T. SHAKSHAK		
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ------------------------- self implemented STL container -------------------------

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

	/**
	 * @brief Clears all elements from the stack
	 */
	void clear() {
		topIndex = -1;
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

// ------------------------- assembler data structures -------------------------

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
	bool write(int address, signed char val) {
		if (address >= 0 && address < MEMORY_SIZE) {
			cells[address] = val;
			return true;
		}
		return false;
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

	/**
	 * @brief Returns the size of the memory
	 * @return The number of memory cells
	 */
	int getSize() const {
		return MEMORY_SIZE;
	}
};

// ------------------------- register classes -------------------------

/**
 * @class Register
 * @brief Abstract base class for all registers
 */
class Register {
protected:
	signed char value;

public:
	/**
	 * @brief Constructor for Register
	 * @param val The initial value of the register
	 */
	Register(signed char val = 0) : value(val) {}

	/**
	 * @brief Destructor
	 */
	virtual ~Register() {}

	/**
	 * @brief Gets the value of the register
	 * @return The value of the register
	 */
	signed char getValue() const { return value; }

	/**
	 * @brief Sets the value of the register
	 * @param val The value to set
	 */
	void setValue(signed char val) { value = val; }

	/**
	 * @brief Resets the register to zero
	 */
	virtual void reset() { value = 0; }
};

/**
 * @class GeneralRegister
 * @brief Represents one of the 8 VM data registers R0-R7.
 * @author KONG WAI XIN
 */
class GeneralRegister : public Register {
private:
	string name;

public:
	/**
	 * @brief Constructor for GeneralRegister
	 * @param regName The register name, such as R0, R1, R2
	 */
	GeneralRegister(string regName = "") : Register(0) {
		name = regName;
	}

	/**
	 * @brief Gets the register name
	 * @return The name of the register
	 */
	string getName() const {
		return name;
	}

	/**
	 * @brief Sets the register name
	 * @param regName The new register name
	 */
	void setName(string regName) {
		name = regName;
	}
};

/**
 * @class FlagRegister
 * @brief Implements the flag register of the assembler
 */
class FlagRegister : public Register {
private:
	bool Overflow;
	bool Underflow;
	bool Zero;
	bool Carry;

public:
	/**
	 * @brief Constructor for FlagRegister
	 */
	FlagRegister() : Register() {
		Overflow = false;
		Underflow = false;
		Zero = false;
		Carry = false;
	}

	/**
	 * @brief Destructor
	 */
	virtual ~FlagRegister() {}

	/**
	 * @brief Sets the overflow flag
	 * @param val The value to set
	 */
	void setOverflow(bool val) { Overflow = val; }

	/**
	 * @brief Sets the underflow flag
	 * @param val The value to set
	 */
	void setUnderflow(bool val) { Underflow = val; }

	/**
	 * @brief Sets the zero flag
	 * @param val The value to set
	 */
	void setZero(bool val) { Zero = val; }

	/**
	 * @brief Sets the carry flag
	 * @param val The value to set
	 */
	void setCarry(bool val) { Carry = val; }

	/**
	 * @brief Gets the overflow flag
	 * @return The overflow flag
	 */
	bool getOverflow() const { return Overflow; }

	/**
	 * @brief Gets the underflow flag
	 * @return The underflow flag
	 */
	bool getUnderflow() const { return Underflow; }

	/**
	 * @brief Gets the zero flag
	 * @return The zero flag
	 */
	bool getZero() const { return Zero; }

	/**
	 * @brief Gets the carry flag
	 * @return The carry flag
	 */
	bool getCarry() const { return Carry; }

	/**
	 * @brief Resets the flags to false
	 */
	void reset() {
		Overflow = false;
		Underflow = false;
		Zero = false;
		Carry = false;
	}

	/**
	 * @brief Resets a specific flag only
	 * @param flagName The name of the flag to reset
	 */
	bool reset(string flagName) {
		if (flagName == "OVERFLOW" || flagName == "OF") {
			Overflow = false;
		} else if (flagName == "UNDERFLOW" || flagName == "UF") {
			Underflow = false;
		} else if (flagName == "ZERO" || flagName == "ZF") {
			Zero = false;
		} else if (flagName == "CARRY" || flagName == "CF") {
			Carry = false;
		} else {
			return false;
		}

		return true;
	}

	/**
	 * @brief Updates the flags based on the result of an operation
	 * @param result The result of the operation
	 */
	void updateFlag(int result) {
		Overflow = (result > 127);
		Underflow = (result < -128);
		Zero = (result == 0);
	}

	/**
	 * @brief Updates the flags based on the result of an operation
	 * @param op The operator of the operation +, -, *, /
	 * @param a The first operand
	 * @param b The second operand, use 1 for INC or DEC
	 * @param result The result of the operation
	 */
	void updateFlag(char op, int a, int b, int result) {
		updateFlag(result);
		if (op == '+' || op == '-' || op == '*' || op == '/') {
			Carry = (result > 255 || result < 0);
		}
	}
};

/**
 * @class ProgramCounter
 * @brief Implements the program counter of the assembler
 */
class ProgramCounter : public Register {
public:
	/**
	 * @brief Constructor for ProgramCounter
	 */
	ProgramCounter() : Register() {}

	/**
	 * @brief Increments the program counter
	 */
	void increment() { value++; }

	/**
	 * @brief Jumps to a specific address
	 * @param addr The address to jump to
	 */
	void jump(signed char addr) { value = addr; }
};

/**
 * @class StackPointer
 * @brief Implements the stack pointer of the assembler
 */
class StackPointer : public Register {
public:
	/**
	 * @brief Constructor for StackPointer
	 */
	StackPointer() : Register() {}

	/**
	 * @brief Increments the stack pointer
	 */
	void increment() { value++; }

	/**
	 * @brief Decrements the stack pointer
	 */
	void decrement() { value--; }
};

/**
 * @class CPU
 * @brief Owns the VM registers, flags, memory, PC, SI, and system stack
 * @author KONG WAI XIN
 */
class CPU {
private:
	GeneralRegister registers[8];
	FlagRegister flags;
	Memory memory;
	ProgramCounter pc;
	StackPointer si;
	sStack<signed char> systemStack;

	/**
	 * @brief Converts a decimal string to an integer
	 */
	int stringToInt(string text) const {
		int sign = 1;
		int index = 0;
		int number = 0;
		if (!text.empty() && text[0] == '-') {
			sign = -1;
			index = 1;
		}
		for (int i = index; i < (int)text.length(); i++) {
			number = number * 10 + (text[i] - '0');
		}
		return number * sign;
	}

	/**
	 * @brief Checks whether a string contains a valid integer
	 */
	bool isNumber(string text) const {
		if (text.empty()) return false;
		int start = 0;
		if (text[0] == '-') start = 1;
		if (start == (int)text.length()) return false;
		for (int i = start; i < (int)text.length(); i++) {
			if (text[i] < '0' || text[i] > '9') return false;
		}
		return true;
	}

	/**
	 * @brief Removes surrounding square brackets
	 */
	string removeBrackets(string text) const {
		if (text.length() >= 2 && text[0] == '['
			&& text[text.length() - 1] == ']') {
			return text.substr(1, text.length() - 2);
		}
		return text;
	}

	/**
	 * @brief Formats a value as four characters for the VM dump
	 */
	string format4(int value) const {
		bool negative = value < 0;
		if (negative) value = -value;
		string digits = "";
		if (value == 0) digits = "0";
		while (value > 0) {
			digits = (char)('0' + value % 10) + digits;
			value /= 10;
		}
		while ((int)digits.length() < 4) digits = "0" + digits;
		if (negative) digits = "-" + digits.substr(1);
		return digits;
	}

public:
	/**
	 * @brief Constructs and initializes the VM hardware
	 */
	CPU() : systemStack(8) {
		string names[8] = {"R0", "R1", "R2", "R3",
			"R4", "R5", "R6", "R7"};
		for (int i = 0; i < 8; i++) registers[i].setName(names[i]);
		reset();
	}

	/**
	 * @brief Resets all VM hardware
	 */
	void reset() {
		for (int i = 0; i < 8; i++) registers[i].reset();
		flags.reset();
		memory.reset();
		pc.reset();
		si.reset();
		systemStack.clear();
	}

	/**
	 * @brief Checks whether a token names R0 through R7
	 */
	bool isRegisterName(string name) const {
		return name.length() == 2 && name[0] == 'R'
			&& name[1] >= '0' && name[1] <= '7';
	}

	/**
	 * @brief Gets the array index for a register name
	 */
	int getRegisterIndex(string name) const {
		if (!isRegisterName(name)) return -1;
		return name[1] - '0';
	}

	/**
	 * @brief Gets a data register value
	 */
	signed char getRegisterValue(string name) const {
		int index = getRegisterIndex(name);
		if (index == -1) {
			cout << "Error: invalid register " << name << endl;
			exit(1);
		}
		return registers[index].getValue();
	}

	/**
	 * @brief Sets a data register and updates flags
	 */
	void setRegisterValue(string name, int value) {
		int index = getRegisterIndex(name);
		if (index == -1) {
			cout << "Error: invalid register " << name << endl;
			exit(1);
		}
		flags.updateFlag(value);
		flags.setCarry(value > 127 || value < -128);
		registers[index].setValue((signed char)value);
	}

	/**
	 * @brief Resolves direct or register-indirect memory addressing
	 */
	int getAddress(string token) const {
		string clean = removeBrackets(token);
		int address = 0;
		if (isRegisterName(clean)) {
			address = (int)getRegisterValue(clean);
		} else if (isNumber(clean)) {
			address = stringToInt(clean);
		} else {
			cout << "Error: invalid address " << token << endl;
			exit(1);
		}
		if (address < 0 || address >= memory.getSize()) {
			cout << "Error: memory address out of range" << endl;
			exit(1);
		}
		return address;
	}

	/**
	 * @brief Resolves a register, immediate value, or memory operand
	 */
	int getOperandValue(string token) const {
		if (isRegisterName(token)) return (int)getRegisterValue(token);
		if (token.length() >= 2 && token[0] == '[') {
			return (int)memory.read(getAddress(token));
		}
		if (isNumber(token)) return stringToInt(token);
		cout << "Error: invalid operand " << token << endl;
		exit(1);
	}

	/**
	 * @brief Writes a value to VM memory
	 */
	void writeMemory(int address, int value) {
		if (!memory.write(address, (signed char)value)) {
			cout << "Error: memory address out of range" << endl;
			exit(1);
		}
	}

	/**
	 * @brief Reads a value from VM memory
	 */
	signed char readMemory(int address) const {
		return memory.read(address);
	}

	/**
	 * @brief Increments the program counter
	 */
	void incrementPC() {
		pc.increment();
	}

	/**
	 * @brief Resets one named flag
	 */
	void resetFlag(string flagName) {
		if (!flags.reset(flagName)) {
			cout << "Error: invalid flag " << flagName << endl;
			exit(1);
		}
	}

	/**
	 * @brief Pushes a register value onto the system stack
	 */
	void pushRegister(string registerName) {
		if (systemStack.isFull()) {
			cout << "Error: stack overflow" << endl;
			exit(1);
		}
		systemStack.push(getRegisterValue(registerName));
		si.increment();
	}

	/**
	 * @brief Pops the system stack into a register
	 */
	void popToRegister(string registerName) {
		if (systemStack.isEmpty()) {
			cout << "Error: stack underflow" << endl;
			exit(1);
		}
		signed char value = systemStack.pop();
		si.decrement();
		setRegisterValue(registerName, (int)value);
	}

	/**
	 * @brief Prints the final VM state in assignment format
	 */
	void dump() const {
		cout << "#Begin#" << endl << "#Registers#";
		for (int i = 0; i < 8; i++) {
			cout << format4((int)registers[i].getValue()) << "#";
		}
		cout << endl << "#Flags#OF#" << flags.getOverflow()
			<< "#UF#" << flags.getUnderflow() << "#CF#"
			<< flags.getCarry() << "#ZF#" << flags.getZero() << "#" << endl;
		cout << "#PC#" << format4((int)pc.getValue()) << "#" << endl;
		cout << "#Memory#" << endl;
		for (int i = 0; i < memory.getSize(); i++) {
			cout << "#" << format4((int)memory.read(i));
			if ((i + 1) % 8 == 0) cout << "#" << endl;
		}
		cout << "#End#" << endl;
	}
};

// ------------------------- instruction classes -------------------------

/**
 * @class Instruction
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
		} else if (opcode == "SUB") {
			result = (int)destValue - (int)sourceValue;
		} else if (opcode == "MUL") {
			result = (int)destValue * (int)sourceValue;
		} else if (opcode == "DIV") {
			if (sourceValue == 0) {
				cout << "Error: Division by zero!" << endl;
				return; // Stop execution to prevent crash
			}
			result = (int)destValue / (int)sourceValue;
		} else if (opcode == "INC") {
			result = (int)destValue + 1; 	// INC only uses destination
		} else if (opcode == "DEC") {
			result = (int)destValue - 1;	// DEC only uses destination
		}

		// Flags Update
		if (result > 127) {
			flag_OF = true;
			flag_CF = true;		// Exceeds 8-bit capacity
		} else if (result < -128) {
			flag_UF = true;
			flag_CF = true;		// Exceeds 8-bit capacity
		}

		// Truncate to 8-bit
		destValue = (signed char)result;

		if (destValue == 0) {
			flag_ZF = true;
		}

		// Print Output
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
			} else if (userInput < -128) {
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
		} else if (opcode == "DISPLAY") {
			// Print the sStack value directly to the screen
			cout << (int)destValue << endl;
		}
	}
};

/**
 * @class Operation
 * @brief Abstract base class for all operations
 */
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

/**
 * @brief Trims whitespace from a string
 * @param str The string to trim
 * @return The trimmed string
 */
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
