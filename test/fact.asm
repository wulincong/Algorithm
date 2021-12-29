;long fact_do(long n)
;n in %rdi

fact_do:
    movl    $1, %rax    ;set result = 1
  .L2:
    imulq   %rdi, %rax  ;result *= n
    subq    $1, %rdi
    cmpq    $1, %rdi    ;compare n:1
    jg      .L2
    rep;    ret

;long fact_while(long n)
;n in %rdi
fact_while:
    movl $1, %rax ;set result = 1
    jmp     .L5
  .L6:
    imulq %rdi, %rax ;
    subq $1, %rdi
  .L5:
    cmpq $1, %rdi
    jg      .L6
    rep; ret


;long fact_while(long n)
;n in %rdi
fact_while:
    cmpq    $1, %rdi
    jle     .L7
    movl    $1, %rax ;set result = 1
  .L6:
    imulq   %rdi, %rax ;
    subq    $1, %rdi
    cmpq    $1, %rdi
    jne     .L6
    rep; ret
  .L7:
    movl    $1, %rax    ;set result = 1
    rep