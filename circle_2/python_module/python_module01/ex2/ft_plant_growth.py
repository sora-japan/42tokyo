class Plant:
    a_name: str = ""
    height_in_centimeters: float = 0
    age_in_days: int = 0

    def show(self) -> None:
        print(
            f"{self.a_name}: "
            f"{self.height_in_centimeters:.1f}cm, "
            f"{self.age_in_days} days old"
        )

    def grow(self) -> None:
        self.height_in_centimeters = round(self.height_in_centimeters + 0.8, 1)

    def age(self) -> None:
        self.age_in_days += 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    self_plant = Plant()
    self_plant.a_name = "Rose"
    start_height = self_plant.height_in_centimeters = 25
    self_plant.age_in_days = 30
    self_plant.show()

    for i in range(1, 8):
        print(f"=== Day {i} ===")
        self_plant.grow()
        self_plant.age()
        self_plant.show()
    total = round(self_plant.height_in_centimeters - start_height, 1)
    print(f"Growth this week: {total:.1f}cm")
