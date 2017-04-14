; Disassembly of file: main.o
; Wed Apr 12 20:15:41 2017
; Mode: 64 bits
; Syntax: MASM/ML64
; Instruction set: SSE2, x64

public _main
public __ZNSt3__111char_traitsIcE6lengthEPKc            ; Note: Weak. Not supported by MASM 

extern _strlen: near
extern ___gxx_personality_v0: byte
extern __Znwm: near
extern __ZdlPv: near
extern __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev: near
extern __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm: near
extern __ZN8AXWindow4initEffPKcj: near
extern __ZN8AXWindow3runEv: near
extern __ZN8AXWindow15setCurrentSceneEP7AXScene: near
extern __ZN8AXEntityC1ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEffff: near
extern __ZN7AXSceneC1Ev: near
extern __ZN7AXScene9addEntityEP8AXEntity: near
extern __ZN5AXLog3logERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_i: near
extern __Unwind_Resume: near


__TEXT.__text SEGMENT PARA 'CODE'                       ; section number 1

_main   dd 0E5894855H, 0B0EC8148H                       ; 0000 _ -8.1037312E+22 -1.7208004E-09 
        dd 0F3000001H                                   ; 0008 _ -1.0141206E+31 
        db 0FH, 10H, 05H                                ; 000C _ ...
        dd _main-$+416H                                 ; 000F _ 1.4923829E-42 (rel)
        dd 0D100FF3H                                    ; 0013 _ 4.4392624E-31 
        dd _main-$+40AH                                 ; 0017 _ 1.4867777E-42 (rel)
        db 48H, 8DH, 05H                                ; 001B _ H..
        dd _main-$+480H                                 ; 001E _ 1.66194E-42 (rel)
        dd 000009B9H, 3C85C700H                         ; 0022 _ 3.4878319E-42 0.016330242 
        dd 00FFFFFFH, 89000000H                         ; 002A _ 2.3509886E-38 -1.540744E-33 
        dd 0FFFF38BDH, 0B58948FFH                       ; 0032 _ NAN.0 -1.022854E-06 
        dd 0FFFFFF30H, 89C78948H                        ; 003A _ NAN.0 -4.8036606E-33 
        db 0CEH, 0E8H                                   ; 0042 _ ..
        dd __ZN8AXWindow4initEffPKcj-$-48H              ; 0044 _ 0.0 (rel)
        dd 0F00F883H, 0001B985H                         ; 0048 _ 6.3587489E-30 1.5838736E-40 
        dd 858D4800H, 0FFFFFF18H                        ; 0050 _ -1.3286025E-35 NAN.0 
        dd 48858948H, 48FFFFFFH                         ; 0058 _ 273482.25 524287.97 
        db 8DH, 05H                                     ; 0060 _ ..
        dd _main-$+406H                                 ; 0062 _ 1.5862699E-42 (rel)
        dd 40858948H, 48FFFFFFH                         ; 0066 _ 4.173008 524287.97 
        dd 0FF488D8BH, 8948FFFFH                        ; 006E _ -2.6658053E+38 -2.4194493E-33 
        dd 0FFFF588DH, 858948FFH                        ; 0076 _ NAN.0 -1.2910233E-35 
        dd 0FFFFFF50H, 58858B48H                        ; 007E _ NAN.0 1.174666E+15 
        dd 48FFFFFFH, 0FF608589H                        ; 0086 _ 524287.97 -2.9844043E+38 
        dd 8948FFFFH, 0FFFF6885H                        ; 008E _ -2.4194493E-33 NAN.0 
        dd 858948FFH, 0FFFFFF70H                        ; 0096 _ -1.2910233E-35 NAN.0 
        dd 78858948H, 48FFFFFFH                         ; 009E _ 2.1667496E+34 524287.97 
        dd 001040C7H, 48000000H                         ; 00A6 _ 1.4926057E-39 131072.0 
        dd 000840C7H, 48000000H                         ; 00AE _ 7.579217E-40 131072.0 
        dd 000000C7H, 8B480000H                         ; 00B6 _ 2.7885839E-43 -3.8518599E-32 
        dd 0FFFF508DH, 0CF8948FFH                       ; 00BE _ NAN.0 -4.6065249E+09 
        dd 0B8858948H, 48FFFFFEH                        ; 00C6 _ -6.3675048E-05 524287.94 
        dd 0FEB08D89H                                   ; 00CE _ -1.1733951E+38 
        db 0FFH, 0FFH, 0E8H                             ; 00D2 _ ...
        dd __ZNSt3__111char_traitsIcE6lengthEPKc-$-0D9H ; 00D5 _ 0.0 (rel)
        dd 0B8BD8B48H, 48FFFFFEH                        ; 00D9 _ -9.0381654E-05 524287.94 
        dd 0FEB0B58BH, 8948FFFFH                        ; 00E1 _ -1.1744338E+38 -2.4194493E-33 
        db 0C2H, 0E8H                                   ; 00E9 _ ..
        dd __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm-$-0EFH; 00EB _ 0.0 (rel)
        dd 00858D48H, 48FFFFFFH                         ; 00EF _ 1.2264803E-38 524287.97 
        dd 48884589H                                    ; 00F7 _ 279084.28 
        db 8DH, 05H                                     ; 00FB _ ..
        dd _main-$+2ECH                                 ; 00FD _ 1.408305E-42 (rel)
        dd 80458948H, 884D8B48H                         ; 0101 _ -6.3858965E-39 -6.1853668E-34 
        dd 984D8948H, 90458948H                         ; 0109 _ -2.6564938E-24 -3.8957157E-29 
        dd 98458B48H, 0A0458948H                        ; 0111 _ -2.5531972E-24 -1.6731972E-19 
        dd 0A8458948H, 0B0458948H                       ; 0119 _ -1.0965465E-14 -7.1863271E-10 
        dd 0B8458948H, 1040C748H                        ; 0121 _ -4.7096313E-05 3.8018844E-29 
        dd 00000000H, 0840C748H                         ; 0129 _ 0.0 5.8012152E-34 
        dd 00000000H, 0000C748H                         ; 0131 _ 0.0 7.1488642E-41 
        dd 48000000H, 48904D8BH                         ; 0139 _ 131072.0 295532.34 
        dd 8948CF89H, 0FFFEA885H                        ; 0141 _ -2.4171707E-33 NAN.0 
        dd 8D8948FFH, 0FFFFFEA0H                        ; 0149 _ -8.46085E-31 NAN.0 
        db 0E8H                                         ; 0151 _ .
        dd __ZNSt3__111char_traitsIcE6lengthEPKc-$-156H ; 0152 _ 0.0 (rel)
        dd 98858948H, 0E9FFFFFEH                        ; 0156 _ -3.4518313E-24 -3.8685622E+25 
        dd 00000000H                                    ; 015E _ 0.0 
