#pip install mysql-connector-python 
import mysql.connector
mydb = mysql.connector.connect(
    host="localhost",
    user="yourusername",
    password="yourpassword"
    database="mydatabase"
)
kwerenda = mydb.cursor()
kwerenda.execute("CREATE DATABASE mydatabase")