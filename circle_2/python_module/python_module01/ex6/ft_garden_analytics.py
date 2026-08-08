class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self.set_height(height)
        self.set_age(age)
        self._stats = self.Stats()

    def show(self) -> None:
        self._stats.plus_one_show()
        print(
            f"{self._name}: "
            f"{self._height:.1f}cm, "
            f"{self._age} days old"
        )

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age

    def grow(self, amount: float = 0.8) -> None:
        self._stats.plus_one_grow()
        self._height = round(self._height + amount, 1)

    def age(self, amount: int = 1) -> None:
        self._stats.plus_one_age()
        self._age += amount

    @staticmethod
    def year_plant(age: int) -> bool:
        return age > 365

    @classmethod
    def create_plant(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    class Stats:
        def __init__(self) -> None:
            self._count_grow = 0
            self._count_age = 0
            self._count_show = 0

        def plus_one_grow(self) -> None:
            self._count_grow += 1

        def plus_one_age(self) -> None:
            self._count_age += 1

        def plus_one_show(self) -> None:
            self._count_show += 1

        def display(self) -> None:
            print(
                f"Stats: {self._count_grow} grow, "
                f"{self._count_age} age, {self._count_show} show"
            )


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._blooming = False

    def bloom(self) -> None:
        self._blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if self._blooming:
            print(f" {self._name} is blooming beautifully!")
        else:
            print(f" {self._name} has not bloomed yet")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seeds = 0

    def bloom(self) -> None:
        super().bloom()
        self._seeds += 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seeds}")


class Tree(Plant):
    def __init__(
            self, name: str, height: float, age: int, trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._stats: "Tree.Stats" = self.Stats()

    def produce_shade(self) -> None:
        self._stats.plus_one_shade()
        print(
            f"Tree {self._name} now produces a shade of "
            f"{self._height:.1f}cm long and {self._trunk_diameter:.1f}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")

    class Stats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()
            self._count_shade = 0

        def plus_one_shade(self) -> None:
            self._count_shade += 1

        def display(self) -> None:
            super().display()
            print(f" {self._count_shade} shade")


class Vegetable(Plant):
    def __init__(
            self, name: str, height: float, age: int, harvest_season: str
    ) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = 0

    def age(self, amount: int = 1) -> None:
        super().age(amount)
        self._nutritional_value += 1

    def grow(self, amount: float = 0.8) -> None:
        self._stats.plus_one_grow()
        self._height = round(self._height + 2.1, 1)

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self._harvest_season}")
        print(f" Nutritional value: {self._nutritional_value}")


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant._name}]")
    plant._stats.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.year_plant(30)}")
    print(f"Is 400 days more than a year? -> {Plant.year_plant(400)}")

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_statistics(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
    rose.bloom()
    rose.show()
    display_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    display_statistics(sunflower)

    print("\n=== Anonymous")
    unknown = Plant.create_plant()
    unknown.show()
    display_statistics(unknown)
