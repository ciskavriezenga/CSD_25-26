import re

def get_user_name():
    user_name = input("Hi, what is your first name")
    if(not user_name):
        # recursion
        print("Nothing was entered, let's try again.")
        return get_user_name()

    # use regular expression to check if only characters were entered
    reg_pattern = r'[^\.a-zA-Z]'
    if re.search(reg_pattern, user_name):
        #Character other then . a-z 0-9 was found --> recursive call
        print("Please, only use characters a-z and A-Z, let's try again.")
        return get_user_name()

    return user_name
