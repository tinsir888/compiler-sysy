declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @deepWhileBr(i32 %t4, i32 %t1){
B43:
  %t64 = alloca i32, align 4
  %t55 = alloca i32, align 4
  %t48 = alloca i32, align 4
  %t46 = alloca i32, align 4
  %t44 = alloca i32, align 4
  store i32 %t4, i32* %t44, align 4
  %t45 = load i32, i32* %t44, align 4
  store i32 %t1, i32* %t46, align 4
  %t47 = load i32, i32* %t46, align 4
  %t49 = load i32, i32* %t46, align 4
  %t50 = load i32, i32* %t44, align 4
  %t11 = add i32 %t49, %t50
  store i32 %t11, i32* %t48, align 4
  br label %B51
B51:                               	; preds = %B43, %B43, %B57
  %t54 = load i32, i32* %t48, align 4
  %t13 = icmp slt i32 %t54, 75
  br i1 %t13, label %B52, label %B53
B56:                               	; preds = %B43, %B52
  %t59 = load i32, i32* %t48, align 4
  %t60 = load i32, i32* %t55, align 4
  %t22 = add i32 %t59, %t60
  store i32 %t22, i32* %t48, align 4
  %t63 = load i32, i32* %t48, align 4
  %t24 = icmp sgt i32 %t63, 99
  br i1 %t24, label %B61, label %B62
B61:                               	; preds = %B43, %B56
  %t65 = load i32, i32* %t55, align 4
  %t29 = mul i32 %t65, 2
  store i32 %t29, i32* %t64, align 4
  %t30 = icmp eq i32 1, 1
  br i1 %t30, label %B66, label %B67
B66:                               	; preds = %B43, %B61
  %t68 = load i32, i32* %t64, align 4
  %t33 = mul i32 %t68, 2
  store i32 %t33, i32* %t48, align 4
  br label %B67
B52:                               	; preds = %B51, %B51
  store i32 42, i32* %t55, align 4
  %t58 = load i32, i32* %t48, align 4
  %t18 = icmp slt i32 %t58, 100
  br i1 %t18, label %B56, label %B57
B53:                               	; preds = %B51, %B52, %B51
  %t69 = load i32, i32* %t48, align 4
  ret i32 %t69
B57:                               	; preds = %B56, %B52, %B62
  br label %B51
B62:                               	; preds = %B61, %B56, %B67
  br label %B57
B67:                               	; preds = %B66, %B61, %B66
  br label %B62
}
define i32 @main() {
B70:
  %t71 = alloca i32, align 4
  store i32 2, i32* %t71, align 4
  %t73 = load i32, i32* %t71, align 4
  %t74 = load i32, i32* %t71, align 4
  %t72 = call i32 @deepWhileBr(i32 %t74,i32 %t73)
  ret i32 %t72
}
