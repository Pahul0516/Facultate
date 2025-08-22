
# timp O(n)
# spatiu O(1)
def f(v1, v2):
    # Asigură-te că vectorii au aceeași lungime
    if len(v1) != len(v2):
        raise ValueError("Vectorii trebuie să aibă aceeași lungime.")
    
    # Calculăm produsul scalar doar pentru elementele nenule
    rezultat = 0
    for x, y in zip(v1, v2):
        rezultat += x * y
    
    return rezultat

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([1,0,2,0,3], [1,2,0,3,1]) == 4
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f([0,0,0,0,0], [1,2,0,3,1]) == 0
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([0,1,0,0,0], [1,2,0,3,1]) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f([2,1,21,1,2], [1,2,0,3,1]) == 9
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")

    

    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")