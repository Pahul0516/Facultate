# Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1} astfel încât o singură valoare se repetă de două ori, să se identifice acea valoare care se repetă. 
# De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.

# timp O(n)
# spatiu O(1)
def f(numbers):
    sumaGauss = (len(numbers) * (len(numbers)+1))/2
    suma = sum(numbers)
    return int(len(numbers)-(sumaGauss-suma))

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([1,2,3,4,2]) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f([1,2,3,4,4]) == 4
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([1,2,1,4,3,5]) == 1
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f([1,2,3,4,3,5]) == 3
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")


    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")