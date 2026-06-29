; Test program for all instruction types

; MOV operations
MOV R0, 10        ; immediate
MOV R1, 20        ; immediate
MOV R2, R0        ; register to register
MOV R3, [R2]      ; indirect (memory[10])

; Arithmetic operations
ADD R0, R1        ; R0 = 10 + 20 = 30
SUB R1, R0        ; R1 = 20 - 30 = -10
MUL R2, R0        ; R2 = 10 * 30 = 300
DIV R3, R1        ; R3 = 0 / -10 = 0

; INC/DEC
INC R0            ; R0 = 30 + 1 = 31
DEC R1            ; R1 = -10 - 1 = -11

; Memory operations
STORE R0, 40      ; memory[40] = 31
LOAD R4, 40       ; R4 = 31

; Stack operations
PUSH R0           ; push 31
PUSH R1           ; push -11
POP R5            ; R5 = -11
POP R6            ; R6 = 31

; Flag reset
RESET OF
RESET UF
RESET CF
RESET ZF

; Display
DISPLAY R0        ; print 31
DISPLAY R5        ; print -11

; Input
INPUT R7          ; read from user
DISPLAY R7        ; print user input
