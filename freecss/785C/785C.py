

a=[int(i) for i in input('').split()]

n = a[0]
m = a[1]

if (m >= n):
    ans = n
    print(ans)
    exit()

k = (-1. - (1 + 4 * (2 * n - 2 * m)) ** 0.5) / -2

#print(k)
k = int(k+m)

beg = max(k - 3000, m+1)
end = min(n+1, k + 3000)
#print(end)
ans = k + 3000

#if (beg == end):
 #   ans = m+1*/

for d in range(beg, end, 1):
    k = d - m
    food = n + m * (k - 1)
    eat = ((m + 1 + m + k) * k) // 2
    #print(d, k, food, eat)
    if (food <= eat):
        #print("jh")
        if (ans > d):
            ans = d

print(ans)
