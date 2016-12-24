#|
; should give 1/2 and -3
(define a   2)
(define b   5)
(define c  -3)
|#

; should give 3+4i and 3-4i
(define a   1)
(define b  -6)
(define c  25)


(define d  (sqrt  (- (* b b)  (* 4 a c))))
(define x  (/   (+  (- 0 b)  d)   (* 2 a)))
(define y  (/   (-  (- 0 b)  d)   (* 2 a)))

a
b
c
d
x
y
(+  (* a x x)  (* b x)  c)
(+  (* a y y)  (* b y)  c)