?_001:  mov     rdi, qword ptr [rbp-158H]               ; 0162 _ 48: 8B. BD, FFFFFEA8
        mov     rsi, qword ptr [rbp-160H]               ; 0169 _ 48: 8B. B5, FFFFFEA0
        mov     rdx, qword ptr [rbp-168H]               ; 0170 _ 48: 8B. 95, FFFFFE98
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm; 0177 _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_002                                   ; 017C _ E9, 00000000

?_002:
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_003                                   ; 0181 _ E9, 00000000

?_003:  lea     rdi, [rbp-0E8H]                         ; 0186 _ 48: 8D. BD, FFFFFF18
        lea     rsi, [rbp-100H]                         ; 018D _ 48: 8D. B5, FFFFFF00
        mov     edx, 2                                  ; 0194 _ BA, 00000002
        call    __ZN5AXLog3logERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_i; 0199 _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_004                                   ; 019E _ E9, 00000000

?_004:  lea     rdi, [rbp-100H]                         ; 01A3 _ 48: 8D. BD, FFFFFF00
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 01AA _ E8, 00000000(rel)
        lea     rdi, [rbp-0E8H]                         ; 01AF _ 48: 8D. BD, FFFFFF18
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 01B6 _ E8, 00000000(rel)
        mov     dword ptr [rbp-0C4H], -1                ; 01BB _ C7. 85, FFFFFF3C, FFFFFFFF
        jmp     ?_015                                   ; 01C5 _ E9, 0000023A

; Note: Inaccessible code
        mov     ecx, edx                                ; 01CA _ 89. D1
        mov     qword ptr [rbp-108H], rax               ; 01CC _ 48: 89. 85, FFFFFEF8
        mov     dword ptr [rbp-10CH], ecx               ; 01D3 _ 89. 8D, FFFFFEF4
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_005                                   ; 01D9 _ E9, 0000001B

