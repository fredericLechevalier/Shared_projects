BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _strchr      ;Export’strchr’

_strchr:            ;char *strchr(rdi = char *str, sil = int c ) with rcx = int cptr
	ENTER 0, 0
    MOV     rcx, -1                 ;initializes cptr
;    CMP     sil, 0x0                ;is c == \0 ?
;    JE      _strchr_EmptyC          ;if true : return Empty string
    CMP     byte[rdi], 0x0          ;is str == NULL ? (aka is str empty ?)
    JNE     _strchr_loop            ;if false : jump -> _strchr_loop
    MOV     rax, 0x0                ;else : return str because we got an empty string !
    LEAVE
    RET

_strchr_loop:
    ADD     rcx, 1                      ;cptr++
    CMP     byte[rdi + rcx], 0x0        ;is str[cptr] == \0 ? aka : are we at the end of the string ?
    JE      _strchr_Char_Not_Found      ;if true : return NULL (only trigers if no match were found in an existing string.)
    CMP     byte[rdi + rcx], sil        ;is str[cptr] == c ?
    JNE     _strchr_loop                ;if false : jump -> _strchr_loop (recursive)
    ADD     rdi, rcx                    ;else : get all chars after rdi[rcx]
    MOV     rax, rdi
    LEAVE
    RET

_strchr_EmptyC:
    ADD     rdi, rcx                    ;get all chars after rdi[rcx]
    MOV     rax, rdi
    LEAVE
    RET

_strchr_Char_Not_Found:             ;return NULL
    CMP     sil, 0x0                ;is c == \0 ?
    JE      _strchr_EmptyC          ;if true : return Empty string
    MOV     rax, 0x0
    LEAVE
    RET