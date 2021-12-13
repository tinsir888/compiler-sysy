declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @fun(i32 %t4, i32 %t1){
B39:
  %t44 = alloca i32, align 4
  %t42 = alloca i32, align 4
  %t40 = alloca i32, align 4
  store i32 %t4, i32* %t40, align 4
  %t41 = load i32, i32* %t40, align 4
  store i32 %t1, i32* %t42, align 4
  %t43 = load i32, i32* %t42, align 4
  br label %B45
B45:                               	; preds = %B39, %B39, %B46
  %t48 = load i32, i32* %t40, align 4
  %t9 = icmp sgt i32 %t48, 0
  br i1 %t9, label %B46, label %B47
B46:                               	; preds = %B45, %B45
  %t49 = load i32, i32* %t42, align 4
  %t50 = load i32, i32* %t40, align 4
  %t13 = srem i32 %t49, %t50
  store i32 %t13, i32* %t44, align 4
  %t51 = load i32, i32* %t40, align 4
  store i32 %t51, i32* %t42, align 4
  %t52 = load i32, i32* %t44, align 4
  store i32 %t52, i32* %t40, align 4
  br label %B45
B47:                               	; preds = %B45, %B46, %B45
  %t53 = load i32, i32* %t42, align 4
  ret i32 %t53
}
define i32 @main() {
B54:
  %t57 = alloca i32, align 4
  %t56 = alloca i32, align 4
  %t55 = alloca i32, align 4
  %t58 = call i32 @getint()
  store i32 %t58, i32* %t56, align 4
  %t59 = call i32 @getint()
  store i32 %t59, i32* %t55, align 4
  %t61 = load i32, i32* %t56, align 4
  %t62 = load i32, i32* %t55, align 4
  %t60 = call i32 @fun(i32 %t62,i32 %t61)
  store i32 %t60, i32* %t57, align 4
  %t64 = load i32, i32* %t57, align 4
  call void( i32 ) @putint(i32 %t64)
  ret i32 0
}
