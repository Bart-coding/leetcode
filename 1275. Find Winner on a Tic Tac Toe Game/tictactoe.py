class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:

        if len(moves) < 3:
            return "Pending"

        A_rows = [0, 0, 0]
        A_cols = [0, 0, 0]
        A_diags = [0, 0]
        B_rows = [0, 0, 0]
        B_cols = [0, 0, 0]
        B_diags = [0, 0]

        for i in range(len(moves)):
            if i % 2 == 0:
                A_rows[moves[i][0]] += 1
                A_cols[moves[i][1]] += 1
                if moves[i][0] == moves[i][1]:
                    A_diags[0] += 1
                    if moves[i][0] == 1:
                        A_diags[1] += 1
                if abs(moves[i][0] - moves[i][1]) == 2:
                    A_diags[1] += 1
            else:
                B_rows[moves[i][0]] += 1
                B_cols[moves[i][1]] += 1
                if moves[i][0] == moves[i][1]:
                    B_diags[0] += 1
                    if moves[i][0] == 1:
                        B_diags[1] += 1
                if abs(moves[i][0] - moves[i][1]) == 2:
                    B_diags[1] += 1

        if 3 in A_rows or 3 in A_cols or 3 in A_diags:
            return "A"
        if 3 in B_rows or 3 in B_cols or 3 in B_diags:
            return "B"

        if len(moves) < 9:
            return "Pending"
        else:
            return "Draw"