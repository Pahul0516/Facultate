# Considerându-se o matrice cu n x m elemente binare (0 sau 1) sortate crescător pe linii, să se identifice indexul liniei care conține cele mai multe elemente de 1.
# De ex. în matricea
# [[0,0,0,1,1],
# [0,1,1,1,1],
# [0,0,1,1,1]]
# a doua linie conține cele mai multe elemente 1.

# timp O(n*m)
# spatiu O(1)
def f(mat, n):
    afis = 0
    maxi = -1
    for i in range(0,n):
        s = sum(mat[i])
        if s > maxi:
            maxi = s
            afis = i

    return afis

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([[0,0,0,1,1],
                  [0,1,1,1,1],
                  [0,0,1,1,1]], 3) == 1
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")


    try:
        assert f([[1,1,1,1,1],
                  [0,1,1,1,1],
                  [0,0,1,1,1]], 3) == 0
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([[0,0,0,0,0],
                  [0,0,0,0,0],
                  [0,0,0,0,0]], 3) == 0
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")
    
    try:
        assert f([[1,0,1,0,1],
                  [0,1,0,1,1],
                  [0,1,1,1,1]], 3) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")

    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")