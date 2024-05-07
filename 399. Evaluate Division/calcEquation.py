class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
        variables_graph: dict[str, dict[str, int]] = {}
        for i in range(len(equations)): # populate the graph
            if equations[i][0] not in variables_graph:
                variables_graph[equations[i][0]] = {}
            if equations[i][1] not in variables_graph:
                variables_graph[equations[i][1]] = {}
            variables_graph[equations[i][0]][equations[i][1]] = values[i]
            variables_graph[equations[i][1]][equations[i][0]] = 1 / values[i]
        answers: list = []
        for start_node, end_node in queries: # resolve queries
            if start_node not in variables_graph or end_node not in variables_graph:
                answers.append(-1.0)
                continue
            elif start_node == end_node:
                answers.append(1.0)
                continue
            elif start_node in variables_graph and end_node in variables_graph[start_node]:
                answers.append(variables_graph[start_node][end_node])
                continue
            visited_nodes = set()
            visited_nodes.add(start_node)
            answer = -1.0
            def dfs(node: str, result: float): # search for end_node
                nonlocal answer
                visited_nodes.add(node)
                if node == end_node:
                    answer = result
                    return
                for next_node in variables_graph[node].keys():
                    if next_node not in visited_nodes:
                        dfs(next_node, result * variables_graph[node][next_node])
            dfs(start_node, 1.0)
            answers.append(answer)
        return answers