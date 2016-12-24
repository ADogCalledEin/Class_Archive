(define (new_length list count)
  (cond
    ((null? list) count)
    (else
      (new_length (cdr list) (+ 1 count))
    )
  )
)

(define p (list 2 3 4 5))
(new_length p 0)
