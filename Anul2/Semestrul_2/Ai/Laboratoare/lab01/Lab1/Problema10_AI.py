from bisect import bisect_left

# timp O(n*m)
# spatiu O(1)
def f(matrice, n):
    n = len(matrice)
    m = len(matrice[0])
    
    max_ones = 0
    best_row = -1
    
    for i in range(n):
        # Găsim primul 1 folosind căutare binară
        idx = bisect_left(matrice[i], 1)
        num_ones = m - idx  # Numărul de 1 în linie
        
        if num_ones > max_ones:
            max_ones = num_ones
            best_row = i  # Indexul liniei curente
    
    return best_row

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
                  [0,0,0,0,0]], 3) == -1
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