  .text
  .syntax unified
  .thumb
  .global push
  .type push, %function
push:
	push  	{lr}
	mov 	r3, r0
	mov 	r0, #8
	bl  	malloc
	mov 	r2, r3
	str 	r2, [r0]
	ldr 	r1, .top
	ldr 	r2, [r1]
	mov 	r1, r0
	str 	r2, [r1, #4]
	ldr 	r1, .top
	mov 	r2, r0
	str 	r2, [r1]
	pop 	{pc}
.top:
	.word 	top
