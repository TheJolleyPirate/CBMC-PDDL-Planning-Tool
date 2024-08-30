;; original sequence 1: (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -76 -75 -74 -73 -72 -71 -70 -69 -68 -67 -66 -65 -64 -63 -62 -61 -56 -55 -54 -53 -60 -59 -58 -57 -27 -26 -44 -43 -42 -41 45 46 47 48 -36 -35 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -89 -88 -87 -86 -85 -84 77 78 79 80 81 82 83 90 91 92 93 94 95 96 -105 -104 -103 -102 -101 -100 -99 -98 28 29 30 31 32 33 34 -40 -39 -38 -37 49 50 51 52 -97)
;; original sequence 2: (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -76 -75 -74 -73 -72 -71 -70 -69 -68 -67 -66 -65 -64 -63 -62 -61 -60 -59 -58 -57 -56 -27 -26 -44 -43 -42 -41 45 46 47 48 -36 -35 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -89 -88 -87 -86 -85 -84 77 78 79 80 81 82 83 90 91 92 93 94 95 96 -55 -54 -53 -105 -104 -103 -102 -101 -100 -99 -98 28 29 30 31 32 33 34 -40 -39 -38 -37 49 50 51 52 -97)
;; simplified sequence 1: (107 -56 110 109 106 108)
;; simplified sequence 2: (107 109 -56 106 110 108)
;; common subsequences: (((-27 -26 -44 -43 -42 -41 45 46 47 48 -36 -35 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -89 -88 -87 -86 -85 -84 77 78 79 80 81 82 83 90 91 92 93 94 95 96) . 106) ((1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -76 -75 -74 -73 -72 -71 -70 -69 -68 -67 -66 -65 -64 -63 -62 -61) . 107) ((-105 -104 -103 -102 -101 -100 -99 -98 28 29 30 31 32 33 34 -40 -39 -38 -37 49 50 51 52 -97) . 108) ((-60 -59 -58 -57) . 109) ((-55 -54 -53) . 110))
;; #safe insertions/deletions: 0
;; sequence 1 (names): ((NORMAL SUB2) (INVERTED G56) (NORMAL SUB5) (NORMAL SUB4) (NORMAL SUB1) (NORMAL SUB3))
;; sequence 2 (names): ((NORMAL SUB2) (NORMAL SUB4) (INVERTED G56) (NORMAL SUB1) (NORMAL SUB5) (NORMAL SUB3))

(DEFINE (PROBLEM ASYNEUMA-TO-TRIODANUS) (:DOMAIN GENOME-EDIT-DISTANCE)
        (:OBJECTS SUB5 SUB4 SUB3 SUB2 SUB1 G56)
        (:INIT (NORMAL SUB2) (INVERTED G56) (NORMAL SUB5) (NORMAL SUB4)
               (NORMAL SUB1) (NORMAL SUB3) (PRESENT SUB2) (PRESENT G56)
               (PRESENT SUB5) (PRESENT SUB4) (PRESENT SUB1)
               (PRESENT SUB3) (CW SUB3 SUB2) (CW SUB1 SUB3)
               (CW SUB4 SUB1) (CW SUB5 SUB4) (CW G56 SUB5)
               (CW SUB2 G56) (IDLE) (= (TOTAL-COST) 0))
        (:GOAL (AND (NORMAL SUB2) (NORMAL SUB4) (INVERTED G56)
                    (NORMAL SUB1) (NORMAL SUB5) (NORMAL SUB3)
                    (CW SUB3 SUB2) (CW SUB5 SUB3) (CW SUB1 SUB5)
                    (CW G56 SUB1) (CW SUB4 G56) (CW SUB2 SUB4)))
        (:METRIC MINIMIZE (TOTAL-COST)))