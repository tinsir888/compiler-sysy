declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @ififElse() {
B16:
  %t18 = alloca i32, align 4
  %t17 = alloca i32, align 4
  store i32 5, i32* %t17, align 4
  store i32 10, i32* %t18, align 4
  %t21 = load i32, i32* %t17, align 4
  %t7 = icmp eq i32 %t21, 5
  br i1 %t7, label %B19, label %B20
B19:                               	; preds = %B16, %B16
  %t25 = load i32, i32* %t18, align 4
  %t9 = icmp eq i32 %t25, 10
  br i1 %t9, label %B22, label %B24
B22:                               	; preds = %B16, %B19
  store i32 25, i32* %t17, align 4
  br label %B23
B20:                               	; preds = %B19, %B16, %B23
  %t27 = load i32, i32* %t17, align 4
  ret i32 %t27
B24:                               	; preds = %B22, %B19
  %t26 = load i32, i32* %t17, align 4
  %t13 = add i32 %t26, 15
  store i32 %t13, i32* %t17, align 4
  br label %B23
B23:                               	; preds = %B24, %B22, %B24
  br label %B20
}
define i32 @main() {
B28:
  %t29 = call i32 @ififElse()
  ret i32 %t29
}
