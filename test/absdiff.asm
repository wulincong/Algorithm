; long adsdiff_se(long x, long y)
; x in %rdi, y in %rsi

absdiff_se: 
    cmpq    %rsi, %rdi          ;Compare x:y x-y
    jge     .L2                 ;if x-y>=0 goto x_ge_y
    addq    $1, lt_cnt(%rip)    ;lt_cnt++
    movq    %rsi, %rax
    subq    %rdi, %rax          ;result = y - x
    ret
  .L2:
    addq $1, ge_cnt(%rip)
    movq    %rdi, %rax
    subq    %rsi, %rax          ;return x - y
    ret



