; Test MOV immediate, MOV register, MOV indirect
; Test STORE direct and STORE register-indirect

MOV R0, 88        ; MOV immediate: R0 = 88
MOV R6, R0        ; MOV register: R6 = R0 = 88

MOV R1, 43        ; R1 stores destination memory address 43
MOV R2, 30        ; R2 stores source memory address 30

STORE R6, 30      ; STORE direct: memory[30] = R6 = 88
MOV R3, [R2]      ; MOV indirect: R3 = memory[address in R2] = memory[30] = 88
DISPLAY R3        ; Expected output: 88

MOV R4, 12        ; R4 = 12
STORE R4, 43      ; STORE direct: memory[43] = R4 = 12
MOV R5, [R1]      ; MOV indirect: R5 = memory[address in R1] = memory[43] = 12
DISPLAY R5        ; Expected output: 12

STORE [R1], [R2]  ; STORE indirect: memory[address in R1] = memory[address in R2]
                  ; memory[43] = memory[30] = 88

MOV R7, [R1]      ; MOV indirect again: R7 = memory[43] = 88
DISPLAY R7        ; Expected output: 88