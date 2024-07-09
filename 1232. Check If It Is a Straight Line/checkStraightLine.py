from itertools import islice


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) == 2:
            return True

        (x1, y1), (x2, y2) = coordinates[:2]
        if x1 == x2:
            for single_coordinates in itertools.islice(coordinates, 2, None):
                if single_coordinates[0] != x1:
                    return False
        elif y1 == y2:
            for single_coordinates in itertools.islice(coordinates, 2, None):
                if single_coordinates[1] != y1:
                    return False
        else:
            a = (y1 - y2) / (x1 - x2)
            b = y1 - (a * x1)
            for single_coordinates in itertools.islice(coordinates, 2, None):
                if single_coordinates[1] != (a * single_coordinates[0]) + b:
                    return False

        return True