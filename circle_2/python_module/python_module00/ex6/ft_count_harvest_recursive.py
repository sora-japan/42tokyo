def ft_count_harvest_recursive():
    day = int(input("Days until harvest: "))
    def count_day(now):
        if now > day:
            print("Harvest time!")
            return
        else:
            print(f"Day {now}")
            count_day(now + 1)
    count_day(1)
