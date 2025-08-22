#Să se determine produsul scalar a doi vectori rari care conțin numere reale. Un vector este rar atunci când conține multe elemente nule. 
# Vectorii pot avea oricâte dimensiuni. 
# De ex. produsul scalar a 2 vectori unisimensionali [1,0,2,0,3] și [1,2,0,3,1] este 4.

# timp O(n)
# spatiu O(1)
def f(v1, v2):
    return sum(el1 * el2 for el1, el2 in zip(v1, v2))

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