from cs50 import get_string

string = get_string("Text: ")
letters = 0
words = 1
sentences = 0

for i in string:
    if i.isalpha() == True:
        letters += 1
    elif i == " ":
        words += 1
    elif i in [".", "!", "?"]:
        sentences += 1

L = (float(letters) / float(words)) * 100
S = (float(sentences) / float(words)) * 100
index = ((0.0588 * L) - (0.296 * S)) - 15.8

if index < 1:
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {int(round(index))}")
