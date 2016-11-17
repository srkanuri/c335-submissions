  .text
  .syntax unified
  .thumb
  .global or
  .type or, %function
or:
	orrs 	r0, r1
	mov   	pc, lr
  .global and
  .type and, %function
and:
	ands  	r0, r1
	mov   	pc, lr
  .global plus
  .type plus, %function
plus:
	adds  	r0, r1
	mov   	pc, lr
  .global minus
  .type minus, %function
minus:
	subs  	r0, r1
	mov   	pc, lr
  .global neg
  .type neg, %function
neg:
	mov 	r1, r0
	neg  	r0, r1
	mov  	pc, lr
	.end
