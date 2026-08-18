#!/usr/bin/env python3
def input_temperature(temp_str: str) -> int:
    temp_int = int(temp_str)
    if temp_int < 0:
        raise ValueError(f"{temp_int}°C is too cold for plants (min 0°C)")
    elif temp_int > 40:
        raise ValueError(f"{temp_int}°C is too hot for plants (max 40°C)")
    return temp_int

def test_temperature() -> None:
    print("Input data is '25'")
    input_temperature("25")
    print("Temperature is now 25°C")
    print()
    print("Input data is 'abc'")
    try:
        input_temperature("abc")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is '100'")
    try:
        input_temperature("100")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is '-50'")
    try:
        input_temperature("-50")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")
    test_temperature()
    print("\nAll tests completed - program didn't crash!")

