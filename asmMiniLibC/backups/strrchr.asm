BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL strrchr      ;Export’strrchr’

strrchr:            ;char *strrchr(rdi = char *str, sil(aka 8bit rsi) = int c ) with rcx = int cptr, r9 = int temp_cptr
	ENTER 0, 0
    MOV     r9, 0x0                 ;initializes temp_cptr at NULL in case of never finding occurences of c
    MOV     rcx, -1                 ;initializes cptr
    CMP     sil, 0x0                ;is c == \0 ?
    JE      _strrchr_EmptyC         ;if true : return Empty string
    CMP     byte[rdi], 0x0          ;is str == NULL ? (aka is str empty ?)
    JNE     _strrchr_loop           ;if false : jump -> _strrchr_loop
    MOV     rax, 0x0                ;else : return str because we got an empty string !
    LEAVE
    RET

_strrchr_loop:
    ADD     rcx, 1                      ;cptr++
    CMP     byte[rdi + rcx], 0x0        ;is str[cptr] == \0 ? aka : are we at the end of the string ?
    JE      _strrchr_return             ;if true : return what r9 as stored.
    CMP     byte[rdi + rcx], sil        ;is str[cptr] == c ?
    JNE     _strrchr_loop               ;if false : jump -> _strrchr_loop (recursive)
    MOV     r9, rcx                     ;else : creates a temp_cptr to store it and keep looking for another occurence of c
    JMP     _strrchr_loop

_strrchr_EmptyC:
    MOV     al, ""
    LEAVE
    RET

_strrchr_NULL:
    MOV     rax, 0x0
    LEAVE
    RET

_strrchr_return:
    CMP     r9, 0x0         ;is r9 == NULL ? aka : Did we found any matches ?
    JE      _strrchr_NULL   ;if true : return NULL
    ADD     rdi, r9         ;get all chars after rdi[r9]
    MOV     rax, rdi        ;get ready to output str
    LEAVE
    RET