declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
  @g = dso_local global i32 0, align 4
  @h = dso_local global i32 0, align 4
  @f = dso_local global i32 0, align 4
  @e = dso_local global i32 0, align 4
define i32 @EightWhile() {
B101:
  %t105 = alloca i32, align 4
  %t104 = alloca i32, align 4
  %t103 = alloca i32, align 4
  %t102 = alloca i32, align 4
  store i32 5, i32* %t102, align 4
  store i32 6, i32* %t103, align 4
  store i32 7, i32* %t104, align 4
  store i32 10, i32* %t105, align 4
  br label %B106
B106:                               	; preds = %B101, %B101, %B113
  %t109 = load i32, i32* %t102, align 4
  %t21 = icmp slt i32 %t109, 20
  br i1 %t21, label %B107, label %B108
B111:                               	; preds = %B101, %B107, %B118
  %t114 = load i32, i32* %t103, align 4
  %t26 = icmp slt i32 %t114, 10
  br i1 %t26, label %B112, label %B113
B116:                               	; preds = %B101, %B112, %B123
  %t119 = load i32, i32* %t104, align 4
  %t31 = icmp eq i32 %t119, 7
  br i1 %t31, label %B117, label %B118
B121:                               	; preds = %B101, %B117, %B128
  %t124 = load i32, i32* %t105, align 4
  %t36 = icmp slt i32 %t124, 20
  br i1 %t36, label %B122, label %B123
B126:                               	; preds = %B101, %B122, %B133
  %t129 = load i32, i32* @e, align 4
  %t41 = icmp sgt i32 %t129, 1
  br i1 %t41, label %B127, label %B128
B131:                               	; preds = %B101, %B127, %B138
  %t134 = load i32, i32* @f, align 4
  %t46 = icmp sgt i32 %t134, 2
  br i1 %t46, label %B132, label %B133
B136:                               	; preds = %B101, %B132, %B143
  %t139 = load i32, i32* @g, align 4
  %t51 = icmp slt i32 %t139, 3
  br i1 %t51, label %B137, label %B138
B141:                               	; preds = %B101, %B137, %B142
  %t144 = load i32, i32* @h, align 4
  %t56 = icmp slt i32 %t144, 10
  br i1 %t56, label %B142, label %B143
B107:                               	; preds = %B106, %B106
  %t110 = load i32, i32* %t102, align 4
  %t24 = add i32 %t110, 3
  store i32 %t24, i32* %t102, align 4
  br label %B111
B108:                               	; preds = %B106, %B107, %B106
  %t153 = load i32, i32* %t102, align 4
  %t154 = load i32, i32* %t103, align 4
  %t155 = load i32, i32* %t105, align 4
  %t84 = add i32 %t154, %t155
  %t85 = add i32 %t153, %t84
  %t156 = load i32, i32* %t104, align 4
  %t87 = add i32 %t85, %t156
  %t157 = load i32, i32* @e, align 4
  %t158 = load i32, i32* %t105, align 4
  %t90 = add i32 %t157, %t158
  %t159 = load i32, i32* @g, align 4
  %t92 = sub i32 %t90, %t159
  %t160 = load i32, i32* @h, align 4
  %t94 = add i32 %t92, %t160
  %t95 = sub i32 %t87, %t94
  ret i32 %t95
B112:                               	; preds = %B111, %B111
  %t115 = load i32, i32* %t103, align 4
  %t29 = add i32 %t115, 1
  store i32 %t29, i32* %t103, align 4
  br label %B116
B113:                               	; preds = %B111, %B112, %B111
  %t152 = load i32, i32* %t103, align 4
  %t80 = sub i32 %t152, 2
  store i32 %t80, i32* %t103, align 4
  br label %B106
B117:                               	; preds = %B116, %B116
  %t120 = load i32, i32* %t104, align 4
  %t34 = sub i32 %t120, 1
  store i32 %t34, i32* %t104, align 4
  br label %B121
B118:                               	; preds = %B116, %B117, %B116
  %t151 = load i32, i32* %t104, align 4
  %t77 = add i32 %t151, 1
  store i32 %t77, i32* %t104, align 4
  br label %B111
B122:                               	; preds = %B121, %B121
  %t125 = load i32, i32* %t105, align 4
  %t39 = add i32 %t125, 3
  store i32 %t39, i32* %t105, align 4
  br label %B126
B123:                               	; preds = %B121, %B122, %B121
  %t150 = load i32, i32* %t105, align 4
  %t74 = sub i32 %t150, 1
  store i32 %t74, i32* %t105, align 4
  br label %B116
B127:                               	; preds = %B126, %B126
  %t130 = load i32, i32* @e, align 4
  %t44 = sub i32 %t130, 1
  store i32 %t44, i32* @e, align 4
  br label %B131
B128:                               	; preds = %B126, %B127, %B126
  %t149 = load i32, i32* @e, align 4
  %t71 = add i32 %t149, 1
  store i32 %t71, i32* @e, align 4
  br label %B121
B132:                               	; preds = %B131, %B131
  %t135 = load i32, i32* @f, align 4
  %t49 = sub i32 %t135, 2
  store i32 %t49, i32* @f, align 4
  br label %B136
B133:                               	; preds = %B131, %B132, %B131
  %t148 = load i32, i32* @f, align 4
  %t68 = add i32 %t148, 1
  store i32 %t68, i32* @f, align 4
  br label %B126
B137:                               	; preds = %B136, %B136
  %t140 = load i32, i32* @g, align 4
  %t54 = add i32 %t140, 10
  store i32 %t54, i32* @g, align 4
  br label %B141
B138:                               	; preds = %B136, %B137, %B136
  %t147 = load i32, i32* @g, align 4
  %t65 = sub i32 %t147, 8
  store i32 %t65, i32* @g, align 4
  br label %B131
B142:                               	; preds = %B141, %B141
  %t145 = load i32, i32* @h, align 4
  %t59 = add i32 %t145, 8
  store i32 %t59, i32* @h, align 4
  br label %B141
B143:                               	; preds = %B141, %B142, %B141
  %t146 = load i32, i32* @h, align 4
  %t62 = sub i32 %t146, 1
  store i32 %t62, i32* @h, align 4
  br label %B136
}
define i32 @main() {
B161:
  store i32 1, i32* @g, align 4
  store i32 2, i32* @h, align 4
  store i32 4, i32* @e, align 4
  store i32 6, i32* @f, align 4
  %t162 = call i32 @EightWhile()
  ret i32 %t162
}
