# Virtual Machine and Assembly Language Interpreter

- CCP6124 Object-oriented Programming and Data Structures Trimester 2610

# Build

- clone this repository

```bash
git clone https://github.com/black-OWL432/asm-interpreter.git
cd asm-interpreter
```

- **linux/MacOS**: compile with g++

```bash
g++ src/main.cpp -o out/vm && ./out/vm test.asm
```

- **Windows**: install mingw-w64 and add to PATH then compile with g++

```ps1
g++ src\main.cpp -o out\vm.exe
& ".\out\vm.exe" test.asm
```
