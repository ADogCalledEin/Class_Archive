
(define (sign  x)
   (cond
     ((< x 0)  -1)
     ((= x 0)   0)
     ((> x 0)   1)
   )
)


; now test it out
(sign  -5.3)
(sign   (- 5 5))
(sign   4)





; version B :

(define (signB  x)
   (cond
     ((< x 0)  -1)
     ((= x 0)   0)
     (else      1)
   )
)


; now test it out
(signB  -5.3)
(signB   (- 5 5))
(signB   4)

; Note : if you look at the interpreter's evaluation
; of the definition of signB  you will see  signb
; i.e. the language is case-insensitive

(signb  -7)
