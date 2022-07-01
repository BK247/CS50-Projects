from cs50 import get_int
from cs50 import get_string
import re

ccnumber = get_string("Enter your number:  ")

regex_visa = "^4[0-9]{12}(?:[0-9]{3})?$"
p1 = re.compile(regex_visa)
regex_amex = "^3[47][0-9]{13}$"
p2 = re.compile(regex_amex)
regex_mastercard = "^(5[1-5][0-9]{14}|2(22[1-9][0-9]{12}|2[3-9][0-9]{13}|[3-6][0-9]{14}|7[0-1][0-9]{13}|720[0-9]{12}))$"
p3 = re.compile(regex_mastercard)


if re.match(p1, ccnumber):
    print("VISA")
elif re.match(p2, ccnumber):
    print("AMEX")
elif re.match(p3, ccnumber):
    print("MASTERCARD")
else:
    print("INVALID")
