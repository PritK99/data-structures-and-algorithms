def lcm(a, b):
    for l in range(1, a * b + 1):
        if l % a == 0 and l % b == 0:
            return l

    assert False


if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm(a, b))

