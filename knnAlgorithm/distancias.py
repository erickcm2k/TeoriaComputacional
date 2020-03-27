import matplotlib.pyplot as plt
import numpy as np
import csv
import math
class Point:

    def __init__(self, x, y, *family):
        self.x = x
        self.y = y
        self.family = family

# O(1)
def getEuclideanDistance(P1, P2):
    distance = math.sqrt(math.pow(P1.x - P2.x, 2) + math.pow(P1.y - P2.y, 2)) 
    return distance 

# O(NlogN + N) -> O(NlogN)
def getKNN(point, k, points):
    distances = []
    for i in range(0, len(points)):
        distances.append( (getEuclideanDistance(point, points[i]), points[i].family[0]) )

    distances = sorted(distances, key = lambda x: x[0])   
    
    print('\nOrdered distances: \n')
    for distance in distances:
        print(distance)

    print('\nK nearest neighbours\n')
    knns = []
    if len(distances) >= k:
        for i in range (0, k):
            knns.append(distances[i])
        return knns 
    else:
        print('Use a smaller K value ')
        return []

# O(N + NlogN) -> O(NlogN)
def getfamily(distances):
    families = {}
    for i in range (0, len(distances)):    
        if distances[i][1] in families:
            families[distances[i][1]] += 1
        else:
            families[distances[i][1]] = 1
    
    families = sorted(families.items(), key = lambda x: x[1], reverse = True)
    return families[0][0]
    # family = str(families[0][0])
    # b = "()',"
    # for char in b:
    #     family = family.replace(char,"")

    # return family

def readFromCSV(fileName):
    points = []
    with open(fileName) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
              #  print(f'Column names are: {", ".join(row)}')
                line_count += 1
            else:
             #   print(f'\t ({row[0]}, {row[1]}) family: {row[2]}.')
                points.append(Point(row[0], row[1], row[2]))
                line_count += 1
            #print(f'Processed {line_count} lines.')
    return points

def addNewPoint(Point, points):
    a = 10


points = readFromCSV('datasheet.txt')
testPoints = readFromCSV('testDataset.txt')

# p10 = Point(11, 20)
# distances = getKNN(p10, 5, points)
# for distance in distances:
#     print(distance)

# p10.family = getfamily(distances)
# points.append(p10)
# for point in points:
#     print(f'({point.x} , {point.y}) {point.family}')





# Los datos de esta línea para abajo son únicamente para graficar

oneX = []
oneY = []
fiveX = []
fiveY = []
sevenX = []
sevenY = []

for i in range(len(points)):
    #print(f'{points[i].x} {points[i].y} {points[i].family[0]}')
    if points[i].family[0] == '1':
        oneX.append(float(points[i].x))
        oneY.append(float(points[i].y))
    elif points[i].family[0] == '5':
        fiveX.append(float(points[i].x))
        fiveY.append(float(points[i].y))
    elif points[i].family[0] == '7':
        sevenX.append(float(points[i].x))
        sevenY.append(float(points[i].y))

plt.plot(oneX, oneY, 'bo')
plt.plot(fiveX, fiveY, 'go')
plt.plot(sevenX, sevenY, 'ro')  
plt.ylabel('Y')
plt.xlabel('X')
plt.show()


