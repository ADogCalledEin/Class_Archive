;Summation of a function (series, etc)
(define (sum func s n)
  (cond
    ((= s n) (func s))
    (else
      (+ (func s) (sum func (+ s 1) n))
    )
  )
)

(define (dumb x)
  (+ x 4)
)

(sum dumb 4 10 )

;Now using a lambda
(define (summation func)
  (lambda (s n)
    (cond
      ((= s n) (func s))
      (else
        (+ (func s) ((summation func) (+ s 1) n)))
    )
  )
)

((summation square) 0 4)
((summation sqrt) 3 4)
