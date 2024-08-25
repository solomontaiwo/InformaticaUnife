.data
    myDouble: .double 7.202
    zeroDouble: .double 0.0

.text
    li $v0, 3
    ldc1 $f12, myDouble
    syscall