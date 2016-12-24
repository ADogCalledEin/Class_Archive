;Matrices, hooray!
;Tranposing a matrix

(define (column a out)
  (cond
    ((null? a) (reverse out))
    (else
      (column (cdr a) (cons (car (car a)) out))
    )
  )
)

(define (nth a n count)
  (cond
    ((= count n) (car a))
    (else
      (nth (cdr a) n (+ 1 count))
    )
  )
)


(define (loop a n count)
  (cond
    ((= count n) a)
    (else
      (loop (cdr a) n (+ count 1))
    )
  )
)

(define (remove big_list out count n len)
  (cond
    ((= count len) (reverse out))
    (else
      (remove big_list (cons (loop (nth big_list count 0) n 0) out) (+ count 1) n len)
    )
  )
)

(define (transpose big_list count out)
  (cond
    ((= count (length (car big_list))) (reverse out))
    (else
      (transpose big_list (+ count 1) (cons (column (remove big_list (list ) 0 count (length big_list)) (list )) out))
    )
  )
)

(define m
  (list
    (list 2 4 7 1 2)
    (list 8 5 2 0 3)
    (list 4 2 2 9 4)
    (list 6 3 7 1 6)
    (list 2 8 3 7 7)
  )
)

(define z (list ))
(define q (list ))
(define y (list ))

(transpose m 0 y)
