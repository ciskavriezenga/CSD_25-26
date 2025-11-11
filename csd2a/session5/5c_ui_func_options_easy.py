

example_question = "Choose your samplepack: "
example_options = ["ducksounds", "regular drumkit"]

def retrieve_user_option(question, options):
    """
    Presents the user with a the provided question and options to choose from
    and then returns the index of the selected option.

    parameter question: the question to ask the user
    paramter options: the options the user can choose from

    question type: string
    options type: list
    """
    if(not str(question)):
        raise TypeError(
            "retrieve_user_option function expects first parameter to be a string")
    else:
        # default option
        selected_option = 1
        correctInput = False

        while (not correctInput):
            # present user with options and ask for selection
            print(question)
            for i, option in enumerate(options):
                print(i + 1, ":", option)
            print("leave empty for default opion 1")
            user_input = input()

            # if answer is empty --> use default
            if not user_input:
                correctInput = True

            # answer was not empty, validate answer
            else:
                try:
                    # if answer is an integer, try to use this answer
                    input_index = int(user_input)
                    # validate if selection is in range
                    if (input_index >= 1 and input_index <= len(options)):
                        selected_option = input_index

                        correctInput = True
                    # TODO - throw error
                except:
                    print("Incorrect input - please enter a valid value.\n" +
                        "Please try again.\n\n")

        # after while shift selected option
        selected_option -= 1

    return selected_option

selected_index = retrieve_user_option(example_question, example_options)
print("Selected drumkit: ", example_options[selected_index])
