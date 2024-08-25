age = input("Insert your age: ")

if int(age) > 18:
    print("You are of age.")
elif int(age) == 18:
    print("You've just turned 18, congrats!")
else:
    print("You are still a minor.")