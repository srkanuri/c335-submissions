  .text
  .syntax unified
  .thumb
  .global pop
  .type pop, %function
pop:
	push	{lr}
	bl	  empty
	cmp	  r0, #0
	beq	 .remove
	mov	r0, #1
	bl	throw_error
	b	.end
.remove:
	ldr	r1, .top
	ldr	r1, [r1]
	ldr	r2, [r1]
	mov	r3, r2
	mov	r0, r1
	ldr	r2, [r1, #4]
	ldr	r1, .top
	str	r2, [r1]
	bl	free
	mov	r0, r3
.end:
	pop	{pc}
.top:
	.word	top
