; Convert binary to decimal numbers

(define (to_dec alist dec)
  (cond
    ((null? alist) dec)
    (else
      (to_dec (cdr alist) (+ dec (* (car alist) (expt 2 (- (length alist) 1)))))
    )
  )
)

(define p (list 1 0 0 0 1 1))
(to_dec p 0)
