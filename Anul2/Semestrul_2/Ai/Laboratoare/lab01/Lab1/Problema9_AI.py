
# timp O(n*m)
# spatiu O(n)
def f(mat, x1, y1, x2, y2):
    suma = 0
    for i in range(x1, x2 + 1):
        for j in range(y1, y2 + 1):
            suma += mat[i][j]
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
                  [1, 5, 7, 9, 4]], 0, 0, 1, 1) == 14
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