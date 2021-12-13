declare void @putint(i32)
declare void @putch(i32)
declare i32 @getint() 
declare i32 @getch()
  @s = dso_local global i32 0, align 4
define i32 @get_ans_se(i32 %t9, i32 %t6, i32 %t3){
B277:
  %t284 = alloca i32, align 4
  %t282 = alloca i32, align 4
  %t280 = alloca i32, align 4
  %t278 = alloca i32, align 4
  store i32 %t9, i32* %t278, align 4
  %t279 = load i32, i32* %t278, align 4
  store i32 %t6, i32* %t280, align 4
  %t281 = load i32, i32* %t280, align 4
  store i32 %t3, i32* %t282, align 4
  %t283 = load i32, i32* %t282, align 4
  store i32 0, i32* %t284, align 4
  %t287 = load i32, i32* %t280, align 4
  %t288 = load i32, i32* %t278, align 4
  %t15 = icmp eq i32 %t287, %t288
  br i1 %t15, label %B285, label %B286
B285:                               	; preds = %B277, %B277
  store i32 1, i32* %t284, align 4
  br label %B286
B286:                               	; preds = %B285, %B277, %B285
  %t289 = load i32, i32* %t282, align 4
  %t19 = mul i32 %t289, 2
  store i32 %t19, i32* %t282, align 4
  %t290 = load i32, i32* %t282, align 4
  %t291 = load i32, i32* %t284, align 4
  %t23 = add i32 %t290, %t291
  store i32 %t23, i32* %t282, align 4
  %t292 = load i32, i32* @s, align 4
  %t293 = load i32, i32* %t282, align 4
  %t27 = add i32 %t292, %t293
  store i32 %t27, i32* @s, align 4
  %t294 = load i32, i32* %t282, align 4
  ret i32 %t294
}
define i32 @get_ans(i32 %t36, i32 %t33, i32 %t30){
B295:
  %t302 = alloca i32, align 4
  %t300 = alloca i32, align 4
  %t298 = alloca i32, align 4
  %t296 = alloca i32, align 4
  store i32 %t36, i32* %t296, align 4
  %t297 = load i32, i32* %t296, align 4
  store i32 %t33, i32* %t298, align 4
  %t299 = load i32, i32* %t298, align 4
  store i32 %t30, i32* %t300, align 4
  %t301 = load i32, i32* %t300, align 4
  store i32 0, i32* %t302, align 4
  %t305 = load i32, i32* %t298, align 4
  %t306 = load i32, i32* %t296, align 4
  %t42 = icmp eq i32 %t305, %t306
  br i1 %t42, label %B303, label %B304
B303:                               	; preds = %B295, %B295
  store i32 1, i32* %t302, align 4
  br label %B304
B304:                               	; preds = %B303, %B295, %B303
  %t307 = load i32, i32* %t300, align 4
  %t46 = mul i32 %t307, 2
  store i32 %t46, i32* %t300, align 4
  %t308 = load i32, i32* %t300, align 4
  %t309 = load i32, i32* %t302, align 4
  %t50 = add i32 %t308, %t309
  store i32 %t50, i32* %t300, align 4
  %t310 = load i32, i32* %t300, align 4
  ret i32 %t310
}
define i32 @main() {
B311:
  %t320 = alloca i32, align 4
  %t319 = alloca i32, align 4
  %t318 = alloca i32, align 4
  %t317 = alloca i32, align 4
  %t316 = alloca i32, align 4
  %t315 = alloca i32, align 4
  %t314 = alloca i32, align 4
  %t313 = alloca i32, align 4
  %t312 = alloca i32, align 4
  %t52 = sub i32 0, -2147483648
  store i32 %t52, i32* %t312, align 4
  store i32 -2147483648, i32* %t313, align 4
  %t57 = add i32 -2147483648, 1
  store i32 %t57, i32* %t314, align 4
  store i32 2147483647, i32* %t315, align 4
  %t62 = sub i32 2147483647, 1
  store i32 %t62, i32* %t316, align 4
  %t322 = load i32, i32* %t312, align 4
  %t323 = load i32, i32* %t313, align 4
  %t321 = call i32 @get_ans(i32 %t323,i32 %t322,i32 0)
  store i32 %t321, i32* %t317, align 4
  %t325 = load i32, i32* %t317, align 4
  %t326 = load i32, i32* %t312, align 4
  %t87 = add i32 %t326, 1
  %t327 = load i32, i32* %t314, align 4
  %t324 = call i32 @get_ans(i32 %t327,i32 %t87,i32 %t325)
  store i32 %t324, i32* %t317, align 4
  %t329 = load i32, i32* %t317, align 4
  %t330 = load i32, i32* %t312, align 4
  %t331 = load i32, i32* %t315, align 4
  %t98 = sub i32 0, %t331
  %t99 = sub i32 %t98, 1
  %t328 = call i32 @get_ans(i32 %t99,i32 %t330,i32 %t329)
  store i32 %t328, i32* %t317, align 4
  %t333 = load i32, i32* %t317, align 4
  %t334 = load i32, i32* %t312, align 4
  %t335 = load i32, i32* %t316, align 4
  %t108 = add i32 %t335, 1
  %t332 = call i32 @get_ans(i32 %t108,i32 %t334,i32 %t333)
  store i32 %t332, i32* %t317, align 4
  %t337 = load i32, i32* %t317, align 4
  %t338 = load i32, i32* %t313, align 4
  %t115 = sdiv i32 %t338, 2
  %t339 = load i32, i32* %t314, align 4
  %t118 = sdiv i32 %t339, 2
  %t336 = call i32 @get_ans(i32 %t118,i32 %t115,i32 %t337)
  store i32 %t336, i32* %t317, align 4
  %t341 = load i32, i32* %t317, align 4
  %t342 = load i32, i32* %t313, align 4
  %t343 = load i32, i32* %t315, align 4
  %t127 = sub i32 0, %t343
  %t128 = sub i32 %t127, 1
  %t340 = call i32 @get_ans(i32 %t128,i32 %t342,i32 %t341)
  store i32 %t340, i32* %t317, align 4
  %t345 = load i32, i32* %t317, align 4
  %t346 = load i32, i32* %t313, align 4
  %t347 = load i32, i32* %t316, align 4
  %t137 = add i32 %t347, 1
  %t344 = call i32 @get_ans(i32 %t137,i32 %t346,i32 %t345)
  store i32 %t344, i32* %t317, align 4
  %t349 = load i32, i32* %t314, align 4
  %t350 = load i32, i32* %t315, align 4
  %t348 = call i32 @get_ans(i32 %t350,i32 %t349,i32 0)
  store i32 %t348, i32* %t318, align 4
  %t352 = load i32, i32* %t318, align 4
  %t353 = load i32, i32* %t314, align 4
  %t354 = load i32, i32* %t316, align 4
  %t351 = call i32 @get_ans(i32 %t354,i32 %t353,i32 %t352)
  store i32 %t351, i32* %t318, align 4
  %t356 = load i32, i32* %t318, align 4
  %t357 = load i32, i32* %t315, align 4
  %t358 = load i32, i32* %t316, align 4
  %t355 = call i32 @get_ans(i32 %t358,i32 %t357,i32 %t356)
  store i32 %t355, i32* %t318, align 4
  %t360 = load i32, i32* %t318, align 4
  %t361 = load i32, i32* %t312, align 4
  %t167 = sdiv i32 %t361, 2
  %t362 = load i32, i32* %t313, align 4
  %t170 = sdiv i32 %t362, 2
  %t359 = call i32 @get_ans(i32 %t170,i32 %t167,i32 %t360)
  store i32 %t359, i32* %t318, align 4
  %t364 = load i32, i32* %t312, align 4
  %t365 = load i32, i32* %t313, align 4
  %t363 = call i32 @get_ans_se(i32 %t365,i32 %t364,i32 0)
  store i32 %t363, i32* %t319, align 4
  %t367 = load i32, i32* %t319, align 4
  %t368 = load i32, i32* %t312, align 4
  %t184 = add i32 %t368, 1
  %t369 = load i32, i32* %t314, align 4
  %t366 = call i32 @get_ans_se(i32 %t369,i32 %t184,i32 %t367)
  store i32 %t366, i32* %t319, align 4
  %t371 = load i32, i32* %t319, align 4
  %t372 = load i32, i32* %t312, align 4
  %t373 = load i32, i32* %t315, align 4
  %t195 = sub i32 0, %t373
  %t196 = sub i32 %t195, 1
  %t370 = call i32 @get_ans_se(i32 %t196,i32 %t372,i32 %t371)
  store i32 %t370, i32* %t319, align 4
  %t375 = load i32, i32* %t319, align 4
  %t376 = load i32, i32* %t312, align 4
  %t377 = load i32, i32* %t316, align 4
  %t205 = add i32 %t377, 1
  %t374 = call i32 @get_ans_se(i32 %t205,i32 %t376,i32 %t375)
  store i32 %t374, i32* %t319, align 4
  %t379 = load i32, i32* %t319, align 4
  %t380 = load i32, i32* %t313, align 4
  %t212 = sdiv i32 %t380, 2
  %t381 = load i32, i32* %t314, align 4
  %t215 = sdiv i32 %t381, 2
  %t378 = call i32 @get_ans_se(i32 %t215,i32 %t212,i32 %t379)
  store i32 %t378, i32* %t319, align 4
  %t383 = load i32, i32* %t319, align 4
  %t384 = load i32, i32* %t313, align 4
  %t385 = load i32, i32* %t315, align 4
  %t224 = sub i32 0, %t385
  %t225 = sub i32 %t224, 1
  %t382 = call i32 @get_ans_se(i32 %t225,i32 %t384,i32 %t383)
  store i32 %t382, i32* %t319, align 4
  %t387 = load i32, i32* %t319, align 4
  %t388 = load i32, i32* %t313, align 4
  %t389 = load i32, i32* %t316, align 4
  %t234 = add i32 %t389, 1
  %t386 = call i32 @get_ans_se(i32 %t234,i32 %t388,i32 %t387)
  store i32 %t386, i32* %t319, align 4
  %t391 = load i32, i32* %t314, align 4
  %t392 = load i32, i32* %t315, align 4
  %t390 = call i32 @get_ans_se(i32 %t392,i32 %t391,i32 0)
  store i32 %t390, i32* %t320, align 4
  %t394 = load i32, i32* %t320, align 4
  %t395 = load i32, i32* %t314, align 4
  %t396 = load i32, i32* %t316, align 4
  %t393 = call i32 @get_ans_se(i32 %t396,i32 %t395,i32 %t394)
  store i32 %t393, i32* %t320, align 4
  %t398 = load i32, i32* %t320, align 4
  %t399 = load i32, i32* %t315, align 4
  %t400 = load i32, i32* %t316, align 4
  %t397 = call i32 @get_ans_se(i32 %t400,i32 %t399,i32 %t398)
  store i32 %t397, i32* %t320, align 4
  %t402 = load i32, i32* %t320, align 4
  %t403 = load i32, i32* %t312, align 4
  %t264 = sdiv i32 %t403, 2
  %t404 = load i32, i32* %t313, align 4
  %t267 = sdiv i32 %t404, 2
  %t401 = call i32 @get_ans_se(i32 %t267,i32 %t264,i32 %t402)
  store i32 %t401, i32* %t320, align 4
  %t405 = load i32, i32* %t317, align 4
  %t406 = load i32, i32* %t318, align 4
  %t272 = add i32 %t405, %t406
  %t407 = load i32, i32* %t319, align 4
  %t274 = add i32 %t272, %t407
  %t408 = load i32, i32* %t320, align 4
  %t276 = add i32 %t274, %t408
  ret i32 %t276
}
