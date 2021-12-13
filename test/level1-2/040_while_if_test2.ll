declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @ifWhile() {
B26:
  %t28 = alloca i32, align 4
  %t27 = alloca i32, align 4
  store i32 0, i32* %t27, align 4
  store i32 3, i32* %t28, align 4
  %t32 = load i32, i32* %t27, align 4
  %t7 = icmp eq i32 %t32, 5
  br i1 %t7, label %B29, label %B31
B29:                               	; preds = %B26, %B26
  br label %B33
B33:                               	; preds = %B26, %B29, %B34
  %t36 = load i32, i32* %t28, align 4
  %t9 = icmp eq i32 %t36, 2
  br i1 %t9, label %B34, label %B35
B39:                               	; preds = %B26, %B31, %B40
  %t42 = load i32, i32* %t27, align 4
  %t17 = icmp slt i32 %t42, 5
  br i1 %t17, label %B40, label %B41
B31:                               	; preds = %B29, %B26
  br label %B39
B34:                               	; preds = %B33, %B33
  %t37 = load i32, i32* %t28, align 4
  %t12 = add i32 %t37, 2
  store i32 %t12, i32* %t28, align 4
  br label %B33
B35:                               	; preds = %B33, %B34, %B33
  %t38 = load i32, i32* %t28, align 4
  %t15 = add i32 %t38, 25
  store i32 %t15, i32* %t28, align 4
  br label %B30
B40:                               	; preds = %B39, %B39
  %t43 = load i32, i32* %t28, align 4
  %t20 = mul i32 %t43, 2
  store i32 %t20, i32* %t28, align 4
  %t44 = load i32, i32* %t27, align 4
  %t23 = add i32 %t44, 1
  store i32 %t23, i32* %t27, align 4
  br label %B39
B41:                               	; preds = %B39, %B40, %B39
  br label %B30
B30:                               	; preds = %B31, %B35, %B41
  %t45 = load i32, i32* %t28, align 4
  ret i32 %t45
}
define i32 @main() {
B46:
  %t47 = call i32 @ifWhile()
  ret i32 %t47
}
