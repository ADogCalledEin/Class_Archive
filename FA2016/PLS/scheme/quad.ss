(define a 1)
(define b -6)
(define c 25)


(define (posi-quadratic a b c)
    (define discrim (sqrt (- (* b b)
                          (* 4.0 a c))))
    (/ (+ (- b) discrim)
       (* 2.0 a)))

(define (negi-quadratic a b c)
   (define discrim (sqrt (- (* b b)
                         (* 4.0 a c))))
   (/ (- (- b) discrim)
      (* 2.0 a)))

(posi-quadratic a b c)
(negi-quadratic a b c)
