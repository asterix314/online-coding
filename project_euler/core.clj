(ns project-euler.core
  (:require [clojure.math.numeric-tower :as math]
            [clojure.math.combinatorics :as combo]))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 169

;; f(n) = f((n-1)/2) if n odd
;; f(n) = f(n/2) + f(n-1) if n even

(def pe169 (memoize (fn [n]
    (cond (= n 0) 1
          (odd? n) (pe169 (/ (dec n) 2))
          :else (+' (pe169 (/ n 2)) (pe169 (dec n)) )))))

;; (time (pe169 (math/expt 10 25)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 23

;; 1. find all the abundant numbers below 28124
;; 2. calculate their pair-sums which are also below 28124
;; 3. give the difference (sum of 1 to 18123) - (sum of pair-sums)

;; this naive implementation of the abundancy test is not the bottleneck
;; more advance method based on prime factorization: 
;; https://en.wikipedia.org/wiki/Divisor_function
(defn abundant? [x]
  (loop [sum 1
         next-divider 2]
    (cond (> sum x) true
          (> (* next-divider next-divider) x) false
          (= (* next-divider next-divider) x) (> (+ sum next-divider) x)
          :else
          (recur (if (zero? (mod x next-divider))
                   (+ sum next-divider (quot x next-divider))
                   sum)
                 (inc next-divider)))))

;; the bottleneck is the pairwise check which takes O(n^2)
(defn pe023 [n]
  (let [abundant-numbers (vec (filter abundant? (range 12 n)))
        pair-sums (set 
                   (for [x abundant-numbers
                         y abundant-numbers
                         :when (<= x y)
                         :when (< (+ x y) n)] 
                     (+ x y)))]
    (- (/ (* n (dec n)) 2) (apply + pair-sums))))

;; (time (pe023 28124))
;; => 4179871

;; alternative implementation. slightly slower.
(comment defn pe023 [n]
  (let [pair-sums
        (loop [pair-sums #{}
               abundant-numbers (filter abundant? (range 12 n))]
          (if (empty? abundant-numbers) pair-sums
              (recur (->> abundant-numbers
                          (map (partial + (first abundant-numbers)))
                          (take-while (partial > n))
                          (into pair-sums))
                     (rest abundant-numbers))))]
    (- (/ (* n (dec n)) 2) (apply + pair-sums))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 35

;; uses Java BigInteger.isProbablePrime to test primality
;; certainty of 5 is sufficient for n <= 1e6

(defn circular-prime? [n]
  (let [s (str n)
        rotate-left #(str (subs % 1) (first %))
        prime? #(.isProbablePrime (BigInteger/valueOf %) 5)]
    (and (prime? n)
         (not (clojure.string/includes? s "0"))
         (->> s
              (iterate rotate-left)
              (rest)
              (take-while (partial not= s))
              (every? #(prime? (read-string %)))))))

(defn pe035 [n]
  (count (filter circular-prime? (range 2 n))))

;; (time (pe035 1e6))
;; => 55

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 85

;; there are Binomial[n+1,2] * Binomial[m+1,2], or n(n+1)m(m+1)/4 rectangles.
;; to find the (n,m) to yield closest to 2e6, try in sequence:
;; k = 2000000, 2000001, 1999999, 2000002, 1999998, 2000003, ...
;; and search for a facorization n(n+1)m(m+1) = 4k, n <= m.

(defn pe085 [x]
  (letfn [(gen-trials [k]
            (iterate #(+ (- (* 2 k) %) (if (> % k) 0 1)) k))
          (gen-sol [k]
            (for [n (iterate inc 1)
                  :while (<= (* n n (inc n) (inc n)) (* 4 k))
                  :let [[q r] ((juxt quot rem) (* 4 k) (* n (inc n)))
                        m (int (math/sqrt q))]
                  :when (and (zero? r)
                             (>= q (* n (inc n)))
                             (= q (* m (inc m))))]
              [k n m]))]
    (->> (gen-trials x)
         (map (comp first gen-sol))
         (filter some?)
         (first))))

;; (time (pe085 2000000))
;; => [1999998 36 77]
;; 36 * 77 = 2772

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 36

(defn pe036 [n]
  (letfn [(double-palindrome? [x]
            (every? #(= % (clojure.string/reverse %))
                    [(str x) (Integer/toBinaryString x)]))]
    (->> (range 1 n 2) ;; inspect odd numbers only
         (filter double-palindrome?)
         (apply +))))

;; (time (pe036 1000000))
;; => 872187

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; project euler problem 100

(defn pe100 [start-discs]
  )


(comment loop [d start-discs
       sd (* d (dec d))
       b (inc (first (math/exact-integer-sqrt (/ sd 2))) )
       sb (* 2 b (dec b))]
  (println d sd b sb)
  (cond
   (= sd sb) [b d]
   (> sd sb) (recur d sd (inc b) (+ sb (* 4 b)))
   :else (recur (inc d) (+ sd (* 2 d)) b sb)))

(time (pe100 1000000))


(comment letfn [(get-blues [discs]
            (-> (*' 1/2 discs (dec' discs)) math/exact-integer-sqrt first inc'))
          (get-discs [blues]
            (-> (*' 2 blues (dec' blues)) math/exact-integer-sqrt first inc'))
          (match? [blues discs]
            (== (*' 2 blues (dec' blues)) (*' discs (dec' discs))))]
    (->> (iterate inc' (get-blues start-discs))
         (filter #(match? % (get-discs %)))
         first))


