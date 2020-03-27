import math
class Point:

    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color

# O(1)
def getEuclideanDistance(P1, P2):
    distance = math.sqrt(math.pow(P1.x - P2.x, 2) + math.pow(P1.y - P2.y, 2)) 
    return distance 

# O(NlogN + N) -> O(NlogN)
def getKNN(point, k, points):
    distances = []
    for i in range(0, len(points)):
        distances.append( (getEuclideanDistance(point, points[i]), points[i].color) )

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
def getColor(knns):
    families = {}
    for i in range (0, len(knns)):    
        if knns[i][1] in families:
            families[knns[i][1]] += 1
        else:
            families[knns[i][1]] = 1
    
    families = sorted(families.items(), key = lambda x: x[1], reverse = True)
    return families[0][0]