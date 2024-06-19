class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        total_cost = 0
        if 2 * candidates > len(costs):
            heapify(costs)
            for i in range(k):
                total_cost += heappop(costs)
        else:
            workers_to_hire = []
            for i in range(candidates):
                heappush(workers_to_hire, (costs[i], 'L'))
            for i in range(1, candidates + 1):
                heappush(workers_to_hire, (costs[-i], 'R'))
            next_left_candidate = candidates
            next_right_candidate = len(costs) - candidates - 1
            for i in range(k):
                worker_cost, side = heappop(workers_to_hire)
                total_cost += worker_cost
                if next_left_candidate <= next_right_candidate:
                    if side == 'L':
                        heappush(workers_to_hire, (costs[next_left_candidate], 'L'))
                        next_left_candidate += 1
                    else:
                        heappush(workers_to_hire, (costs[next_right_candidate], 'R'))
                        next_right_candidate -= 1
        return total_cost