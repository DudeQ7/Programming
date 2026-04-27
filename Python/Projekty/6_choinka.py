def draw_tree(height):
  # Loop through each row of the tree
  for i in range(1, height + 1):
    # Print the spaces before the asterisks on each row
    for j in range(height - i):
      print(" ", end="")
    # Print the asterisks on each row
    for j in range(2 * i - 1):
      print("*", end="")
    # Move to the next line
    print()
# Call the function to draw a tree with a height of 5
draw_tree(5)