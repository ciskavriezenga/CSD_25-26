

example_question = "Choose your samplepack: "
example_options = ["ducksounds", "regular drumkit"]


def retrieve_user_input(question, options):
    """
    Presents the user with a the provided question and options to choose from,
    indexed with an offset of 1 and then returns the user input

    parameter question: the question to ask the user
    paramter options: the options the user can choose from

    question type: string
    options type: list
    """
    # be sure the question is a string
    if(not str(question)):
        raise TypeError(
            "retrieve_user_option function expects first parameter to be a string")
    # present user with options and ask for selection
    print(question)
    for i, option in enumerate(options):
        print(i + 1, ":", option)
    print("leave empty for default opion 1")
    return input()


def validate_int_in_inclusive_range(value, range_low, range_high):
    try:
        int_value = int(value)
        if (int_value >= range_low and int_value <= range_high):
            return True;
        return False
    except:
        return False

    return True

def retrieve_user_option(question, options):
    """
    Presents the user with a the provided question and options to choose from
    and then returns the index of the selected option.

    parameter question: the question to ask the user
    paramter options: the options the user can choose from

    question type: string
    options type: list
    """
    # default option, offset of +1 due to readability for user
    selected_option = 1
    correctInput = False

    while (not correctInput):
        user_input = retrieve_user_input(question, options)
        # validate user input
        if(validate_int_in_inclusive_range(user_input, 0, len(options))):
            # user input is in given range
            selected_option = int(user_input)
            correctInput = True
        # if answer is empty --> use default value
        elif(not user_input):
            correctInput = True
        # else incorrect input -->  retry
        else:
            print("Incorrect input - please enter a valid value.\n" +
                "Please try again.\n\n")

    # after retrieval of correct answer shift to zero-indexing, thus -1
    selected_option -= 1

    return selected_option

selected_index = retrieve_user_option(example_question, example_options)
print("Selected drumkit: ", example_options[selected_index])
