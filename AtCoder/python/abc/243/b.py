n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

hit = sum(va == vb for va, vb in zip(a, b))
blow = len(set(a) & set(b)) - hit

print(hit, blow)