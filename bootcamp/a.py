import math

def main():
    a, b = map(float, input().split())
    t = int(pow((2*b/a), -3.0/2.0))
    ans = float('inf')

    for i in range(-10, 11):
        u = t + i
        if u > 0:  # 負の数の平方根を避ける
            ans = min(ans, b*(u-1) + a*(math.sqrt(u))/u)

    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
