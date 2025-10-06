# example of functions that validates the expected type and a given range

cast_functions = {
    "int": int,
    "float": float,
    "string": str
}

def validate_input_type(input_value, expected_type):
    """
    parameter input_value: an input string to validate
    parameter expected_type: a string representing the type,
                    options: "int", "float", "string"
    """

    try:
        casted_value = cast_functions[expected_type](input_value)
        return True
    except:
        return False


def validate_input_in_range(input_value, expected_type, range_low, range_high):
    """
    Checks if input value is of the expected type and within the range
    [range_low, range_high] (inclusive range)

    parameter input_value: an input string to validate
    parameter expected_type: a string representing the type,
                    options: "int", "float"
    """

    if(expected_type == "int" or expected_type == "float"):
        # expected type is either int or float
        if(validate_input_type(input_value, expected_type)):
            # value is of the expected type
            input_value = cast_functions[expected_type](input_value)
            return (input_value >= range_low and input_value <= range_high)

        else:
            return False




# ============== DEMO FUNCTION validate_input_type =================

print("_______ Expecting an int ________")
print("When presenting a int as input, expecting an int: ",
    validate_input_type("11", "int"))
print("When presenting a float as input, expecting an int: ",
    validate_input_type("11.1", "int"))
print("When presenting a string as input, expecting an int: ",
    validate_input_type("a string as input", "int"))

print("\n\n")
print("_______ Expecting a float ________")
print("When presenting a int as input, expecting a float: ",
    validate_input_type("11", "float"))
print("When presenting a float as input, expecting a float: ",
    validate_input_type("11.1", "float"))
print("When presenting a string as input, expecting a float: ",
    validate_input_type("a string as input", "float"))

print("\n\n")
print("_______ Expecting a float ________")
print("When presenting a int as input, expecting a string: ",
    validate_input_type("11", "string"))
print("When presenting a float as input, expecting a string: ",
    validate_input_type("11.1", "string"))
print("When presenting a string as input, expecting a string: ",
    validate_input_type("a string as input", "string"))



# ============== DEMO FUNCTION validate_input_in_range =================

print("\n\n")
input_string = "10"
input_type = "int"
range_low = 8
range_high = 12

print("Validate input string", input_string, "and check range [",
    range_low, ", ", range_high, "]: ",
    validate_input_in_range(input_string, input_type, range_low, range_high))


input_string = "13"
range_low = 8
range_high = 12

print("Validate input string", input_string, "as type ", input_type,
    "and check range [", range_low, ", ", range_high, "]: ",
    validate_input_in_range(input_string, input_type, range_low, range_high))

input_string = "11.1"
range_low = 8
range_high = 12

print("Validate input string", input_string, "as type ", input_type,
    "and check range [", range_low, ", ", range_high, "]: ",
    validate_input_in_range(input_string, input_type, range_low, range_high))



print("\n\n")
input_string = "4"
input_type = "float"
range_low = 1
range_high = 5
print("Validate input string", input_string, "as type ", input_type,
    "and check range [", range_low, ", ", range_high, "]: ",
    validate_input_in_range(input_string, input_type, range_low, range_high))
# thus: int value passes 'validate float'


input_string = "5.1"
range_low = 1
range_high = 5

print("Validate input string", input_string, "as type ", input_type,
    "and check range [", range_low, ", ", range_high, "]: ",
    validate_input_in_range(input_string, input_type, range_low, range_high))
