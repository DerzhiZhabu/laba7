def recurs(check, nomer, k, result):
    if len(nomer) == 0:
        check[0] += 1
    if check[0] == k:
        return True
    for i in range(len(nomer)):
        oleg = []
        deleted = False
        for j in range(len(nomer)):
            if nomer[j] != nomer[i] or deleted:
                oleg.append(nomer[j])
            else:
                deleted = True
        if recurs(check, oleg, k, result):
            result.append(str(nomer[i]))
            return True
    return False

def main():
    n = int(input())
    k = int(input())
    check = [0]
    result = []

    nomer = list(range(1, n+1))

    recurs(check, nomer, k, result)
    for i in range(n - 1, -1, -1):
        print(result[i], end="")

if __name__ == "__main__":
    main()
