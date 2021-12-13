declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @FourWhile() {
B49:
  %t53 = alloca i32, align 4
  %t52 = alloca i32, align 4
  %t51 = alloca i32, align 4
  %t50 = alloca i32, align 4
  store i32 5, i32* %t50, align 4
  store i32 6, i32* %t51, align 4
  store i32 7, i32* %t52, align 4
  store i32 10, i32* %t53, align 4
  br label %B54
B54:                               	; preds = %B49, %B49, %B61
  %t57 = load i32, i32* %t50, align 4
  %t13 = icmp slt i32 %t57, 20
  br i1 %t13, label %B55, label %B56
B59:                               	; preds = %B49, %B55, %B66
  %t62 = load i32, i32* %t51, align 4
  %t18 = icmp slt i32 %t62, 10
  br i1 %t18, label %B60, label %B61
B64:                               	; preds = %B49, %B60, %B71
  %t67 = load i32, i32* %t52, align 4
  %t23 = icmp eq i32 %t67, 7
  br i1 %t23, label %B65, label %B66
B69:                               	; preds = %B49, %B65, %B70
  %t72 = load i32, i32* %t53, align 4
  %t28 = icmp slt i32 %t72, 20
  br i1 %t28, label %B70, label %B71
B55:                               	; preds = %B54, %B54
  %t58 = load i32, i32* %t50, align 4
  %t16 = add i32 %t58, 3
  store i32 %t16, i32* %t50, align 4
  br label %B59
B56:                               	; preds = %B54, %B55, %B54
  %t77 = load i32, i32* %t50, align 4
  %t78 = load i32, i32* %t51, align 4
  %t79 = load i32, i32* %t53, align 4
  %t44 = add i32 %t78, %t79
  %t45 = add i32 %t77, %t44
  %t80 = load i32, i32* %t52, align 4
  %t47 = add i32 %t45, %t80
  ret i32 %t47
B60:                               	; preds = %B59, %B59
  %t63 = load i32, i32* %t51, align 4
  %t21 = add i32 %t63, 1
  store i32 %t21, i32* %t51, align 4
  br label %B64
B61:                               	; preds = %B59, %B60, %B59
  %t76 = load i32, i32* %t51, align 4
  %t40 = sub i32 %t76, 2
  store i32 %t40, i32* %t51, align 4
  br label %B54
B65:                               	; preds = %B64, %B64
  %t68 = load i32, i32* %t52, align 4
  %t26 = sub i32 %t68, 1
  store i32 %t26, i32* %t52, align 4
  br label %B69
B66:                               	; preds = %B64, %B65, %B64
  %t75 = load i32, i32* %t52, align 4
  %t37 = add i32 %t75, 1
  store i32 %t37, i32* %t52, align 4
  br label %B59
B70:                               	; preds = %B69, %B69
  %t73 = load i32, i32* %t53, align 4
  %t31 = add i32 %t73, 3
  store i32 %t31, i32* %t53, align 4
  br label %B69
B71:                               	; preds = %B69, %B70, %B69
  %t74 = load i32, i32* %t53, align 4
  %t34 = sub i32 %t74, 1
  store i32 %t34, i32* %t53, align 4
  br label %B64
}
define i32 @main() {
B81:
  %t82 = call i32 @FourWhile()
  ret i32 %t82
}
