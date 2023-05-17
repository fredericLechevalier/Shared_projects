BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _memset      ;Export’memset’

_memset:        ;void *memset(RDI = void *s, RSI = int c, RDX = size_t size); with RCX = int cptr
    ENTER   0, 0
    MOV     rcx, -1         ;initialize cptr
    CMP     rdx, 0          ;is size_t empty ?
    JE      _memset_return  ;if true : don't need to change anything, return s
    JMP     _memset_loop

_memset_loop:
    INC     rcx                     ;cptr++
    CMP     rcx, rdx                ;compares cptr && size
    JE      _memset_return          ;if cptr == size, return s
    MOV     byte [rdi + rcx], sil   ;set s[cptr] to c
    JMP     _memset_loop            ;recursive


_memset_return:                     ;return *s
    MOV     rax, rdi
    LEAVE
    RET

;MGIGHT NEED FUTURE UPDATE