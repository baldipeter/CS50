# TODO
import sys


def main():
    bank_num = get_int()
    valid_num = is_valid(bank_num)
    if valid_num == False:
        sys.exit("INVALID")
    c = company(bank_num)
    print(c)


# Get a string that looks like a num
def get_int():
    b_num = input("Card number? ").strip()
    return b_num


# Check for Luhn’s Algorithm
def is_valid(num):
    sum1 = 0
    sum2 = 0
    n = int(num)

    for i in range(len(num)):
        if i % 2 == 0:
            sum1 += n % 10
        else:
            sum2 += (n % 10 * 2) % 10
            sum2 += (n % 10 * 2) // 10

        n //= 10

    return (sum1 + sum2) % 10 == 0


# Company check
def company(valid):
    length = len(valid)
    valid = int(valid)
    while valid > 100:
        valid //= 10
    print(f"valid = {valid}, length = {length}")
    if length == 15 and valid in [34, 37]:
        return "AMEX"
    elif length == 16 and 51 <= valid <= 55:
        return "MASTERCARD"
    elif length in [13, 16] and 40 <= valid <= 49:
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()
