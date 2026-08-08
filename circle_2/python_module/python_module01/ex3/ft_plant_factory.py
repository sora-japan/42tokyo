class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.a_name = name
        self.height_in_centimeters = height
        self.age_in_days = age

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
    print("=== Plant Factory Output ===")
    plants = [
        Plant("Rose", 25.0, 30),
        Plant("Oak", 200.0, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80.0, 45),
        Plant("Fern", 15.0, 120)
    ]

    for plant in plants:
        print("Created: ", end="")
        plant.show()
