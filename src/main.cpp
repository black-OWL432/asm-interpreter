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
	 * @brief Gets current program counter value
	 */
	int getPC() const {
		return (int)pc.getValue();
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
	 * @brief Prints the final VM state in assignment format to any output stream
	 */
	void dump(ostream& out) const {
		out << "#Begin#" << endl;
		out << "#Registers#";

		for (int i = 0; i < 8; i++) {
			out << format4((int)registers[i].getValue()) << "#";
		}

		out << endl;
		out << "#Flags#OF#" << flags.getOverflow()
			<< "#UF#" << flags.getUnderflow()
			<< "#CF#" << flags.getCarry()
			<< "#ZF#" << flags.getZero() << "#" << endl;

		out << "#PC#" << format4((int)pc.getValue()) << "#" << endl;
		out << "#Memory#" << endl;

		for (int i = 0; i < memory.getSize(); i++) {
			out << "#" << format4((int)memory.read(i));

			if ((i + 1) % 8 == 0) {
				out << "#" << endl;
			}
		}

		out << "#End#" << endl;
	}

	/**
	 * @brief Prints the final VM state to screen
	 */
	void dump() const {
		dump(cout);
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
	 * @param cpu Reference to the CPU to execute the instruction on
	 */
	virtual void execute(CPU& cpu) = 0;

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
	ArithmeticInstruction(string op, string dest, string source = "") {
		opcode = op;
		destRegister = dest;
		sourceRegister = source;
	}

	void execute(CPU& cpu) override {
		// 1. Retrieve the actual value from the target stack via the CPU
		int destValue = (int)cpu.getRegisterValue(destRegister);
		int sourceValue = 0;

		// 2. Retrieve the value from the source (the Kong function handles both numbers and stacks automatically)
		if (sourceRegister != "") {
			sourceValue = cpu.getOperandValue(sourceRegister);
		}

		int result = 0;

		// 3. Perform the arithmetic operations
		if (opcode == "ADD") {
			result = destValue + sourceValue;
		} else if (opcode == "SUB") {
			result = destValue - sourceValue;
		} else if (opcode == "MUL") {
			result = destValue * sourceValue;
		} else if (opcode == "DIV") {
			if (sourceValue == 0) {
				cout << "Error: Division by zero!" << endl;
				exit(1); 
			}
			result = destValue / sourceValue;
		} else if (opcode == "INC") {
			result = destValue + 1;
		} else if (opcode == "DEC") {
			result = destValue - 1;
		}

		// 4. Send the final result to the CPU
		// The CPU will automatically update the LEDs (OF, UF, ZF, CF) and push the value
		cpu.setRegisterValue(destRegister, result);
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
	IOInstruction(string op, string target) {
		opcode = op;
		targetRegister = target;
	}

	void execute(CPU& cpu) override {
		if (opcode == "INPUT") {
			cout << "?";
			int userInput;
			cin >> userInput;
			
			// Send the user input to the CPU to store it and update the flags

			cpu.setRegisterValue(targetRegister, userInput);
		} 
		else if (opcode == "DISPLAY") {
			// Retrieve the actual value from the CPU and display it
			int value = (int)cpu.getRegisterValue(targetRegister);
			cout << value << endl;
		}
	}
};





/**
 * @class MOVInstruction
 * @brief Handles MOV operations (Immediate, Register, Indirect)
 */
class MOVInstruction : public Instruction {
private:
    string dest;
    string source;

public:
    MOVInstruction(string d, string s) {
        dest = d;
        source = s;
    }

    void execute(CPU& cpu) override {
        int val = 0;
        
        // Check if the source is a memory address (Indirect: [R1])
        if (source.front() == '[' && source.back() == ']') {
            // Extract the register name from inside the brackets (e.g., R1 from [R1])
            string regName = source.substr(1, source.length() - 2);
            int address = cpu.getRegisterValue(regName);
            
            // Read the value from memory
            val = cpu.readMemory(address); 
        } 
        else {
            // Handle either an immediate value (e.g., 10) or a register operand (e.g., R1)
            val = cpu.getOperandValue(source);
        }

        // Store the final value in the destination register
        cpu.setRegisterValue(dest, val);
    }
};

/**
 * @class ShiftInstruction
 * @brief Handles bitwise shifts and rotations (SHL, SHR, ROL, ROR)
 */
class ShiftInstruction : public Instruction {
private:
    string opcode;
    string destRegister;
    string countStr;

public:
    ShiftInstruction(string op, string dest, string count) {
        opcode = op;
        destRegister = dest;
        countStr = count;
    }

    void execute(CPU& cpu) override {
        // Retrieve the shift count
        int count = cpu.getOperandValue(countStr);

        // Retrieve the current register value
        int currentVal = cpu.getRegisterValue(destRegister);

        // Convert to an unsigned 8-bit value to perform bitwise operations correctly
        unsigned char uVal = (unsigned char)currentVal;

        // Execute the shift or rotation operation
        if (opcode == "SHL") {
            uVal = uVal << count; // Shift left (zero-fill)
        } 
        else if (opcode == "SHR") {
            uVal = uVal >> count; // Shift right (zero-fill)
        } 
        else if (opcode == "ROL") {
            count = count % 8; // Prevent shifts larger than 8 bits
            uVal = (uVal << count) | (uVal >> (8 - count)); // Rotate left
        } 
        else if (opcode == "ROR") {
            count = count % 8; // Prevent shifts larger than 8 bits
            uVal = (uVal >> count) | (uVal << (8 - count)); // Rotate right
        }

        // Store the result back into the register as a signed 8-bit value
        cpu.setRegisterValue(destRegister, (signed char)uVal);
    }
};



/**
 * @class MOVInstruction
 * @brief Handles MOV instruction for immediate, register, and memory-indirect modes
 */
class MOVInstruction : public Instruction {
private:
	string destRegister;
	string sourceOperand;

public:
	/**
	 * @brief Constructor for MOVInstruction
	 * @param dest Destination register, such as R0
	 * @param source Source operand, such as 10, R1, or [R1]
	 */
	MOVInstruction(string dest, string source) {
		destRegister = dest;
		sourceOperand = source;
	}

	/**
	 * @brief Executes MOV instruction using CPU helper functions
	 */
	void execute(CPU& cpu) override {
		if (!cpu.isRegisterName(destRegister)) {
			cout << "Error: MOV destination must be a register" << endl;
			exit(1);
		}

		int value = cpu.getOperandValue(sourceOperand);
		cpu.setRegisterValue(destRegister, value);
	}
};

/**
 * @class ShiftInstruction
 * @brief Handles bitwise shifts and rotations: SHL, SHR, ROL, ROR
 */
class ShiftInstruction : public Instruction {
private:
	string opcode;
	string destRegister;
	string countOperand;

public:
	ShiftInstruction(string op, string dest, string count) {
		opcode = op;
		destRegister = dest;
		countOperand = count;
	}

	void execute(CPU& cpu) override {
		if (!cpu.isRegisterName(destRegister)) {
			cout << "Error: shift destination must be a register" << endl;
			exit(1);
		}

		int count = cpu.getOperandValue(countOperand);

		if (count < 0) {
			cout << "Error: shift count cannot be negative" << endl;
			exit(1);
		}

		unsigned char value = (unsigned char)cpu.getRegisterValue(destRegister);
		unsigned char result = value;

		if (opcode == "SHL") {
			if (count >= 8) result = 0;
			else result = (unsigned char)(value << count);
		} 
		else if (opcode == "SHR") {
			if (count >= 8) result = 0;
			else result = (unsigned char)(value >> count);
		} 
		else if (opcode == "ROL") {
			count = count % 8;
			if (count == 0) result = value;
			else result = (unsigned char)((value << count) | (value >> (8 - count)));
		} 
		else if (opcode == "ROR") {
			count = count % 8;
			if (count == 0) result = value;
			else result = (unsigned char)((value >> count) | (value << (8 - count)));
		}

		cpu.setRegisterValue(destRegister, (int)result);
		}
};

/**
 * @class LoadInstruction
 * @brief Handles LOAD instruction for direct and register-indirect memory addressing
 */
class LoadInstruction : public Instruction {
private:
	string destRegister;
	string addressOperand;

public:
	LoadInstruction(string dest, string address) {
		destRegister = dest;
		addressOperand = address;
	}

	void execute(CPU& cpu) override {
		if (!cpu.isRegisterName(destRegister)) {
			cout << "Error: LOAD destination must be a register" << endl;
			exit(1);
		}

		int address = cpu.getAddress(addressOperand);
		int value = (int)cpu.readMemory(address);

		cpu.setRegisterValue(destRegister, value);
	}
};

/**
 * @class StoreInstruction
 * @brief Handles STORE instruction for direct and register-indirect memory addressing
 */
class StoreInstruction : public Instruction {
private:
	string firstOperand;
	string secondOperand;

public:
	StoreInstruction(string first, string second) {
		firstOperand = first;
		secondOperand = second;
	}

	void execute(CPU& cpu) override {
		int address;
		int value;

		/*
		 * Supports:
		 * STORE R1, 43
		 * STORE R1, [R2]
		 */
		if (cpu.isRegisterName(firstOperand)) {
			value = (int)cpu.getRegisterValue(firstOperand);
			address = cpu.getAddress(secondOperand);
		}

		/*
		 * Supports:
		 * STORE 20, R3
		 * STORE [R2], R3
		 */
		else {
			address = cpu.getAddress(firstOperand);
			value = cpu.getOperandValue(secondOperand);
		}

		cpu.writeMemory(address, value);
	}
};

/**
 * @class ResetInstruction
 * @brief Handles RESET instruction for clearing one flag
 */
class ResetInstruction : public Instruction {
private:
	string flagName;

public:
	ResetInstruction(string flag) {
		flagName = flag;
	}

	void execute(CPU& cpu) override {
		if (flagName == "") {
			cout << "Error: RESET requires a flag name" << endl;
			exit(1);
		}

		cpu.resetFlag(flagName);
	}
};

/**
 * @class PushInstruction
 * @brief Handles PUSH instruction by pushing a register value onto the system stack
 */
class PushInstruction : public Instruction {
private:
	string registerName;

public:
	PushInstruction(string reg) {
		registerName = reg;
	}

	void execute(CPU& cpu) override {
		if (!cpu.isRegisterName(registerName)) {
			cout << "Error: PUSH source must be a register" << endl;
			exit(1);
		}

		cpu.pushRegister(registerName);
	}
};

/**
 * @class PopInstruction
 * @brief Handles POP instruction by popping the system stack into a register
 */
class PopInstruction : public Instruction {
private:
	string registerName;

public:
	PopInstruction(string reg) {
		registerName = reg;
	}

	void execute(CPU& cpu) override {
		if (!cpu.isRegisterName(registerName)) {
			cout << "Error: POP destination must be a register" << endl;
			exit(1);
		}

		cpu.popToRegister(registerName);
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

	string getOpcode() const {
		return opcode;
	}

	string getArg1() const {
		return arg1;
	}

	string getArg2() const {
		return arg2;
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

/**
 * @class Runner
 * @brief Loads an assembly program, converts operations into Instruction objects, and runs them on CPU
 * @author KONG WAI XIN - Demo runner structure
 */
class Runner {
private:
	CPU cpu;
	sVector<Operation> operations;
	sVector<Instruction*> instructions;

	/**
	 * @brief Deletes dynamically created instruction objects
	 */
	void clearInstructions() {
		for (int i = 0; i < instructions.getSize(); i++) {
			delete instructions[i];
		}
		instructions.clear();
	}

	/**
	 * @brief Creates the correct Instruction subclass based on opcode
	 */
	Instruction* createInstruction(Operation& op) {
		string code = op.getOpcode();
		string a1 = op.getArg1();
		string a2 = op.getArg2();

		if (code == "MOV") {
			return new MOVInstruction(a1, a2);
		} else if (code == "ADD" || code == "SUB" || code == "MUL" || code == "DIV") {
			return new ArithmeticInstruction(code, a1, a2);
		} else if (code == "INC" || code == "DEC") {
			return new ArithmeticInstruction(code, a1);
		} else if (code == "INPUT" || code == "DISPLAY") {
			return new IOInstruction(code, a1);
		} else if (code == "ROL" || code == "ROR" || code == "SHL" || code == "SHR") {
			return new ShiftInstruction(code, a1, a2);
		} else if (code == "LOAD") {
			return new LoadInstruction(a1, a2);
		} else if (code == "STORE") {
			return new StoreInstruction(a1, a2);
		} else if (code == "RESET") {
			return new ResetInstruction(a1);
		} else if (code == "PUSH") {
			return new PushInstruction(a1);
		} else if (code == "POP") {
			return new PopInstruction(a1);
		}

		cout << "Error: unknown instruction " << code << endl;
		exit(1);
	}

	/**
	 * @brief Parses one non-empty assembly line into an Operation object
	 */
	void parseLine(string line) {
		int commentIdx = line.find(';');
		if (commentIdx != -1) {
			line = line.substr(0, commentIdx);
		}

		line = trim(line);
		if (line.empty()) {
			return;
		}

		int space = line.find_first_of(" \t");
		if (space == -1) {
			operations.pushBack(Operation(line, "", ""));
			return;
		}

		string opcode = trim(line.substr(0, space));
		string args = trim(line.substr(space + 1));

		int comma = args.find(',');
		string arg1;
		string arg2;

		if (comma == -1) {
			arg1 = trim(args);
			arg2 = "";
		} else {
			arg1 = trim(args.substr(0, comma));
			arg2 = trim(args.substr(comma + 1));
		}

		operations.pushBack(Operation(opcode, arg1, arg2));
	}

public:
	/**
	 * @brief Destructor clears all dynamically allocated instruction objects
	 */
	~Runner() {
		clearInstructions();
	}

	/**
	 * @brief Loads .asm file and stores parsed operations
	 */
	bool loadProgram(string fileName) {
		ifstream fd(fileName);

		if (!fd.is_open()) {
			cout << "Error: Could not open file " << fileName << endl;
			return false;
		}

		string line;
		while (getline(fd, line)) {
			parseLine(line);
		}

		fd.close();
		return true;
	}

	/**
	 * @brief Converts parsed operations into Instruction objects
	 */
	void buildInstructions() {
		clearInstructions();

		for (int i = 0; i < operations.getSize(); i++) {
			Instruction* instruction = createInstruction(operations[i]);
			instructions.pushBack(instruction);
		}
	}

	/**
	 * @brief Executes all instructions using the CPU program counter
	 */
	void run() {
		while (cpu.getPC() < instructions.getSize()) {
			int currentPC = cpu.getPC();

			instructions[currentPC]->execute(cpu);

			cpu.incrementPC();
		}
	}

	/**
	 * @brief Displays final CPU dump
	 */
	void dump() const {
		cpu.dump();
	}

	/**
	 * @brief Writes final CPU dump to output file
	 */
	bool writeOutputFile(string outputFileName) const {
		ofstream out(outputFileName.c_str());

		if (!out.is_open()) {
			cout << "Error: Could not create output file " << outputFileName << endl;
			return false;
		}

		cpu.dump(out);
		out.close();

		return true;
	}

};

// Entry point


// Entry point
int main(int argc, char* argv[]) {
	string fileName;

	if (argc < 2) {
		cout << "Enter filename: ";
		cin >> fileName;
	} else {
		fileName = argv[1];
	}

	Runner runner;

	if (!runner.loadProgram(fileName)) {
		return 1;
	}

	string outputFileName = "output.txt";

	if (argc >= 3) {
		outputFileName = argv[2];
	}

	runner.buildInstructions();
	runner.run();
	runner.dump();
	runner.writeOutputFile(outputFileName);

	return 0;
}

