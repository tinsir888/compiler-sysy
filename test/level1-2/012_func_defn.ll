declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
  @a = dso_local global i32 0, align 4
define i32 @func(i32 %t3){
B17:
  %t18 = alloca i32, align 4
  store i32 %t3, i32* %t18, align 4
  %t19 = load i32, i32* %t18, align 4
  %t20 = load i32, i32* %t18, align 4
  %t7 = sub i32 %t20, 1
  store i32 %t7, i32* %t18, align 4
  %t21 = load i32, i32* %t18, align 4
  ret i32 %t21
}
define i32 @main() {
B22:
  %t23 = alloca i32, align 4
  store i32 10, i32* @a, align 4
  %t25 = load i32, i32* @a, align 4
  %t24 = call i32 @func(i32 %t25)
  store i32 %t24, i32* %t23, align 4
  %t26 = load i32, i32* %t23, align 4
  ret i32 %t26
}
