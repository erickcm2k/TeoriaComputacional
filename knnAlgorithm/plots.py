import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np
import csv
import math

class Point:

    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color

points = []

with open('datasheet.txt') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        if line_count == 0:
            #print(f'Column names are: {", ".join(row)}')
            line_count += 1
        else:
            #print(f'\t ({row[0]}, {row[1]}) color: {row[2]}.')
            points.append(Point(row[0], row[1], row[2]))
            line_count += 1
    #print(f'Processed {line_count} lines.')

oneX = []
oneY = []
fiveX = []
fiveY = []
sevenX = []
sevenY = []

for i in range(len(points)):
    #print(f'{points[i].x} {points[i].y} {points[i].color}')
    if int(points[i].color) == 1:
        oneX.append(float(points[i].x))
        oneY.append(float(points[i].y))
    elif points[i].color == '5':
        fiveX.append(float(points[i].x))
        fiveY.append(float(points[i].y))
    elif points[i].color == '7':
        sevenX.append(float(points[i].x))
        sevenY.append(float(points[i].y))

print(oneX)
print(oneY)
print(fiveX)
print(fiveY)
print(sevenX)
print(sevenY)


plt.plot(oneX, oneY, 'bo')
plt.plot(fiveX, fiveY, 'go')
plt.plot(sevenX, sevenY, 'ro')  
# plt.ylabel('Y')
# plt.xlabel('X')
plt.show()