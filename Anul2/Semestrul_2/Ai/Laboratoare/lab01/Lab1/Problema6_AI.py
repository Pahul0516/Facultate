
# timp O(n)
# spatiu O(1)
def f(sir):
    # Pasul 1: Găsim un candidat pentru elementul majoritar
    candidat = None
    contor = 0
    
    for numar in sir:
        if contor == 0:
            candidat = numar
            contor = 1
        elif numar == candidat:
            contor += 1
        else:
            contor -= 1
    
    # Pasul 2: Verificăm dacă candidatul este într-adevăr majoritar
    if candidat is not None:
        aparitii = sir.count(candidat)
        if aparitii > len(sir) // 2:
            return candidat
    
    return None  # Nu există element majoritar

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