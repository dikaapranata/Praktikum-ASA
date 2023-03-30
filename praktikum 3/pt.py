# Input: text T
T = input()

# Input: pattern P
P = input()

# Import re module
import re

# Find all occurrences of P in T using re.finditer
matches = re.finditer(P,T)

# Initialize count of occurrences
count = 0

# Initialize list of start and end indices
indices = []

# Loop through each match object
for match in matches:
    # Increment count by 1
    count += 1
    
    # Get start and end indices of match using match.start() and match.end()
    start = match.start()
    end = match.end() - 1
    
    # Append a tuple of start and end indices to indices list
    indices.append((start,end))

# Print the output 
if count == 0:
    # If no occurrence is found, print 0
    print(0)
else:
    # If some occurrences are found, print count and indices list 
    print(count)
    print(*indices)