; Convert decimal numbers to binary

(define (to_binary alist quo)
  (cond
    ((= quo 0) alist)
    (else
      (to_binary (cons (remainder quo 2) alist) (quotient quo 2))
    )
  )
)

(define p (list ))
(to_binary p 13)
(to_binary p 25)
