import random

value = [4,4,4,4,4,4]
#1.
#PRODUCT FUNCTION
def product(values):
    result = 1
    for v in values:
        result = result * v
    return result

#print product(value)

#2.
#SHORTEST WORD FUNCTION
wordy = ['word', 'worder', 'wordest']

def shortest(words):
    result = words[0]
    for w in words:
        if len(w) < len(result):
            result = w
        return result
    
#print shortest(wordy)

#3.
#AVERAGE FUNCTION
def average(numbers):
    result = 0
    for num in numbers:
        result = result + num
    return result / len(numbers)

#print average(value)

#4.
#DICE ROLLING
def dice():
    
    num = 10000

    rolls = {}
    for k in range(2, 13):
        rolls[k] = 0

    for k in range(num):
        first = random.randint(1, 6)
        second = random.randint(1, 6)
        if first == second:
                doubles+=1
        rolls[first+second]+=1

    for k in rolls:
        print('%d - %d' %(k, rolls[k]))
        
#dice()

#GUESSING GAME
def guessing_game():
    print("Think of a number between 1 and 1000.")
    min = 1
    max = 1000
    while (min < max):
        guess = (min + max) // 2
        answer = input("Is it more than {} (y/n)? ".format(guess))
        if answer.lower().startswith("y"):
            min = guess + 1
        else:
            max = guess
    # At this point min and max must be the same
    print("Your number is {}.".format(min))

guessing_game()

