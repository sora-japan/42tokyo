

class GardenError(Exception):


class PlantError(GardenError):
    print("Testing PlantError...")

class WaterError(GardenError):
    print("Testing WaterError...")



if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

