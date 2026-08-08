class Plant:
    a_name: str = ""
    height_in_centimeters: int = 0
    age_in_days: int = 0

    def show(self) -> None:
        print(
            f"{self.a_name}: "
            f"{self.height_in_centimeters}cm, "
            f"{self.age_in_days} days old"
        )


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")

    # 1つ目の植物
    plant1 = Plant()
    plant1.a_name = "Rose"
    plant1.height_in_centimeters = 25
    plant1.age_in_days = 30
    plant1.show()

    # 2つ目の植物
    plant2 = Plant()
    plant2.a_name = "Sunflower"
    plant2.height_in_centimeters = 80
    plant2.age_in_days = 45
    plant2.show()

    # 3つ目の植物
    plant3 = Plant()
    plant3.a_name = "Cactus"
    plant3.height_in_centimeters = 15
    plant3.age_in_days = 120
    plant3.show()
