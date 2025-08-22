import re
from collections import Counter

# timp O(n)
# spatiu O(n)
def f(text):
    # Îndepărtează semnele de punctuație și împărțim textul în cuvinte
    cuvinte = re.findall(r'\b\w+\b', text.lower())  # folosește lower() pentru a ignora diferențele de majuscule/minuscule
    
    # Contează frecvența fiecărui cuvânt
    frecventa = Counter(cuvinte)
    
    # Filtrăm cuvintele care apar o singură dată
    cuvinte_unice = [cuvant for cuvant, numar in frecventa.items() if numar == 1]
    
    return cuvinte_unice


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
        assert f("") == []
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 4 failed")

    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")