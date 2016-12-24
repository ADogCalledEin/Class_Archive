;Better power functions
(define (checkpower x n)
  (cond
      ((= n 0) 1)
      ((= n 1) x)
      ((= n 2) (* x x))
      ((even? n) (checkpower (checkpower x (/ n 2)) 2))
      (else (* x (checkpower x (- n 1))))
  )
)

(define (power x n)
  (cond
    ((< n 0) (/ 1 (checkpower x (- 0 n))))
    (else (checkpower x n))
  )
)

(power 2 13)
