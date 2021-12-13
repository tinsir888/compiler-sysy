declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @whileIf() {
B22:
  %t24 = alloca i32, align 4
  %t23 = alloca i32, align 4
  store i32 0, i32* %t23, align 4
  store i32 0, i32* %t24, align 4
  br label %B25
B25:                               	; preds = %B22, %B22, %B30
  %t28 = load i32, i32* %t23, align 4
  %t7 = icmp slt i32 %t28, 100
  br i1 %t7, label %B26, label %B27
B29:                               	; preds = %B22, %B26
  store i32 25, i32* %t24, align 4
  br label %B30
B33:                               	; preds = %B22, %B31
  store i32 42, i32* %t24, align 4
  br label %B34
B26:                               	; preds = %B25, %B25
  %t32 = load i32, i32* %t23, align 4
  %t9 = icmp eq i32 %t32, 5
  br i1 %t9, label %B29, label %B31
B27:                               	; preds = %B25, %B26, %B25
  %t39 = load i32, i32* %t24, align 4
  ret i32 %t39
B31:                               	; preds = %B29, %B26
  %t36 = load i32, i32* %t23, align 4
  %t12 = icmp eq i32 %t36, 10
  br i1 %t12, label %B33, label %B35
B30:                               	; preds = %B31, %B29, %B34
  %t38 = load i32, i32* %t23, align 4
  %t19 = add i32 %t38, 1
  store i32 %t19, i32* %t23, align 4
  br label %B25
B35:                               	; preds = %B33, %B31
  %t37 = load i32, i32* %t23, align 4
  %t16 = mul i32 %t37, 2
  store i32 %t16, i32* %t24, align 4
  br label %B34
B34:                               	; preds = %B35, %B33, %B35
  br label %B30
}
define i32 @main() {
B40:
  %t41 = call i32 @whileIf()
  ret i32 %t41
}
