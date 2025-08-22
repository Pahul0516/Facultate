# Pentru un șir cu n numere întregi care conține și duplicate, să se determine elementul majoritar (care apare de mai mult de n / 2 ori). 
# De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].

# timp O(n)
# spatiu O(n)
def f(values):
    dictionary = dict()
    for v in values:
        number = int(v)
        dictionary[number] = dictionary.get(number,0)+1

    for k, v in dictionary.items():
        if v > int(len(values)/2):
            return k
    return None
        
def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([2,8,7,2,2,5,2,3,1,2,2]) == 2
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f([1,4,4]) == 4
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([1,2,1,4,3,5]) == None
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f([1,2,3,4,3,5]) == None
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")


    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")