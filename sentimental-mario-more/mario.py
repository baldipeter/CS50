# TODO


def main():
    h = get_int()
    pyramid(h, h)


def get_int():
    while True:
        try:
            height = int(input("What should be the height? "))
        except ValueError:
            print("Height should be an integer between 1 and 8")
        else:
            if 1 <= height <= 8:
                return height
            else:
                print("Height should be an integer between 1 and 8")


def pyramid(n, m):
    if n != 1:
        pyramid(n - 1, m)
        print(" " * (m - n), "#" * n, "  ", "#" * n, sep="")
    elif n == 1:
        print(" " * (m - n), "#  #", sep="")


if __name__ == "__main__":
    main()
