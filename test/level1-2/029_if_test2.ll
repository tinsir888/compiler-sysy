declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @ifElseIf() {
B35:
  %t37 = alloca i32, align 4
  %t36 = alloca i32, align 4
  store i32 5, i32* %t36, align 4
  store i32 10, i32* %t37, align 4
  %t42 = load i32, i32* %t36, align 4
  %t7 = icmp eq i32 %t42, 6
  br i1 %t7, label %B38, label %B41
B38:                               	; preds = %B35, %B35, %B41
  %t44 = load i32, i32* %t36, align 4
  ret i32 %t44
  br label %B39
B45:                               	; preds = %B35, %B48
  store i32 25, i32* %t36, align 4
  br label %B46
B51:                               	; preds = %B35, %B54
  %t57 = load i32, i32* %t36, align 4
  %t26 = add i32 %t57, 15
  store i32 %t26, i32* %t36, align 4
  br label %B52
B41:                               	; preds = %B35
  %t43 = load i32, i32* %t37, align 4
  %t9 = icmp eq i32 %t43, 11
  br i1 %t9, label %B38, label %B40
B40:                               	; preds = %B38, %B41
  %t49 = load i32, i32* %t37, align 4
  %t13 = icmp eq i32 %t49, 10
  br i1 %t13, label %B48, label %B47
B39:                               	; preds = %B40, %B38, %B46
  %t59 = load i32, i32* %t36, align 4
  ret i32 %t59
B47:                               	; preds = %B45, %B40, %B48
  %t55 = load i32, i32* %t37, align 4
  %t19 = icmp eq i32 %t55, 10
  br i1 %t19, label %B54, label %B53
B46:                               	; preds = %B47, %B45, %B52
  br label %B39
B53:                               	; preds = %B51, %B47, %B54
  %t58 = load i32, i32* %t36, align 4
  %t29 = add i32 0, %t58
  %t30 = sub i32 0, %t29
  store i32 %t30, i32* %t36, align 4
  br label %B52
B52:                               	; preds = %B53, %B51, %B53
  br label %B46
B48:                               	; preds = %B40
  %t50 = load i32, i32* %t36, align 4
  %t15 = icmp eq i32 %t50, 1
  br i1 %t15, label %B45, label %B47
B54:                               	; preds = %B47
  %t56 = load i32, i32* %t36, align 4
  %t21 = sub i32 0, 5
  %t22 = icmp eq i32 %t56, %t21
  br i1 %t22, label %B51, label %B53
}
define i32 @main() {
B60:
  %t62 = call i32 @ifElseIf()
  call void( i32 ) @putint(i32 %t62)
  ret i32 0
}
