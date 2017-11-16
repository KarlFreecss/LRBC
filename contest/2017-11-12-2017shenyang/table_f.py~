def check(x):
  y = x * x * 3 - 12
  k = int(round(pow(y, 0.5)))
  if (k * k == y):
    return True
  return False

index = 1
last = 4
old = 1
while (index < 1e31):
  index = index * last / old

  while (not check(x)):
    x = x + 1

  print(x)

  old = last
  last = index
