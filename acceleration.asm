;assembly part using x86-64

section .data
meters	dd 1000.0 ;1 km = 1000 meters
secs	dd 3600.0 ;1 hr = 3600 seconds

section .text
bits 64
default rel

global accelerationcalculator

; NOTE:
; xmm0 = vi
; xmm1 = vf
; xmm2 = time

accelerationcalculator:
	
	;--- (vf - vi) / time ---
	subss xmm1, xmm0
	divss xmm1, xmm2
	
	;--- convert to m/s ---
	movss xmm3, dword [meters]
	movss xmm4, dword [secs]
	divss xmm3, xmm4 ; 1000 / 3600
	mulss xmm1, xmm3 ; ((vi - vf) / time) * (1000/3600)

	;--- convert to int ---
	cvtss2si eax, xmm1 

	ret