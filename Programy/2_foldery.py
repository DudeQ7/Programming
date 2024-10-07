import os 
directory = "Rysunek_"
parent_dir = "E:\Gimp"
i =40
for i in range(9,40):
    print("Folder numer: "+ str(i) + "Stworzony BRAWO :) ")
    os.makedirs(os.path.join(parent_dir,directory)+str(i),exist_ok=True)