BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _memcpy      ;Export’memcpy’

_memcpy:        ;void *memcpy(RDI = void *dest, RSI = const vod *src, RDX = size_t n); with RCX = int cptr, r9b = char temp_char
    ENTER   0, 0
    MOV     rcx, -1         ;initialize cptr
    CMP     rdx, 0          ;is size_t empty ?
    JE      _memcpy_return  ;if true : don't need to cahnge anything, return s
    JMP     _memcpy_loop

_memcpy_loop:
    INC     rcx                                 ;cptr++
    CMP     rcx, rdx                            ;compares cptr && size
    JE      _memcpy_return                      ;if cptr == size, return s
;    CMP     byte [rsi + rcx], 0x0               ;compares src[cptr] && \0  need to see origial behaviour to decide wich to test (src / dest)
;    JE      _memcpy_return                      ;if src[cptr] == '\0' : return dest
    MOV     r9b, byte[rsi + rcx]                ;creates a temporary char value(r9b) to store our char as the MOV instruction bellow dosn't accept byte[] in both opperands
    MOV     byte [rdi + rcx], r9b               ;set s[cptr] to c
    JMP     _memcpy_loop                        ;recursive


_memcpy_return:                     ;return *dest
    MOV     rax, rdi
    LEAVE
    RET

