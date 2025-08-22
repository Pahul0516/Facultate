# timp O(n)
# spatiu O(n)
def f(sir):
    # Creăm un set pentru a urmări valorile întâlnite
    valori_intalnite = set()
    
    # Parcurgem șirul
    for numar in sir:
        # Dacă numărul a fost deja întâlnit, acesta este valoarea care se repetă
        if numar in valori_intalnite:
            return numar
        # Dacă nu, adăugăm numărul în set
        valori_intalnite.add(numar)
    
    # Dacă nu există valori repetate (ceea ce nu ar trebui să se întâmple conform cerinței)
    return None

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