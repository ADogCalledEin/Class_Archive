#|
  Defining a distance formula in scheme
  Computing the distance between two points
|#

(define x1 8)
(define y1 2)
(define x2 12)
(define y2 11)

(define (dist x1 y1 x2 y2)
  (define (find_x x2 x1)
    (square (- x2 x1))
  )
  (define (find_y y2 y1)
    (square (- y2 y1))
  )
  (sqrt (+ (find_x x2 x1) (find_y y2 y1)))
)

(dist x1 y1 x2 y2)
