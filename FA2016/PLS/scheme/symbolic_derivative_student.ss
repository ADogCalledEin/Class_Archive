(define  (constant? x)  (number? x))

(define  (variable? x)  (symbol? x))

(define  (same-variable?  v1 v2)
   (and (variable? v1) (variable? v2) (eq? v1 v2))
)

(define  (make-sum a1 a2)  (list '+ a1 a2))

(define  (make-product a1 a2)  (list '* a1 a2))

(define  (sum?  x)
     (and (list? x) (= 3 (length x)) (eq? (car x) '+))
)

(define (first s)  (cadr s)) ; (car (cdr s))

(define (second s)  (caddr s)) ; (car (cdr (cdr s)))

(define  (product?  x)
     (and (pair? x) (eq? (car x) '*))
)

(define (difference? x)
  (and (list? x) (= 3 (length x)) (eq? (car x) '-))
)

(define (make-diff a1 a2) (list '- a1 a2))

(define (quotient? x)
  (and (list? x) (= 3 (length x)) (eq? (car x) '/))
)

(define (make-quot a1 a2) (list '/ a1 a2))

(define (sine? x)
  (and (list? x) (= 2 (length x)) (eq? (car x) 'sin))
)

(define (make-sin x) (list 'cos x))

(define (cosine? x)
  (and (list? x) (= 2 (length x)) (eq? (car x) 'cos))
)

(define (make-cosine x) (list 'sin x))

(define (exp? x)
  (and (list? x) (= 2 (length x)) (eq? (car x) 'exp))
)

(define (make-exp x) (list 'exp x))

(define (log? x)
  (and (list? x) (= 2 (length x)) (eq? (car x) 'log))
)

(define (deriv expr var)
  (cond
      ((constant? expr)
             0
      )

      ((variable? expr)
             (cond
                 ((same-variable? expr var)   1)
                 (else  0)
             )
      )

      ((sum? expr)
             (make-sum  (deriv  (first expr) var)
                        (deriv  (second expr) var)
             )
      )

      ((product? expr)
             (make-sum
                    (make-product  (first   expr)
                                   (deriv  (second expr) var)
                    )
                    (make-product  (deriv  (first   expr) var)
                                   (second expr)
                    )
             )
      )

      ((difference? expr)
             (make-diff (deriv (first expr) var)
			(deriv (second expr) var)
	     )
      )

      ((quotient? expr)
             (make-quot
	            (make-diff
		     (make-product (deriv (first expr) var)
                                   (second expr)
		     )
		     (make-product  (first expr)
                                   (deriv (second expr) var)
		     )
		    )
		    (make-product (second expr) (second expr))
             )
      )

      ((sine? expr)
             (make-product (deriv (first expr) var)
                    (make-sin (first expr))
	     )
      )

      ((cosine? expr)
             (make-product (deriv (make-product -1 (first expr)) var)
                    (make-cosine (first expr))
	     )
      )

      ((log? expr)
            (make-product
	            (make-quot 1 (first expr))
		    (deriv (first expr) var)
	    )
      )

      ((exp? expr)
            (make-product
		    (deriv (first expr) var)
		    (make-exp (first expr))
	    )
      )

      (else 'screwup)
  )
)

(define x '(x))

;(define test (deriv (deriv (deriv '(/ (- (sin (* x (log (cos (/ x (+ (* x x) 1)))))) (* (* x x) x)) (exp (+ x 4))) 'x) 'x) 'x))
(define test (deriv (deriv (deriv (deriv '(/ (- (sin (* x (log (cos (/ x (+ (* x x) 1)))))) (* (* x x) x)) (exp (+ x 4))) 'x) 'x) 'x) 'x))

(define formtest (list 'lambda x test))

;(define chktest (list formtest 3))
(define chktest (list formtest 2))

(eval chktest user-initial-environment)

; need +, -, *, /, sin, cos, exp, log
