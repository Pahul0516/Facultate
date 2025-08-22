# Să se determine cuvintele unui text care apar exact o singură dată în acel text. 
# De ex. cuvintele care apar o singură dată în ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.

# timp O(n)
# spatiu O(n)
def f(string):
    dictionary = dict()
    for s in string.split(' '):
        dictionary[s]=dictionary.get(s,0)+1

    rez = []
    for key, value in dictionary.items():
        if value == 1:
            rez.append(key)

    return rez

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f("ana are ana are mere rosii ana") == ["mere", "rosii"]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f("ana are ana are mere mere rosii ana") == ["rosii"]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f("ana are ana are mere mere rosii rosii ana") == []
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 3 failed")

    try:
        assert f("") == [""]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")

    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")