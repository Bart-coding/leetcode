class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        remaining_asteroids = []
        for asteroid in asteroids:
            if asteroid > 0:
                remaining_asteroids.append(asteroid)
            else:
                left_dir_asteroid_size = -asteroid
                exploded = False
                while remaining_asteroids and remaining_asteroids[-1] > 0:
                    if left_dir_asteroid_size > remaining_asteroids[-1]:
                        remaining_asteroids.pop()
                    elif left_dir_asteroid_size < remaining_asteroids[-1]:
                        exploded = True
                        break
                    else:
                        remaining_asteroids.pop()
                        exploded = True
                        break
                if not exploded:
                    remaining_asteroids.append(asteroid)
        return remaining_asteroids