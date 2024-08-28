class Point:
    '''
    This is a 2-D point
    Attributes: x, y
    '''

    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def distance_from_origin(self):
        return ((self.x**2) + (self.y**2)) ** (1/2)

p1 = Point()
p2 = Point(1)
p3 = Point(1, 2)
p4 = Point(y=2)