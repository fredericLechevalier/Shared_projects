BITS 64 			;64−bit mode
SECTION .text 		;Code section
GLOBAL _strcasecmp      ;Export’strcasecmp’

_strcasecmp:                ;int strrcmp(RDI = const char *str1, RSI = const char *str2); with RCX = int cptr, r9b = char temp_str2, r8b = char tempCase
    ENTER   0, 0
    MOV     rcx, -1     ;initialize cptr
    JMP     _strcasecmp_is_letter

_strcasecmp_is_letter:                          ;looks for lowercase letter in str1[cptr]
    INC     rcx                                 ;cptr++
    MOV     r9b, byte[rsi + rcx]                ;creates a temporary value of str2[cptr] because CMP bellow cannot take "byte" instruction in both opperands
    CMP     byte [rdi + rcx], 'z'               ;compares str1[cptr] && 'z'
    JA      _strcasecmp_nocase_check            ;if : str1[cptr] > 'z', jump to nocase_check, as str1[cptr] isn't a letter
    CMP     byte [rdi + rcx], 'a'               ;compares str1[cptr] && 'a'
    JAE      _strcasecmp_lowercase              ;if : str1[cptr] >= 'a', jump to lowercase_found, as str1[cptr] is a lower case letter
    CMP     byte [rdi], 'Z'                     ;compares str1[cptr] && 'Z'
    JA      _strcasecmp_nocase_check            ;if : str1[cptr] > 'Z', jump to nocase_check, as str1[cptr] isn't a uppercase letter
    CMP     byte [rdi + rcx], 'A'               ;compares str1[cptr] && 'A'
    JAE      _strcasecmp_uppercase              ;if : str1[cptr] >= 'A', jump to uppecasecase_found, as str1[cptr] is a lower case letter
    JMP     _strcasecmp_nocase_check            ;str1[cptr] isn't a letter, let's jump tp nocase_check

_strcasecmp_lowercase:                          ;since str1[cptr] is a lower case, we now act accordigly to str2[cptr] by finding out if it's a letter
    CMP     r9b, 'A'                            ;compares str2[cptr] && 'A'
    JB      _strcasecmp_nocase_check            ;if : str2[cptr] < 'A' then go to nocase_check as str2[cptr] cannot be a letter
    MOV     r8b, byte [rdi + rcx]               ;creates temporary char to hold case convertion
    XOR     r8b, 0x20                           ;converts char stempCase to uppercase
    CMP     r8b, r9b                            ;compares str1[cptr] && (str2[cptr] - 32)
    JE     _strcasecmp_is_letter                ;if : str1[cptr] == (str2[cptr] - 32) (while ignoring cases) jump to next character
    JMP    _strcasecmp_nocase_check             ;else : even while ignoring case no match were found, so we go to our classic check

_strcasecmp_uppercase:                          ;since str1[cptr] is a upper case, we now act accordigly to str2[cptr] by finding out if it's a lowercase letter
    CMP     r9b, 'a'                            ;compares str2[cptr] && 'a'
    JB      _strcasecmp_nocase_check            ;if : str2[cptr] < 'a' then go to nocase_check as str2[cptr] cannot be a lowercase letter
    MOV     r8b, byte [rdi + rcx]               ;creates temporary char to hold case convertion
    XOR     r8b, 0x20                           ;converts char stempCase to uppercase
    CMP     r8b, r9b                            ;compares str1[cptr] && (str2[cptr] + 32)
    JE     _strcasecmp_is_letter                ;if : str1[cptr] == (str2[cptr] + 32) (while ignoring cases) jump to next character
    JMP    _strcasecmp_nocase_check             ;else : even while ignoring case no match were found, so we go to our classic check

_strcasecmp_nocase_check:
    CMP     byte [rdi + rcx], r9b               ;compares str1[cptr] && str2[cptr]
    JG      _strcasecmp_str1_greater            ;if : str1[cptr] > str2[cptr], return 1
    JL      _strcasecmp_str1_lesser             ;if : str1[cptr] < str2[cptr], return -1
    CMP     byte [rdi + rcx], 0x0               ;compares str1[cptr] && '\0' ?
    JE      _strcasecmp_str1_end                ;if : str1[cptr] == '\0', do last check at _strcasecmp_str1_end
    CMP     byte [rsi + rcx], 0x0               ;compares str2[cptr] && '\0' ?
    JE      _strcasecmp_str1_greater            ;if : str2[cptr] == '\0', return 1 (here we know str1[cptr] != '\0', so str1 can only be greater)
    JMP     _strcasecmp_is_letter               ;else : check next letter (recursive)

_strcasecmp_str1_end:
    CMP     byte [rsi + rcx], 0x0       ;compares str2[cptr + 1] && '\0'
    JE      _strcasecmp_equal               ;if : str2[cptr] == '\0' too, return 0
    JMP     _strcasecmp_str1_lesser         ;else : return -1

_strcasecmp_str1_greater:
    SUB     r9b, byte[rdi + rcx]        ;calculates the ASCII difference between str2[cptr] and str1[cptr]
    MOVSX   rax, r9b                    ;stores the result in return register
    NEG     rax                         ;sets the result to it's oposite (in this case, to a negative number)
    LEAVE
    RET

_strcasecmp_str1_lesser:                   ;returns negative result
    SUB     r9b, byte[rdi + rcx]        ;calculates the ASCII difference between str2[cptr] and str1[cptr]
    MOVSX   rax, r9b                    ;stores the result in return register
    NEG     rax                         ;sets the result to it's oposite (in this case, to a negative number)
    LEAVE
    RET

_strcasecmp_equal:
    MOV     rax, 0
    LEAVE
    RET
