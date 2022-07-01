from cs50 import get_float

while True:
    total = get_float("How many cents do you have? ")
    if total > 0:
        break

cents = round(total * 100)
coins = 0

coins_available = [25, 10, 5, 1]

for coin in coins_available:
    coins += cents // coin
    cents %= coin

print(coins)