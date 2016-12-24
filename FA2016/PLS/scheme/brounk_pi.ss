; Calculating pi to n number of b_pis using Brouncker's Equation to calculate Pi

(define (b_pi n ans)
  (cond
    ((= n 1) (/ 4 (+ 1 (/ 1 ans))))
    (else
      (b_pi (- n 2) (+ 2 (/ (square n) ans)))
    )
  )
)

(b_pi 3 1)
(b_pi 5 1)
(b_pi 7 1)
(b_pi 9 1)
(b_pi 21 1)
