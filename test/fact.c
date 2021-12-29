
long fact_do(int n){
    long result = 1;
    do {
        result = result * n;
        n = n-1;
    }
    while (n > 0);
    return result;
}

long fact_do_goto(int n){
    long result = 1;
  LOOP:
    result *= n;
    n = n-1;
    if(n>1)
        goto LOOP;
    return result;
}

long fact_while(long n){
    long result = 1;
    while(n > 1){
        result *= n;
        n--;
    }
    return result;
}

long fact_while_jm_goto(long n){
    long result = 1;
    goto test;
  loop:
    result *= n;
    n--;  
  test:
    if(n>1) goto loop; 
    return result;
}

long fact_while_gd_goto(long n){
    long result = 1;
    if(n <= 1) goto done;
  loop:
    result *= n;
    n --;
    if(n != 1) goto loop;
  done:
    return result;
}