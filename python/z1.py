def recurs(a, chisla, s):
    if len(chisla) == 0:
        return a == s
    for i in range(len(chisla)):
        oleg = []
        deleted = False
        for j in range(len(chisla)):
            if chisla[j] != chisla[i] or deleted:
                oleg.append(chisla[j])
            else:
                deleted = True
        if recurs(a + chisla[i], oleg, s):
            print(chisla[i], "+", end=" ")
            return True
        elif recurs(a * chisla[i], oleg, s):
            print(chisla[i], "*", end=" ")
            return True
    return False

def start(chisla, s):
    for i in range(len(chisla)):
        oleg = []
        deleted = False
        for j in range(len(chisla)):
            if chisla[j] != chisla[i] or deleted:
                oleg.append(chisla[j])
            else:
                deleted = True
        if recurs(chisla[i], oleg, s):
            print(chisla[i])
            return True
    return False

def main():
    s = int(input())
    chisla = [89, 65, 56, 43]
    print()
    print(start(chisla, s))

if __name__ == "__main__":
    main()
