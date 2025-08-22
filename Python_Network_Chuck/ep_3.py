#type = fajne do sprawdzania typow danych 
#Coffee Shop - Robot Barista_v2c
print("Welcome, to NetworkChuck.coffee!!!!!!!!!!!")
name = "Paul"
name = input("What is your name: ")
print("Hi, " + name+" thanks, for coming in today")
price = 10
menu= input("What do you fancy today: "+"\n1.Cappucino - $10\n"+"2.Flat White - $10\n"+"3.Cortado - $10\n"+"Choice: ")
ammount = int(input("How many coffess do you fancy: "))
total_ammount = price * ammount
print("Excellent!\nYour total ammount is: ",total_ammount," USD")
print("Your "+str(ammount)+" Coffees should be ready shortly")