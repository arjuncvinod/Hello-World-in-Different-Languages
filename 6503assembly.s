; 64TASS
; hello.asm

KERNAL_CLEAR_SCREEN = $e544 ; KERNAL ROM routine.
VICSCN = $0400              ; VIC-II Screen Video Matrix, 1024 (int).


; BASIC loader.
*=$0801             ; The two byte load address at the start of the .PRG file.
    .byte $0b, $08  ; Linked list pointer to next line of BASIC.
    .byte $d9, $07  ; 2009 (int) line number (LO, HI).
    .byte $9e       ; BASIC SYS token.
    .text "2064"    ; Memory address (int) to start of ASM: $0810


; ASM code.
*=$0810 ; The start of ASM execution.

      jsr KERNAL_CLEAR_SCREEN

      ; Enter HELLO WORLD into screen memory ($0400-$07e7) (1024-2023).
      lda #8         ; 'H' Screen Code
      sta VICSCN + 0 ; 'H' in $0400 screen memory
            
      lda #5         ; 'E' Screen Code
      sta VICSCN + 1 ; 'E' in $0400+1 screen memory

      lda #12         ; 'L' Screen Code
      sta VICSCN + 2 ; 'L' in $0400+2 screen memory
      
      lda #12         ; 'L' Screen Code
      sta VICSCN + 3 ; 'L' in $0400+3 screen memory

      lda #15         ; 'O' Screen Code
      sta VICSCN + 4 ; 'O' in $0400+4 screen memory

      lda #32        ; ' ' Screen Code
      sta VICSCN + 5 ; ' ' in $0400+5 screen memory

      lda #23         ; 'W' Screen Code
      sta VICSCN + 6 ; 'W' in $0400+6 screen memory
      
      lda #15         ; 'O' Screen Code
      sta VICSCN + 7 ; 'O' in $0400+7 screen memory
      
      lda #18         ; 'R' Screen Code
      sta VICSCN + 8 ; 'R' in $0400+8 screen memory
      
      lda #12         ; 'L' Screen Code
      sta VICSCN + 9 ; 'L' in $0400+9 screen memory
      
      lda #4         ; 'D' Screen Code
      sta VICSCN + 10; 'D' in $0400+10 screen memory
      
      rts            ; All programs must end with Return To Subroutine (RTS).