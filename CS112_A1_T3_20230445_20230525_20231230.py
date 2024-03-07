#Title: CS112_A1_T3_20230445_20230525_20231230
#purpose: Solution to 6 problems
#date: 27/2/2023
#Authors(ID)(Solved Problems):
#    Nour Alaa Hassan(20230445)(problem1,problem4)
#    Ahmed Ali Ahmed Somida(20230525)(Problem2,problem5)
#    Demiana Farid Mechael Asaad(20231230)(problem3,problem5)
# version: 1.0
def Grading_System_P1():
    print("<< Welcome >>")
    while True:
        print("A: start program to know your grade")
        print("B: end program")
        desire = input()

        if desire.lower() == 'a':
            print("Enter your mark")  # if the mark >= 50 you are successful
            try:
                mark = int(input())
            except ValueError:        # if user input value error
                print("Please enter a valid integer for the mark.")
                continue

            if 0 <= mark <= 100:
                if mark >= 90:
                    print("Your grade is: A+")
                elif mark >= 85:
                    print("Your grade is: A")
                elif mark >= 80:
                    print("Your grade is: B+")
                elif mark >= 75:
                    print("Your grade is: B")
                elif mark >= 70:
                    print("Your grade is: C+")
                elif mark >= 65:
                    print("Your grade is: C")
                elif mark >= 60:
                    print("Your grade is: D+")
                elif mark >= 50:
                    print("Your grade is: D")
                else:
                    print("Unfortunately, you are failing")
            else:
                print("Please enter a valid mark")
        elif desire.lower() == 'b':
            break
        else:
            print("Please choose A or B")

def armstrong_num_P2():
    # welcome message for the game
    print("Welcome to Armstrong number detection game")

    # prompting the user to enter a positive number and checking if it is an integer

    while True:
        try:
            number = int(input("Enter a positive number you want to check: "))
            #if the number is negative ask for the number again
            if number<=0:
                print("this number is negative")
            #if the number is positive continue the program
            else:
                break
        except ValueError:
            print("Invalid input")

    # declare the sum variable that will be compared to the number
    sum = 0

    # converting the input to a string to find its length and the power raised for each number calculating its sum
    string_number = str(number)
    power = len(string_number)

    # for loop to calculate the sum
    for digit in string_number:
        sum += int(digit) ** power

    # checking if the sum equals the original number
    if sum == number:
        print(f"{number} is an Armstrong number")
    else:
        print(f"{number} is not an Armstrong number")

def Pi_calculator_P3():
    #Welcome message and the purpose of the program
    print("Hello, This is a program to calculat value of Pi")

    #iterating by the number of turns
    num_iterations = int(input("Please enter number of turns: "))

    #intial values
    denominator = 1
    pi = 0.0

    #calculate as the Leibniz formula
    for i in range(1, num_iterations+1):
        if i%2 == 0:
           pi -= (1/denominator)
        else:
            pi += (1/denominator)

        denominator += 2

    print ("The value of Pi is: ", pi*4) #print the result by 4 to get the accurate value


def ceaser_Cypher_P4():
    print("Welcome to ceaser cypher program")
    print("Please enter your message")
    message = input()  # Take message from the user
    len_message = len(message)  # Define the length of the message
    print(f"the {message} become==> ")
    # This loop is for shifting each character to the next one.
    for i in range(len_message):

        # Special case for the letter Z
        if message[i] == 'z':
            print('a', end='')
        elif message[i] == 'Z':
            print('A', end='')

        # Determine the range of lowercase letters in English letters by ASCII
        elif 'a' <= message[i] < 'z':
            ASCII = ord(message[i]) + 1  # Shifting to the next character
            print(chr(ASCII), end='')

        # Determine the range of uppercase letters in English letters by ASCII
        elif 'A' <= message[i] < 'Z':
            ASCII = ord(message[i]) + 1  # Shifting to the next character
            print(chr(ASCII), end='')

        elif message[i] == ' ':
            print(' ', end='')  # Print the space as same

        else:
            print(message[i], end='')  # Print other characters as the same

def comparing_lists_P5():
    print("welcome to comparing lists program")
    #defining 2 lists to be compared
    list1=[]
    list2=[]
    #getting the length of the first list
    while True:
        length1 = int(input("enter the length of the first list "))
        if length1 > 0:
            break
    # getting the first list from the user
    for i in range(length1):
        #validating the input
        while True:
            try:
                number = int(input(f"enter the {i+1}th number of the list "))
            except ValueError:
                print("Invalid input. Please enter a valid number.")
            else:
                list1.append(number)
                break
    print(list1)
    #getting the length of the second list
    while True:
        length2 = int(input("enter the length of the second list "))
        if length2 >0:
            break
    #getting the elements of the second list
    for i in range(length2):
        while True:
            try:
                number = int(input(f"enter the {i+1}th number of the second list "))
            except ValueError:
                print("Invalid input. Please enter a valid number.")
            else:
                list2.append(number)
                break
    print(list2)
    #checking if the two lengths are not equal the program ends and the lists are not equal
    if(length1!=length2):
        print("the two lists are not equal because they have different length")
        return
    #defining bool that is true as the number is present on the other list
    checker=1
    #looping on the first list to find if all the elements are present in the second one
    for i in list1:
        if i not in list2:
            checker=0
            print("the two lists are not equal")
            return
    # doing the same for list two in case that the user repeat 2 elements in the list
    for i in list2:
        if i not in list1:
            checker=0
            print("the two lists are not equal")
            return
    if checker==1:
        print("the lists are equal")
        return

def Factors_Calculator_P6():
    # Welcome message and purpose of the program
    print("Hello! This is a program to find all factors of a positive integer")

    while True:
        try:
        # Get input as an integer
            num = int(input("Please enter a positive integer: "))

        # Check if the number is positive
            while num <= 0:
                num = int(input("Please enter a positive integer: "))

        # Find factors and print on the same line
            print("Factors:", end=" ")
            for i in range(1, num + 1):
                if num % i == 0:
                    print(i, end=" ")

            break  # Exit the loop if input and factorization are successful

        except ValueError:
        # Handle non-integer input
            print("Please enter a valid integer.")

while True:
    print("\nchoose the operation you want to do\n"
          "A) Start problem 1\n"
          "B) Start problem 2\n"
          "C) Start problem 3\n"
          "D) Start problem 4\n"
          "E) Start problem 5\n"
          "F) Start problem 6\n"
          "Z) Exit the program")
    choice = input().upper()
    while choice not in ['A', 'B', 'C', 'D', 'E', 'F', 'Z']:
        choice = input("Please enter a choice from the menu\n").upper()
    if choice == 'A':
        Grading_System_P1()
    if choice == 'B':
        armstrong_num_P2()
    if choice == 'C':
        Pi_calculator_P3()
    if choice == 'D':
        ceaser_Cypher_P4()
    if choice == 'E':
        comparing_lists_P5()
    if choice == 'F':
        Factors_Calculator_P6()
    if choice == 'Z':
        print("Good bye!")
        break
