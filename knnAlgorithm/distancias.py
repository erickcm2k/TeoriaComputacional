import matplotlib.pyplot as plt
import csv
import math

class Point:

    def __init__(self, x, y, *family):
        self.x = x
        self.y = y
        self.family = family

def getEuclideanDistance(P1, P2):
    distance = math.sqrt(math.pow(P1.x - P2.x, 2) + math.pow(P1.y - P2.y, 2)) 
    return distance 

def getKNN(point, k, points):
    distances = []
    for i in range(0, len(points)):
        distances.append( (getEuclideanDistance(point, points[i]), points[i].family[0]) )

    distances = sorted(distances, key = lambda x: x[0])   
    
    # print('\nOrdered distances: \n')
    # for distance in distances:
    #     print(distance)

    #print('\nK nearest neighbours\n')
    knns = []
    if len(distances) >= k:
        for i in range (0, k):
            knns.append(distances[i])
        return knns 
    else:
        print('Use a smaller K value ')
        return []

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

def readPointsFromCSV(fileName):
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
                points.append(Point(float(row[0]), float(row[1]), row[2]))
                line_count += 1
            #print(f'Processed {line_count} lines.')
    return points

def readTestPointsFromCSV(fileName):
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
                points.append(Point(float(row[0]), float(row[1])))
                line_count += 1
            #print(f'Processed {line_count} lines.')
    return points    

def addNewPoint(newPoint, points):
    distances = getKNN(newPoint, 5, points)
    newPoint.family = getfamily(distances)
    return newPoint

def checkNewPoint(newPoint, points):
    distances = getKNN(newPoint, 5, points)
    newPoint.family = getfamily(distances)
    print(f'({newPoint.x}, {newPoint.y}) {newPoint.family[0]}')


if __name__ == "__main__":

    points = readPointsFromCSV('datasheet.txt')
    testPoints = readTestPointsFromCSV('testDataset.txt')

    print('\nPoints extracted from dataset: \n')
    for point in points:
        print(f'({point.x}, {point.y}) {point.family[0]}')

    print('\nPoints added: \n')
    for point in testPoints:
        checkNewPoint(point, points)

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
    plt.ylabel('Erick Castañeda Martínez')
    plt.xlabel('K - Nearest Neighbours')
    #plt.show()