; Note: Inaccessible code
        lea     rdi, [rbp-100H]                         ; 01DE _ 48: 8D. BD, FFFFFF00
        mov     ecx, edx                                ; 01E5 _ 89. D1
        mov     qword ptr [rbp-108H], rax               ; 01E7 _ 48: 89. 85, FFFFFEF8
        mov     dword ptr [rbp-10CH], ecx               ; 01EE _ 89. 8D, FFFFFEF4
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 01F4 _ E8, 00000000(rel)
?_005:  lea     rdi, [rbp-0E8H]                         ; 01F9 _ 48: 8D. BD, FFFFFF18
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 0200 _ E8, 00000000(rel)
        jmp     ?_016                                   ; 0205 _ E9, 00000209

?_006:  mov     eax, 88                                 ; 020A _ B8, 00000058
        mov     edi, eax                                ; 020F _ 89. C7
        call    __Znwm                                  ; 0211 _ E8, 00000000(rel)
        mov     rdi, rax                                ; 0216 _ 48: 89. C7
        mov     rcx, rax                                ; 0219 _ 48: 89. C1
        mov     qword ptr [rbp-170H], rdi               ; 021C _ 48: 89. BD, FFFFFE90
        mov     rdi, rax                                ; 0223 _ 48: 89. C7
        mov     qword ptr [rbp-178H], rcx               ; 0226 _ 48: 89. 8D, FFFFFE88
        call    __ZN7AXSceneC1Ev                        ; 022D _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_007                                   ; 0232 _ E9, 00000000

?_007:  mov     rax, qword ptr [rbp-178H]               ; 0237 _ 48: 8B. 85, FFFFFE88
        mov     qword ptr [rbp-118H], rax               ; 023E _ 48: 89. 85, FFFFFEE8
        mov     rdi, rax                                ; 0245 _ 48: 89. C7
        call    __ZN8AXWindow15setCurrentSceneEP7AXScene; 0248 _ E8, 00000000(rel)
        mov     ecx, 160                                ; 024D _ B9, 000000A0
        mov     edi, ecx                                ; 0252 _ 89. CF
        call    __Znwm                                  ; 0254 _ E8, 00000000(rel)
        mov     rdi, rax                                ; 0259 _ 48: 89. C7
        mov     byte ptr [rbp-139H], 1                  ; 025C _ C6. 85, FFFFFEC7, 01
        lea     rdx, [rbp-138H]                         ; 0263 _ 48: 8D. 95, FFFFFEC8
        mov     qword ptr [rbp-38H], rdx                ; 026A _ 48: 89. 55, C8
        lea     rdx, [_main+282H]                       ; 026E _ 48: 8D. 15, 00000282(rel)
        mov     qword ptr [rbp-40H], rdx                ; 0275 _ 48: 89. 55, C0
        mov     rsi, qword ptr [rbp-38H]                ; 0279 _ 48: 8B. 75, C8
        mov     qword ptr [rbp-28H], rsi                ; 027D _ 48: 89. 75, D8
        mov     qword ptr [rbp-30H], rdx                ; 0281 _ 48: 89. 55, D0
        mov     rdx, qword ptr [rbp-28H]                ; 0285 _ 48: 8B. 55, D8
        mov     qword ptr [rbp-20H], rdx                ; 0289 _ 48: 89. 55, E0
        mov     qword ptr [rbp-18H], rdx                ; 028D _ 48: 89. 55, E8
        mov     qword ptr [rbp-10H], rdx                ; 0291 _ 48: 89. 55, F0
        mov     qword ptr [rbp-8H], rdx                 ; 0295 _ 48: 89. 55, F8
        mov     qword ptr [rdx+10H], 0                  ; 0299 _ 48: C7. 42, 10, 00000000
        mov     qword ptr [rdx+8H], 0                   ; 02A1 _ 48: C7. 42, 08, 00000000
        mov     qword ptr [rdx], 0                      ; 02A9 _ 48: C7. 02, 00000000
        mov     rsi, qword ptr [rbp-30H]                ; 02B0 _ 48: 8B. 75, D0
        mov     qword ptr [rbp-180H], rdi               ; 02B4 _ 48: 89. BD, FFFFFE80
        mov     rdi, rsi                                ; 02BB _ 48: 89. F7
        mov     qword ptr [rbp-188H], rsi               ; 02BE _ 48: 89. B5, FFFFFE78
        mov     qword ptr [rbp-190H], rax               ; 02C5 _ 48: 89. 85, FFFFFE70
        mov     qword ptr [rbp-198H], rdx               ; 02CC _ 48: 89. 95, FFFFFE68
        call    __ZNSt3__111char_traitsIcE6lengthEPKc   ; 02D3 _ E8, 00000000(rel)
        mov     qword ptr [rbp-1A0H], rax               ; 02D8 _ 48: 89. 85, FFFFFE60
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_008                                   ; 02DF _ E9, 00000000

