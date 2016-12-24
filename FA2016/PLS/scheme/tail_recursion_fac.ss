(define (tr answer n)
  (cond
    ((= n 0) answer)
    (else (tr (* answer n) (- n 1)))
  )
)

(tr 1 2)
(tr 1 3)
(tr 1 3)
(tr 1 9)
