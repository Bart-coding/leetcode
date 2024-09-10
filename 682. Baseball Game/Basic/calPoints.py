class Solution:
    def calPoints(self, operations: List[str]) -> int:

        record = []

        for op in operations:
            try:
                record.append(int(op))
            except ValueError:
                if op == "+":
                    record.append(record[-2] + record[-1])
                elif op == "D":
                    record.append(2 * record[-1])
                else:
                    del record[-1]

        return sum(record)