def delete(n):
    m = []
    i = 0
    tag = False
    while i + 1 < len(n) :
        if n[i+1] != 0:
            m.append(n[i]*n[i+1])
            m.append(n[i+1]-1)
            tag = True
        i += 2
    if not tag:
        m.append(0)
        m.append(0);
    return m

def main():
    n = [int(i) for i in input().split()]
    k = delete(n)
    print(" ".join(str(s) for s in k))

if __name__ == "__main__":
    main()