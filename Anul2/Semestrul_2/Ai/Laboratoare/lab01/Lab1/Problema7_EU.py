# Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n). 
# De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7

# timp O(n^2)
# spatiu O(1)
def f(values, k):
    while k != 1:
        m = max(values)
        values.remove(m)
        k -= 1

    return max(values)

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([2,8,7,2,2],2) == 7
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f([2,8,7,2,2], 1) == 8
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([2,8,7,2,2], 3) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f([2,8,7,2,2], 4) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")


    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")