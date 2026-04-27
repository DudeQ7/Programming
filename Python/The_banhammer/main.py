#pip install dotenv mysql-connector-python
import mysql.connector
import os
from dotenv import load_dotenv
load_dotenv() 
mydb = mysql.connector.connect(
    host = os.getenv('HOST_NAME'),
    user = os.getenv('DB_USER'),
    password = os.getenv('DB_PASSWORD'),
    database = os.getenv('DB_NAME')
  
)
mycursor = mydb.cursor()
mycursor.execute("Select * from twfjqjet.test")
myresult = mycursor.fetchall()
for x in myresult:
    print(x)