section .text
bits 64

global accelerationcalculator

accelerationcalculator:

                                ; xmmm0: vi
                                ; xmm1 : vf
                                ; xmm2 : time
    push rbp
    mov rbp, rsp
    sub rsp, 32                 ; stack space
    
    mov dword [rsp], 0x3E8E38E4 ; .277778 in single-precision hex

    movss xmm3, [rsp]           ; xmm3 = .277778
    movss xmm4, xmm0            ; xmm4 = vi
    movss xmm5, xmm1            ; xmm5 = vf

    mulss xmm4, xmm3            ; convert vi from km/h to m/s  
    mulss xmm5, xmm3            ; convert vf from km/h to m/s

    subss xmm5, xmm4            ; velocity difference // vf-vi

    divss xmm5, xmm2            ; acceleration // (vf - vi)/time

    cvttss2si eax, xmm5         ; convert to integer
    
    add rsp, 32                 ;cleaning stack space
    pop rbp
    ret
