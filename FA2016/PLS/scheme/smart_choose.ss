;Choose function with no reliance on factorial

(define (smart_choose n k)
  (cond
    ((or (= k 0) (= n k)) 1)
    (else (+ (smart_choose (- n 1) (- k 1)) (smart_choose (- n 1) k)))
  )
)

(smart_choose 5 3)
(smart_choose 6 2)
(smart_choose 10 3)
(smart_choose 5 0)
(smart_choose 5 5)
(smart_choose 0 0)
