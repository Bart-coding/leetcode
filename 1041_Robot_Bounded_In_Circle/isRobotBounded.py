class Solution:
    def isRobotBounded(self, instructions: str) -> bool:

        if "G" not in instructions:
            return True
        if "L" not in instructions and "R" not in instructions:
            return False

        x = 0
        y = 0
        direction = 0

        for instruction in instructions:
            if instruction == "G":
                if direction == 0:
                    y += 1
                elif direction == 1:
                    x += 1
                elif direction == 2:
                    y -= 1
                else:
                    x -= 1
            if instruction == "L":
                direction = (direction - 1) % 4
            if instruction == "R":
                direction = (direction + 1) % 4

        if x == 0 and y == 0 or direction != 0:
            return True
        return False
      
