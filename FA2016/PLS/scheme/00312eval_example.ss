(define q   '(* (* x x) (+ x 3)))
q

(define r '(x))
r

(define s '(lambda r q))
s ; not what we want

(define t (list 'lambda r q))
t ; this IS what we want

(define z (list t 8))
z

(eval z user-initial-environment)