?_008:  mov     rdi, qword ptr [rbp-198H]               ; 02E4 _ 48: 8B. BD, FFFFFE68
        mov     rsi, qword ptr [rbp-188H]               ; 02EB _ 48: 8B. B5, FFFFFE78
        mov     rdx, qword ptr [rbp-1A0H]               ; 02F2 _ 48: 8B. 95, FFFFFE60
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm; 02F9 _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_009                                   ; 02FE _ E9, 00000000

?_009:
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_010                                   ; 0303 _ E9, 00000000

?_010:  lea     rsi, [rbp-138H]                         ; 0308 _ 48: 8D. B5, FFFFFEC8
; Note: Memory operand is misaligned. Performance penalty
        movss   xmm0, dword ptr [_main+12DH]            ; 030F _ F3: 0F 10. 05, 0000012D(rel)
        mov     rdi, qword ptr [rbp-190H]               ; 0317 _ 48: 8B. BD, FFFFFE70
        movss   dword ptr [rbp-1A4H], xmm0              ; 031E _ F3: 0F 11. 85, FFFFFE5C
        movss   xmm1, dword ptr [rbp-1A4H]              ; 0326 _ F3: 0F 10. 8D, FFFFFE5C
        movss   xmm2, dword ptr [rbp-1A4H]              ; 032E _ F3: 0F 10. 95, FFFFFE5C
        movss   xmm3, dword ptr [rbp-1A4H]              ; 0336 _ F3: 0F 10. 9D, FFFFFE5C
        call    __ZN8AXEntityC1ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEffff; 033E _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_011                                   ; 0343 _ E9, 00000000

?_011:  lea     rdi, [rbp-138H]                         ; 0348 _ 48: 8D. BD, FFFFFEC8
        mov     byte ptr [rbp-139H], 0                  ; 034F _ C6. 85, FFFFFEC7, 00
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 0356 _ E8, 00000000(rel)
        mov     rdi, qword ptr [rbp-190H]               ; 035B _ 48: 8B. BD, FFFFFE70
        mov     qword ptr [rbp-120H], rdi               ; 0362 _ 48: 89. BD, FFFFFEE0
        mov     rdi, qword ptr [rbp-118H]               ; 0369 _ 48: 8B. BD, FFFFFEE8
        mov     rsi, qword ptr [rbp-120H]               ; 0370 _ 48: 8B. B5, FFFFFEE0
        call    __ZN7AXScene9addEntityEP8AXEntity       ; 0377 _ E8, 00000000(rel)
        mov     byte ptr [rbp-1A5H], al                 ; 037C _ 88. 85, FFFFFE5B
        call    __ZN8AXWindow3runEv                     ; 0382 _ E8, 00000000(rel)
        mov     dword ptr [rbp-0C4H], eax               ; 0387 _ 89. 85, FFFFFF3C
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_015                                   ; 038D _ E9, 00000072

; Note: Inaccessible code
        mov     ecx, edx                                ; 0392 _ 89. D1
        mov     qword ptr [rbp-108H], rax               ; 0394 _ 48: 89. 85, FFFFFEF8
        mov     dword ptr [rbp-10CH], ecx               ; 039B _ 89. 8D, FFFFFEF4
        mov     rdi, qword ptr [rbp-170H]               ; 03A1 _ 48: 8B. BD, FFFFFE90
        call    __ZdlPv                                 ; 03A8 _ E8, 00000000(rel)
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_016                                   ; 03AD _ E9, 00000061

; Note: Inaccessible code
        mov     ecx, edx                                ; 03B2 _ 89. D1
        mov     qword ptr [rbp-108H], rax               ; 03B4 _ 48: 89. 85, FFFFFEF8
        mov     dword ptr [rbp-10CH], ecx               ; 03BB _ 89. 8D, FFFFFEF4
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_012                                   ; 03C1 _ E9, 0000001B

