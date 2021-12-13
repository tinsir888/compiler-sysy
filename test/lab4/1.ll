declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
  @a = dso_local global i32 0, align 4
define i32 @main() {
B8:
  %t9 = alloca i32, align 4
  %t5 = add i32 1, 2
  store i32 %t5, i32* %t9, align 4
  %t12 = load i32, i32* %t9, align 4
  %t7 = icmp slt i32 %t12, 5
  br i1 %t7, label %B10, label %B11
B10:                               	; preds = %B8, %B8
  ret i32 1
  br label %B11
B11:                               	; preds = %B10, %B8, %B10
  ret i32 0
}
