	.build_version macos, 26, 0	sdk_version 27, 0
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_print_binary                   ; -- Begin function print_binary
	.p2align	2
_print_binary:                          ; @print_binary
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x22, x21, [sp, #16]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #32]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	mov	x19, x0
	mov	w21, #31                        ; =0x1f
Lloh0:
	adrp	x20, l_.str@PAGE
Lloh1:
	add	x20, x20, l_.str@PAGEOFF
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	lsr	w8, w19, w21
	and	w8, w8, #0x1
	str	x8, [sp]
	mov	x0, x20
	bl	_printf
	sub	w21, w21, #1
	cmn	w21, #1
	b.ne	LBB0_1
; %bb.2:
	mov	w0, #10                         ; =0xa
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #32]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #64
	b	_putchar
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.globl	_set_bit                        ; -- Begin function set_bit
	.p2align	2
_set_bit:                               ; @set_bit
	.cfi_startproc
; %bb.0:
	mov	w8, #1                          ; =0x1
	lsl	w8, w8, w1
	orr	w0, w8, w0
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_clear_bit                      ; -- Begin function clear_bit
	.p2align	2
_clear_bit:                             ; @clear_bit
	.cfi_startproc
; %bb.0:
	mov	w8, #1                          ; =0x1
	lsl	w8, w8, w1
	bic	w0, w0, w8
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_toggle_bit                     ; -- Begin function toggle_bit
	.p2align	2
_toggle_bit:                            ; @toggle_bit
	.cfi_startproc
; %bb.0:
	mov	w8, #1                          ; =0x1
	lsl	w8, w8, w1
	eor	w0, w8, w0
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_field                      ; -- Begin function get_field
	.p2align	2
_get_field:                             ; @get_field
	.cfi_startproc
; %bb.0:
	mov	w8, #-1                         ; =0xffffffff
	lsl	w9, w8, w2
	cmp	w2, #32
	csinv	w8, w8, w9, eq
	lsr	w9, w0, w1
	and	w0, w8, w9
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_popcount                       ; -- Begin function popcount
	.p2align	2
_popcount:                              ; @popcount
	.cfi_startproc
; %bb.0:
	mov	x8, x0
	mov	w0, #0                          ; =0x0
	mov	w9, #31                         ; =0x1f
LBB5_1:                                 ; =>This Inner Loop Header: Depth=1
	lsr	w10, w8, w9
	and	w10, w10, #0x1
	add	w0, w10, w0
	sub	w9, w9, #1
	cmn	w9, #1
	b.ne	LBB5_1
; %bb.2:
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_set_field                      ; -- Begin function set_field
	.p2align	2
_set_field:                             ; @set_field
	.cfi_startproc
; %bb.0:
	mov	w8, #-1                         ; =0xffffffff
	lsl	w9, w8, w2
	cmp	w2, #32
	csinv	w8, w8, w9, eq
	and	w9, w8, w3
	lsl	w8, w8, w1
	bic	w8, w0, w8
	lsl	w9, w9, w1
	orr	w0, w8, w9
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d"

.subsections_via_symbols
