def fibonacci_last_digit(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10


if __name__ == '__main__':
    n = int(input())
    print(fibonacci_last_digit(n))
