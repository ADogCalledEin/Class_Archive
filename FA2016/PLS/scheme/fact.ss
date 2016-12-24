(define (fac n)
  (cond
    ((= n 0) 1)
    (else
      (* n (fac (- n 1)))
    )
  )
)

(define (choose n k)
  (/ (fac n) (* (fac k) (fac (- n k))))
)

(choose 5 3)
(choose 5 4)
