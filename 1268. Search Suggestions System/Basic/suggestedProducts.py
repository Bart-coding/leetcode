import heapq

class Solution:
    def suggestedProducts(
        self, products: List[str], search_word: str) -> List[List[str]]:

        suggested_products = [[]]
        for product in products:
            if search_word[0] == product[0]:
                suggested_products[0].append(product)
        for i in range(1, len(search_word)):
            suggested_products.append([])
            for product in suggested_products[i - 1]:
                if i < len(product) and search_word[i] == product[i]:
                    suggested_products[i].append(product)
        
        for i in range(len(suggested_products)):
            if len(suggested_products[i]) > 3:
                suggested_products[i] = heapq.nsmallest(3, suggested_products[i])
            elif len(suggested_products[i]) > 1:
                suggested_products[i].sort()
        
        return suggested_products