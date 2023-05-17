BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _strncmp     ;Export’strncmp’

_strncmp:               ;int strrcmp(RDI = const char *str1, RSI = const char *str2, RDX = size_t size); with RCX = int cptr, r9b = char temp_str2
    ENTER   0, 0
    MOV     rcx, -1     ;initialize cptr
    JMP     _strncmp_loop

_strncmp_loop:
    INC     rcx                                 ;cptr++
    CMP     rcx, rdx                            ;compares cptr && size
    JE      _strncmp_equal                      ;if : cptr == size : return 0 (We checked 'size' amount of char and found nothing different)
    MOV     r9b, byte[rsi + rcx]                ;creates a temporary value of str2[cptr] because CMP bellow cannot take "byte" instruction in both opperands
    CMP     byte[rdi + rcx], r9b                ;compares str1[cptr] && str2[cptr]
    JG      _strncmp_str1_greater               ;if : str1[cptr] > str2[cptr], return 1
    JL      _strncmp_str1_lesser                ;if : str1[cptr] < str2[cptr], return -1
    CMP     byte[rdi + rcx], 0x0                ;compares str1[cptr] && '\0' ?
    JE      _strncmp_str1_end                   ;if : str1[cptr] == '\0', do last check at _strncmp_str1_end
    CMP     byte[rsi + rcx], 0x0                ;compares str2[cptr] && '\0' ?
    JE      _strncmp_str1_greater               ;if : str2[cptr] == '\0', return 1 (here we know str1[cptr] != '\0', so str1 can only be greater)
    JMP     _strncmp_loop                       ;else : loop again (recursive)

_strncmp_str1_end:
    CMP     byte[rsi + rcx], 0x0        ;compares str2[cptr + 1] && '\0'
    JE      _strncmp_equal              ;if : str2[cptr] == '\0' too, return 0
    JMP     _strncmp_str1_lesser        ;else : return -1

_strncmp_str1_greater:                  ;returns positive result
    MOV     r8b, byte[rdi + rcx]        ;creates a temporary int value(r8b) to store our char's ASCII as it cannot hold the answer for the SUB bellow
    SUB     r8b, r9b                    ;calculates the ASCII difference between str1[cptr] and str2[cptr]
    MOVSX   rax, r8b                    ;stores the result in return register
    LEAVE
    RET

_strncmp_str1_lesser:                   ;returns negative result
    SUB     r9b, byte[rdi + rcx]        ;calculates the ASCII difference between str2[cptr] and str1[cptr]
    MOVSX   rax, r9b                    ;stores the result in return register
    NEG     rax                         ;sets the result to it's oposite (in this case, to a negative number)
    LEAVE
    RET

_strncmp_equal:                         ;return 0
    MOV     rax, 0
    LEAVE
    RET
