# An example with functions in python

# NOTE: good practice = a multiline comment at beginning of a function,
#       also when the function is simple.
#       Such a comment is an associated docstring,
#       which can be used in auto generated documentation.
#       Also see https://peps.python.org/pep-0257/#one-line-docstrings
#       and https://peps.python.org/pep-0257/#multi-line-docstrings

def halve_values(values):
    """Halves the numeric values in the values list"""
    for i in range(len(values)):
        values[i] *= 0.5

def get_half_values(values):
    """Returns a new list containing the halved values from the values list"""
    half_values = []
    for value in values:
        half_values.append(value * 0.5)

    return half_values

# a list with note durations in quarternotes
note_durations = [1, 0.5, 0.5, 2]


# NOTE: Notice the difference between the two Functions
#       One function alter the presented list.
#       Another function returns a new list and does not alter the original list.
print("The note_durations list before calling a function:", note_durations)

halve_values(note_durations)
print("The note_durations list after calling halve_values:", note_durations)

halved_note_durations = get_half_values(note_durations)
print("The note_durations list after calling get_half_values:", note_durations)
print("The halved_note_durations list:", halved_note_durations)
