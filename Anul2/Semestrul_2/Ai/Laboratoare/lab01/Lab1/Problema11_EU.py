from queue import Queue
from copy import deepcopy


# timp O(n^2  m^2)
# spatiu (n * m)
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def lee(mat, n, m, x, y):
    coada = Queue()
    copy_mat = deepcopy(mat)
    if x == 0 or x == n-1 or y == 0 or y == m - 1 or mat[x][y]==1:
        return copy_mat
    mat[x][y]=1
    coada.put((x,y))
    ok = False
    while not coada.empty():
        i, j = coada.get()
        for t in range (0,4):
            ii = i + directions[t][0]
            jj = j + directions[t][1]
            if mat[ii][jj] == 0:
                mat[ii][jj] = 1
                coada.put((ii,jj))
                if ii == 0 or ii == n-1 or jj == 0 or jj == m - 1:
                    ok = True
                    break
        if ok == True:
            break
    if ok == False:
        return mat
    else:
        return copy_mat

def get_0_positions(mat, n , m):
    pairs = []
    for i in range (0, n):
        for j in range (0, m):
            if mat[i][j] == 0:
                pairs.append((i,j))
    return pairs

def f(mat, n, m):
    pairs = get_0_positions(mat, n , m)
    for p in pairs:
        x, y = p
        mat = lee(mat,n,m,x,y)
    return mat
        

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
