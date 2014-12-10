
;; trying to make the smallest executable
;; http://www.muppetlabs.com/~breadbox/software/tiny/teensy.html
;;   nasm -f elf tiny.asm

GLOBAL main
SECTION .text
main:
        mov     eax, 42
        ret
