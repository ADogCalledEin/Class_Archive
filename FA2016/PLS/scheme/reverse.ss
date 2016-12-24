; Take in a list and return the reverse


(define (element list1 n count)
  (cond
    ((= count n) (car list1))
    (else
      (element (cdr list1) n (+ count 1))
    )
  )
)

(define (my_rev list2 list1 count)
  (cond
    ((= count (length list1)) (cons (element list1 (length list1) 1) list2))
    (else
      (my_rev (cons (element list1 count 1) list2) list1 (+ 1 count))
    )
  )
)


(define n (list 100 200 300 400 500))
(define k (list ))
(my_rev k n 1)
