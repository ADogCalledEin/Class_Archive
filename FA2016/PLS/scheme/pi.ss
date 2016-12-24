;Equation to calculate pi based on n recursions

(define (numer n)
  (cond
    ((= n 0) 0)
    (else
      (sqrt (+ 2 (numer (- n 1))))
    )
  )
)

(numer 3)

(define (denom n)
  (cond
    ((= n 0) 1)
    (else
      (* (/ (numer n) 2) (denom (- n 1)))
    )
  )
)


(define (pi n)
  (/ 2 (denom n))
)

(pi 1)
(pi 2)
(pi 3)
(pi 12)