; Note: Inaccessible code
        lea     rdi, [rbp-138H]                         ; 03C6 _ 48: 8D. BD, FFFFFEC8
        mov     ecx, edx                                ; 03CD _ 89. D1
        mov     qword ptr [rbp-108H], rax               ; 03CF _ 48: 89. 85, FFFFFEF8
        mov     dword ptr [rbp-10CH], ecx               ; 03D6 _ 89. 8D, FFFFFEF4
        call    __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev; 03DC _ E8, 00000000(rel)
?_012:  test    byte ptr [rbp-139H], 01H                ; 03E1 _ F6. 85, FFFFFEC7, 01
; Note: Immediate operand could be made smaller by sign extension
        jne     ?_013                                   ; 03E8 _ 0F 85, 00000005
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_014                                   ; 03EE _ E9, 0000000C

?_013:  mov     rdi, qword ptr [rbp-180H]               ; 03F3 _ 48: 8B. BD, FFFFFE80
        call    __ZdlPv                                 ; 03FA _ E8, 00000000(rel)
?_014:
; Note: Immediate operand could be made smaller by sign extension
        jmp     ?_016                                   ; 03FF _ E9, 0000000F

?_015:  mov     eax, dword ptr [rbp-0C4H]               ; 0404 _ 8B. 85, FFFFFF3C
        add     rsp, 432                                ; 040A _ 48: 81. C4, 000001B0
        pop     rbp                                     ; 0411 _ 5D
        ret                                             ; 0412 _ C3

?_016:  mov     rdi, qword ptr [rbp-108H]               ; 0413 _ 48: 8B. BD, FFFFFEF8
        call    __Unwind_Resume                         ; 041A _ E8, 00000000(rel)
        nop                                             ; 041F _ 90
ALIGN   16

__ZNSt3__111char_traitsIcE6lengthEPKc LABEL NEAR
;  WEAK __ZNSt3__111char_traitsIcE6lengthEPKc
        push    rbp                                     ; 0420 _ 55
        mov     rbp, rsp                                ; 0421 _ 48: 89. E5
        sub     rsp, 16                                 ; 0424 _ 48: 83. EC, 10
        mov     qword ptr [rbp-8H], rdi                 ; 0428 _ 48: 89. 7D, F8
        mov     rdi, qword ptr [rbp-8H]                 ; 042C _ 48: 8B. 7D, F8
        call    _strlen                                 ; 0430 _ E8, 00000000(rel)
        add     rsp, 16                                 ; 0435 _ 48: 83. C4, 10
        pop     rbp                                     ; 0439 _ 5D
        ret                                             ; 043A _ C3
_main   ENDP

__TEXT.__text ENDS

__TEXT.__literal4 SEGMENT DWORD 'DATA'                  ; section number 2

Float_constants label dword
        dd 44340000H, 43F00000H                         ; 043C _ 720.0 480.0 
        dd 41200000H                                    ; 0444 _ 10.0 

__TEXT.__literal4 ENDS

__TEXT.__gcc_except_tab__TEXT SEGMENT DWORD 'DATA'      ; section number 3

GCC_except_table0 label byte
        db 0FFH, 9BH, 0F7H, 80H, 00H, 03H, 75H, 00H     ; 0448 _ ......u.
        db 00H, 00H, 00H, 40H, 01H, 00H, 00H, 00H       ; 0450 _ ...@....
        db 00H, 00H, 00H, 00H, 40H, 01H, 00H, 00H       ; 0458 _ ....@...
        db 3CH, 00H, 00H, 00H, 0CAH, 01H, 00H, 00H      ; 0460 _ <.......
        db 00H, 86H, 01H, 00H, 00H, 18H, 00H, 00H       ; 0468 _ ........
        db 00H, 0DEH, 01H, 00H, 00H, 00H, 9EH, 01H      ; 0470 _ ........
        db 00H, 00H, 7EH, 00H, 00H, 00H, 00H, 00H       ; 0478 _ ..~.....
        db 00H, 00H, 00H, 1CH, 02H, 00H, 00H, 16H       ; 0480 _ ........
        db 00H, 00H, 00H, 92H, 03H, 00H, 00H, 00H       ; 0488 _ ........
        db 32H, 02H, 00H, 00H, 82H, 00H, 00H, 00H       ; 0490 _ 2.......
        db 00H, 00H, 00H, 00H, 00H, 0B4H, 02H, 00H      ; 0498 _ ........
        db 00H, 4AH, 00H, 00H, 00H, 0B2H, 03H, 00H      ; 04A0 _ .J......
        db 00H, 00H, 08H, 03H, 00H, 00H, 3BH, 00H       ; 04A8 _ ......;.
        db 00H, 00H, 0C6H, 03H, 00H, 00H, 00H, 43H      ; 04B0 _ .......C
        db 03H, 00H, 00H, 0DCH, 00H, 00H, 00H, 00H      ; 04B8 _ ........
        db 00H, 00H, 00H, 00H                           ; 04C0 _ ....

