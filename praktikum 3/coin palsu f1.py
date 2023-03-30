def find_fake_coin(coins):
    n = len(coins)
    if n == 1:
        return 0
    elif n == 2:
        if coins[0] < coins[1]:
            return 0
        else:
            return 1
    else:
        third = n // 3
        first_third = coins[:third]
        second_third = coins[third:2*third]
        last_third = coins[2*third:]
        
        if sum(first_third) < sum(second_third):
            return find_fake_coin(first_third)
        elif sum(second_third) < sum(first_third):
            return find_fake_coin(second_third)
        else:
            return find_fake_coin(last_third) + (2 * third)

coins = list(map(int,input().split()))
print(find_fake_coin(coins) + 1)