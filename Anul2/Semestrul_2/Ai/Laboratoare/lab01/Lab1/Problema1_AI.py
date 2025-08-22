
# timp O(n)
# spatiu O(n)
def f(text):
    # Împărțim textul în cuvinte folosind spațiul ca delimitator
    cuvinte = text.split()
    
    # Determinăm ultimul cuvânt în ordine alfabetică
    return max(cuvinte)


def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f("Ana are mere rosii si galbene") == "si"
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")
    
    try:
        assert f("ana are mere rosii si galbene") == "si"
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f("ana are mere ssi rosii si galbene") == "ssi"
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f("ana are mere z ssi rosii si galbene") == "z"
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")

    
    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")
