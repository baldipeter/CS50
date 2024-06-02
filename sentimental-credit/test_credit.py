from credit import is_valid, company


def test_is_valid():
    assert is_valid("378282246310005") == True
    assert is_valid("371449635398431") == True
    assert is_valid("5555555555554444") == True
    assert is_valid("5105105105105100") == True
    assert is_valid("4111111111111111") == True
    assert is_valid("4012888888881881") == True


def test_is_invalid():
    assert is_valid("1234567890") == False


def test_company_amex():
    assert company("378282246310005") == "AMEX"
    assert company("371449635398431") == "AMEX"


def test_company_mc():
    assert company("5555555555554444") == "MASTERCARD"
    assert company("5105105105105100") == "MASTERCARD"


def test_company_visa():
    assert company("4111111111111111") == "VISA"
    assert company("4012888888881881") == "VISA"


def test_company_invalid():
    assert company("1234567890") == "INVALID"
