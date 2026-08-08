def ft_count_harvest_iterative():
    day = int(input("Days until harvest: "))
    i = 1
    while i <= day:
        print(f"Day {i}")
        i += 1  # 忘れずにiを1ずつ増やす
    print("Harvest time!")
