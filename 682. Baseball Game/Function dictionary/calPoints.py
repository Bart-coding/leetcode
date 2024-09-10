class Solution:
    def calPoints(self, operations: List[str]) -> int:

        record = []
        record_prev_two_sum = lambda: record.append(record[-2] + record[-1])
        record_double_of_prev = lambda: record.append(2 * record[-1])
        remove_prev = lambda: record.pop()

        function_dict = {
            "+": record_prev_two_sum,
            "D": record_double_of_prev,
            "C": remove_prev
        }

        for op in operations:
            try:
                record.append(int(op))
            except ValueError:
                function_dict[op]()

        return sum(record)