# Considerându-se o matrice cu n x m elemente întregi și o listă cu perechi formate din coordonatele a 2 căsuțe din matrice ((p,q) și (r,s)), să se calculeze suma elementelor din sub-matricile identificate de fieare pereche.
# De ex, pt matricea
# [[0, 2, 5, 4, 1],
# [4, 8, 2, 3, 7],
# [6, 3, 4, 6, 2],
# [7, 3, 1, 8, 3],
# [1, 5, 7, 9, 4]]
# și lista de perechi ((1, 1) și (3, 3)), ((2, 2) și (4, 4)), suma elementelor din prima sub-matrice este 38, iar suma elementelor din a 2-a sub-matrice este 44.

# timp O(n * m)
# spatiu O(1)
def f(mat, x1, y1, x2, y2):
    if x1 < x2:
        x_start = x1
        x_end = x2
    else:
        x_start = x2
        x_end = x1

    if y1 < y2:
        y_start = y1
        y_end = y2
    else: 
        y_start = y2
        y_end = y1
    suma = 0
    for i in range (x_start, x_end +1):
        for j in range (y_start, y_end + 1):
            suma = suma + mat[i][j]

    return suma


def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([[0, 2, 5, 4, 1],
                  [4, 8, 2, 3, 7],
                  [6, 3, 4, 6, 2],
                  [7, 3, 1, 8, 3],
                  [1, 5, 7, 9, 4]], 1, 1, 3, 3) == 38
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")


    try:
        assert f([[0, 2, 5, 4, 1],
                  [4, 8, 2, 3, 7],
                  [6, 3, 4, 6, 2],
                  [7, 3, 1, 8, 3],
                  [1, 5, 7, 9, 4]], 2, 2, 4, 4) == 44
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([[0, 2, 5, 4, 1],
                  [4, 8, 2, 3, 7],
                  [6, 3, 4, 6, 2],
                  [7, 3, 1, 8, 3],
                  [1, 5, 7, 9, 4]], 1, 1, 0, 0) == 14
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")
    
    try:
        assert f([[0, 2, 5, 4, 1],
                  [4, 8, 2, 3, 7],
                  [6, 3, 4, 6, 2],
                  [7, 3, 1, 8, 3],
                  [1, 5, 7, 9, 4]], 1, 1, 1, 1) == 8
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")


    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")