BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _strlen 		;Export’strlen’

_strlen:                            ;size_t strlen(char *rdi) with rcx = int cptr
	ENTER 0, 0
    MOV     rcx, 0
    CMP     byte[rdi], 0x0          ;Is rdi completly empty ?
    JNE     _strlen_loop            ;jump if rdi is not empty
    MOV     rax, 0
	LEAVE
    RET
    XOR     rax, rax

_strlen_loop:
    ADD     rcx, 1                  ;cptr++
    CMP     byte[rdi + rcx], 0x0    ;is rdi[rcx] = \0 ?
    JNE     _strlen_loop            ;jump if rdi is not empty (recursive)
    MOV     rax, rcx
	LEAVE
    RET



