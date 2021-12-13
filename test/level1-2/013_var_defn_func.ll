declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
define i32 @defn() {
B4:
  ret i32 4
}
define i32 @main() {
B5:
  %t6 = alloca i32, align 4
  %t7 = call i32 @defn()
  store i32 %t7, i32* %t6, align 4
  %t8 = load i32, i32* %t6, align 4
  ret i32 %t8
}
