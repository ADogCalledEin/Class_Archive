; Simple power function with checks for zeroes
(define (checkpower x n)
  (cond
    ((= n 0) 1)
    ((= n 1) x)
    ((> n 0) (* x (checkpower x (- n 1))))
    ((< n 0) (* x (checkpower x (+ n 1))))
  )
)

(define (power x n)
  (cond
    ((= n 0) 1)
    ((> n 0) (checkpower x n))
    ((< n 0) (/ 1 (checkpower x n)))
  )

)

(pow 10 3)
