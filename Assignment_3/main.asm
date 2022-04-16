.include "m328Pdef.inc"

Start:

	ldi r17, 0b11110000 	; identifying input pins 8,9,10,11
	out DDRB,r17		; declaring pins as input
	ldi r17, 0b11111111 	
	out PORTB,r17		; activating internal pullup for PORT B  
	in r17,PINB
	
	;21,22,23 and 24 are the inputs
	
	ldi r21,0b00000001
	and r21,r17 		;z
	lsr r17

	ldi r22,0b00000001
	and r22,r17 		;w
	lsr r17

	ldi r23,0b00000001
	and r23,r17 		;v
	lsr r17

	ldi r24,0b00000001
	and r24,r17 		;u

	;Mov all inputs to other registers
	mov r26,r21 		; z
	mov r27,r22 		; w
	mov r28,r23 		; v
	mov r29,r24 		; u

	;Compliment all the inputs   
	eor r21, r25 		; z'
	eor r22, r25 		; w'
	eor r23, r25 		; v'
	eor r24, r25 		; u'
	
				; G = WZ + VZ + UVW' + U'VW
	
	; WZ calculation
	mov r25, r27 		; duplicating w
	and r25, r26  		; r25(WZ) <- r25(W) & r26(Z) 

	; VZ calculation
	mov r16, r28
	and r16, r26 		; r16(VZ) <- r16(V) & r26(Z)

	; UVW'calculation r18 is unused and so is (r26)z after this point
	mov r26, r29 		; duplicating u
	and r26, r28 		; r26(UV) <- r26(U) & r28(V)
	and r26, r22 		; r26(UVW') <- r26(UV) & r22(W')

	; U'VW calculation
	mov r18, r28 		; duplicating V
	and r18, r27 		; r18(VW) <- r18(V) & r27(W)
	and r18, r24 		; r18(U'VW) <- r18(VW) & r24(U')
	
	or r25, r16 		; r25(WZ + VZ) <- r25(WZ) | r16(VZ)
	or r25, r26 		; r25(WZ + VZ + UVW') <- r25(WZ + VZ) | r26(UVW')
	or r25, r18 		; r25(WZ + VZ + UVW' + U'VW) <- r25(WZ + VZ + UVW') | r18(U'VW)
	


	ldi r16, 0b00000001 
	out DDRD,r16		; set pin 0 as output
	out PORTD, r25
	
	rjmp Start




