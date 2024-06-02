# TODO


def main():
    text = get_text()
    letters = count_letters(text)
    sentences = count_sentence(text)
    words = count_words(text)
    grade = calculate_grade(letters, sentences, words)
    print(grade)


def get_text():
    t = input("Text: ").strip()
    return t


def count_letters(tx):
    lett = 0
    for t in tx:
        if t.isalnum() == True:
            lett += 1
    return lett


def count_sentence(txt):
    x = txt.count(".")
    y = txt.count("!")
    z = txt.count("?")
    return x + y + z


def count_words(string):
    word = string.split(" ")
    return len(word)


def calculate_grade(l, s, w):
    L = l / w * 100
    S = s / w * 100
    # print(L, S)
    grd = int(round(0.0588 * L - 0.296 * S - 15.8, 0))
    if grd <= 1:
        return "Before Grade 1"
    elif grd >= 16:
        return "Grade 16+"
    else:
        return f"Grade {grd}"


if __name__ == "__main__":
    main()
