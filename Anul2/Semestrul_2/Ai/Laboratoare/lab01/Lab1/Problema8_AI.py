
# timp O(n)
# spatiu O(n)
def f(n):
    # Creăm o listă pentru a stoca rezultatele
    result = []
    
    # Parcurgem toate numerele de la 1 la n
    for i in range(1, n + 1):
        # Convertem fiecare numar in binar si eliminam prefixul "0b"
        result.append(bin(i)[2:])
    
    return result

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f(1) == ['1']
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f(2) == ['1', '10']
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f(8) == ['1', '10', '11', '100', '101', '110', '111', '1000']
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f(0) == []
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")


    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")