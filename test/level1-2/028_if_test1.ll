declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @ifElse() {
B11:
  %t12 = alloca i32, align 4
  store i32 5, i32* %t12, align 4
  %t16 = load i32, i32* %t12, align 4
  %t4 = icmp eq i32 %t16, 5
  br i1 %t4, label %B13, label %B15
B13:                               	; preds = %B11, %B11
  store i32 25, i32* %t12, align 4
  br label %B14
B15:                               	; preds = %B13, %B11
  %t17 = load i32, i32* %t12, align 4
  %t8 = mul i32 %t17, 2
  store i32 %t8, i32* %t12, align 4
  br label %B14
B14:                               	; preds = %B15, %B13, %B15
  %t18 = load i32, i32* %t12, align 4
  ret i32 %t18
}
define i32 @main() {
B19:
  %t20 = call i32 @ifElse()
  ret i32 %t20
}
