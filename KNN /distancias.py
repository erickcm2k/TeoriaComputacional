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
        distances.append( (getEuclideanDistance(point, points[i]), points[i].family) )

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
def getFamily(knns):
    families = {}
    for i in range (0, len(knns)):    
        if knns[i][1] in families:
            families[knns[i][1]] += 1
        else:
            families[knns[i][1]] = 1
    
    families = sorted(families.items(), key = lambda x: x[1], reverse = True)
    return families[0][0]
    # family = str(families[0][0])
    # b = "()',"
    # for char in b:
    #     family = family.replace(char,"")

    # return family

p1 = Point(8, 2, "red")
p2 = Point(4, 3, "blue")
p3 = Point(9, 5, "red")
p4 = Point(5, 8, "blue")
p5 = Point(5, 2, "red")
p6 = Point(22, 4, "blue")
p7 = Point(12, 4, "red")
p10 = Point(11, 20)

points = []
points.append(p1)
points.append(p2)
points.append(p3)
points.append(p4)
points.append(p5)
points.append(p6)
points.append(p7)

distances = getKNN(p10, 5, points)
for distance in distances:
    print(distance)

p10.family = getFamily(distances)
points.append(p10)
for point in points:
    print(f'({point.x} , {point.y}) {point.family}')

