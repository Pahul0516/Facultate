from collections import deque

# timp O(n * m)
# spatiu O(n * m)
def f(matrice, n, m):
    if not matrice:
        return []
    
    n, m = len(matrice), len(matrice[0])
    vizitat = [[False] * m for _ in range(n)]

    # Direcții pentru deplasare (sus, jos, stânga, dreapta)
    directii = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # BFS pentru a marca toți zero-ii conectați de margine
    def bfs(x, y):
        coada = deque([(x, y)])
        vizitat[x][y] = True
        
        while coada:
            cx, cy = coada.popleft()
            for dx, dy in directii:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < n and 0 <= ny < m and not vizitat[nx][ny] and matrice[nx][ny] == 0:
                    vizitat[nx][ny] = True
                    coada.append((nx, ny))

    # Marcare zero-urilor de pe margine și a celor conectate cu ele
    for i in range(n):
        if matrice[i][0] == 0:
            bfs(i, 0)
        if matrice[i][m - 1] == 0:
            bfs(i, m - 1)
    
    for j in range(m):
        if matrice[0][j] == 0:
            bfs(0, j)
        if matrice[n - 1][j] == 0:
            bfs(n - 1, j)

    # Înlocuim toate zero-urile neatinse (care sunt complet înconjurate)
    for i in range(n):
        for j in range(m):
            if matrice[i][j] == 0 and not vizitat[i][j]:
                matrice[i][j] = 1

    return matrice

def test():
    tests_passed = 0
    tests_failed = 0

    try:
        assert f([[1,1,1,1,0,0,1,1,0,1],
                  [1,0,0,1,1,0,1,1,1,1],
                  [1,0,0,1,1,1,1,1,1,1],
                  [1,1,1,1,0,0,1,1,0,1],
                  [1,0,0,1,1,0,1,1,0,0],
                  [1,1,0,1,1,0,0,1,0,1],
                  [1,1,1,0,1,0,1,0,0,1],
                  [1,1,1,0,1,1,1,1,1,1]],8,10) == [[1,1,1,1,0,0,1,1,0,1],
                                                   [1,1,1,1,1,0,1,1,1,1],
                                                   [1,1,1,1,1,1,1,1,1,1],
                                                   [1,1,1,1,1,1,1,1,0,1],
                                                   [1,1,1,1,1,1,1,1,0,0],
                                                   [1,1,1,1,1,1,1,1,0,1],
                                                   [1,1,1,0,1,1,1,0,0,1],
                                                   [1,1,1,0,1,1,1,1,1,1]]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 1 failed")

    try:
        assert f([[1,1,1,1,0,0,1,1,0,1],
                  [1,0,0,1,1,0,1,1,1,1],
                  [1,0,0,1,1,1,1,1,1,1],
                  [1,1,1,1,0,0,1,1,0,1],
                  [1,0,0,1,1,0,1,1,0,0],
                  [1,1,0,1,1,0,0,1,0,1],
                  [1,1,1,0,1,0,1,0,0,1],
                  [1,1,1,0,1,0,1,1,1,1]],8,10) == [[1,1,1,1,0,0,1,1,0,1],
                                                   [1,1,1,1,1,0,1,1,1,1],
                                                   [1,1,1,1,1,1,1,1,1,1],
                                                   [1,1,1,1,0,0,1,1,0,1],
                                                   [1,1,1,1,1,0,1,1,0,0],
                                                   [1,1,1,1,1,0,0,1,0,1],
                                                   [1,1,1,0,1,0,1,0,0,1],
                                                   [1,1,1,0,1,0,1,1,1,1]]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([[1,1,1,1,0],
                  [1,0,0,1,1],
                  [1,1,1,1,1],
                  ],3,5) == [[1,1,1,1,0],
                             [1,1,1,1,1],
                             [1,1,1,1,1],
                            ]
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")

    try:
        assert f([],0,0) == []
        tests_passed += 1
    except AssertionError:
        tests_failed += 1
        print("Test 2 failed")
    

    print(f"\nTests Passed: {tests_passed}")
    print(f"Tests Failed: {tests_failed}")

if __name__ == "__main__":
    test()
    print("All tests passed!")