__TEXT.__gcc_except_tab__TEXT ENDS

__TEXT.__cstring SEGMENT BYTE 'DATA'                    ; section number 4

        db 42H, 61H, 73H, 69H, 63H, 20H, 45H, 78H       ; 04C4 _ Basic Ex
        db 61H, 6DH, 70H, 6CH, 65H, 00H, 57H, 69H       ; 04CC _ ample.Wi
        db 6EH, 64H, 6FH, 77H, 20H, 66H, 61H, 69H       ; 04D4 _ ndow fai
        db 6CH, 65H, 64H, 20H, 74H, 6FH, 20H, 69H       ; 04DC _ led to i
        db 6EH, 69H, 74H, 69H, 61H, 6CH, 69H, 73H       ; 04E4 _ nitialis
        db 65H, 00H, 51H, 75H, 69H, 74H, 74H, 69H       ; 04EC _ e.Quitti
        db 6EH, 67H, 00H, 62H, 6CH, 6FH, 62H, 00H       ; 04F4 _ ng.blob.

__TEXT.__cstring ENDS

__LD.__compact_unwind__LD SEGMENT ALIGN(8) 'DATA'       ; section number 5

        dq _main                                        ; 0500 _ 0000000000000000 (d)
        dq 410000000000041FH                            ; 0508 _ 410000000000041F 
        dq ___gxx_personality_v0                        ; 0510 _ 0000000000000000 (d)
        dq _main+448H                                   ; 0518 _ 0000000000000448 (d)
        dq __ZNSt3__111char_traitsIcE6lengthEPKc        ; 0520 _ 0000000000000420 (d)
        dq 010000000000001BH                            ; 0528 _ 010000000000001B 
        dq 0000000000000000H                            ; 0530 _ 0000000000000000 
        dq 0000000000000000H                            ; 0538 _ 0000000000000000 

__LD.__compact_unwind__LD ENDS

__TEXT.__eh_frame SEGMENT ALIGN(8) 'DATA'               ; section number 6

        db 1CH, 00H, 00H, 00H, 00H, 00H, 00H, 00H       ; 0540 _ ........
        db 01H, 7AH, 50H, 4CH, 52H, 00H, 01H, 78H       ; 0548 _ .zPLR..x
        db 10H, 07H, 9BH                                ; 0550 _ ...
        dd ___gxx_personality_v0-$-13H                  ; 0553 _ 00000004 (GOT r)
        dd 070C1010H, 00019008H                         ; 0557 _ 118231056 102408 
        dd 00002C00H, 00002400H                         ; 055F _ 11264 9216 
        dd 0FFFA9800H, 0FFFFFFFFH                       ; 0567 _ -354304 -1 
        dd 00041FFFH, 00000000H                         ; 056F _ 270335 0 
        dd 0FECF0800H, 0FFFFFFFFH                       ; 0577 _ -19986432 -1 
        dd 0E41FFFFH, 43028610H                         ; 057F _ 239206399 1124238864 
        dd 0000060DH, 00000000H                         ; 0587 _ 1549 0 
        dd 00001400H, 00000000H                         ; 058F _ 5120 0 
        dd 527A0100H, 10780100H                         ; 0597 _ 1383727360 276300032 
        dd 070C1001H, 00019008H                         ; 059F _ 118231041 102408 
        dd 00002400H, 00001C00H                         ; 05A7 _ 9216 7168 
        dd 0FFFE7000H, 0FFFFFFFFH                       ; 05AF _ -102400 -1 
        dd 00001BFFH, 00000000H                         ; 05B7 _ 7167 0 
        dd 0E410000H, 43028610H                         ; 05BF _ 239140864 1124238864 
        dd 0000060DH, 00000000H                         ; 05C7 _ 1549 0 
        db 00H                                          ; 05CF _ .

__TEXT.__eh_frame ENDS

END