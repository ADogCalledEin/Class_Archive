;(remainder 37 10)

(define (rem a b)
  (cond
    ((< a b) a)
    (else
      (rem (- a b) b)
    )
  )
)

(rem 37 10)

(rem 0 5)
(rem 5 5)
