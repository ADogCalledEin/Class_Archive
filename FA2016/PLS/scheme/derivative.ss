

(define h 0.00001)

(define (deriv  func  x)
   (/   (-  (func (+ x h))   (func x))  h)
)


(deriv sqrt 16)
(/  1   (* 2 (sqrt 16)))

(deriv sin 4)
(cos 4)


(define (mycubic  x)
  (+  (* x x x)  (* 4 x x) (* 3 x) -6)
)
(define (mycubicprime  x)
  (+  (* 3 x x)  (* 8 x)  3)
)

(deriv mycubic 2)
(mycubicprime 2)
