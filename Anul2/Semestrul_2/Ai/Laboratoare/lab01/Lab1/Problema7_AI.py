
# timp O(nlog n)
# spatiu O(n)
def f(sir, k):
    # Sortăm șirul în ordine descrescătoare
    sir_sortat = sorted(sir, reverse=True)
    
    # Returnăm al k-lea cel mai mare element (index k-1)
    return sir_sortat[k - 1]


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