import sys
import string
import random

available_types = ["String", "Integer", "Float", "Boolean"]
max_int = 999999
max_string_len = 20
max_parent_value = 100

def get_input():
    if len(sys.argv) > 1 & len(sys.argv) < 3:
        data_type = check_data_type(sys.argv[1])
        count = sys.argv[2]
        return data_type, count


def check_data_type(data_type):
    if data_type in available_types:
        return data_type
    raise ValueError("Invalid type")


def check_count(count):
    if type(count) == int:
        return count
    raise ValueError("Invalid count")


def create_data(data_type, count):
    data = ''
    for iter in range(count):
        random.seed(iter)
        if iter == 0:
            data += str(0) + ' '
        else:
            data += str(get_random_integer(max_parent_value)) + ' '
        data += "code=" + str(code_generate[data_type]) + ' '
        data += "name=" + get_random_string() + '\n'
    return data


def get_random_string():
    length = get_random_integer(max_string_len) + 1
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(length))


def get_random_integer(max_value):
    return random.randrange(max_value)


def get_random_float():
    return round(random.uniform(1, 100), 5)


def get_random_boolean():
    return bool(random.getrandbits(1))


def create_file(data):
    file = open("../data_generator/data.txt", "w+")
    file.write(sys.argv[1] + ' ' + sys.argv[2] + '\n')
    file.write(data)
    file.close()


code_generate = {"String": get_random_string(), "Integer": get_random_integer(max_int),
                 "Boolean": get_random_boolean(), "Float": get_random_float()}

if __name__ == '__main__':

    data_type, count = get_input()

    data = create_data(data_type, int(count))

    create_file(data)
