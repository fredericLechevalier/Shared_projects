BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _strcmp      ;Export’strcmp’

_strcmp:                ;int strrcmp(RDI = const char *str1, RSI = const char *str2); with RCX = int cptr, r9b = char temp_str2
    ENTER   0, 0
    MOV     rcx, -1     ;initialize cptr
    JMP     _strcmp_loop

_strcmp_loop:
    INC     rcx                                 ;cptr++
    MOV     r9b, byte[rsi + rcx]                ;creates a temporary value of str2[cptr] because CMP bellow cannot take "byte" instruction in both opperands
    CMP     byte [rdi + rcx], r9b               ;compares str1[cptr] && str2[cptr]
    JG      _strcmp_str1_greater                ;if : str1[cptr] > str2[cptr], return 1
    JL      _strcmp_str1_lesser                 ;if : str1[cptr] < str2[cptr], return -1
    CMP     byte [rdi + rcx], 0x0               ;compares str1[cptr] && '\0' ?
    JE      _strcmp_str1_end                    ;if : str1[cptr] == '\0', do last check at _strcmp_str1_end
    CMP     byte [rsi + rcx], 0x0               ;compares str2[cptr] && '\0' ?
    JE      _strcmp_str1_greater                ;if : str2[cptr] == '\0', return 1 (here we know str1[cptr] != '\0', so str1 can only be greater)
    JMP     _strcmp_loop                        ;else : loop again (recursive)

_strcmp_str1_end:
    CMP     byte [rsi + rcx], 0x0       ;compares str2[cptr + 1] && '\0'
    JE      _strcmp_equal               ;if : str2[cptr] == '\0' too, return 0
    JMP     _strcmp_str1_lesser         ;else : return -1

_strcmp_str1_greater:
    SUB     r9b, byte[rdi + rcx]        ;calculates the ASCII difference between str2[cptr] and str1[cptr]
    MOVSX   rax, r9b                    ;stores the result in return register
    NEG     rax                         ;sets the result to it's oposite (in this case, to a negative number)
    LEAVE
    RET

_strcmp_str1_lesser:                   ;returns negative result
    SUB     r9b, byte[rdi + rcx]        ;calculates the ASCII difference between str2[cptr] and str1[cptr]
    MOVSX   rax, r9b                    ;stores the result in return register
    NEG     rax                         ;sets the result to it's oposite (in this case, to a negative number)
    LEAVE
    RET

_strcmp_equal:
    MOV     rax, 0
    LEAVE
    RET
