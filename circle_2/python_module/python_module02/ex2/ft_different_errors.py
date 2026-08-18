#!/usr/bin/env python3
def garden_operations(operation_number):
    if operation_number == 0:
        print("Testing operation 0...")
        try:
            raise ValueError(f"Caught ValueError: invalid literal for int() with base 10:'{operation_number}'")
        except ValueError as e:
            print(e)
    elif operation_number == 1:
        print("Testing operation 1...")
        raise ZeroDivisionError("")
    elif operation_number == 2:
        raise FileNotFoundError
    elif operation_number == 3:
        raise TypeError
    else:
        return


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")


