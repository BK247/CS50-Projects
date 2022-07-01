def main():
    height = get_height()

    for i in range(height):
        print(" " * (height - 1 - i), end="")
        print("#" * (i+1), end="")
        print(" " * 2, end="")
        print("#" * (i+1), end="\n")


def get_height():
    while True:
        try:
            n = int(input("How tall is the pyramid? "))
            if n > 0 and n < 9:
                break
            else:
                print('Use between 1-9')
        except ValueError:
            print('Use a NUMBER between 1-9')
    return n

main()