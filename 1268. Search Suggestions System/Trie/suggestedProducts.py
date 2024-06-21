import heapq

class Solution:
    def suggestedProducts(
        self, products: List[str], search_word: str) -> List[List[str]]:

        class TrieNode:
            def __init__(self):
                self.children = {}
                self.is_end_of_word = False

        class Trie:
            def __init__(self):
                self.root = TrieNode()

            def insert(self, word):
                node = self.root
                for letter in word:
                    if letter not in node.children:
                        node.children[letter] = TrieNode()
                    node = node.children[letter]
                node.is_end_of_word = True

        letter_trie = Trie()
        for product in products:
            letter_trie.insert(product)

        def get_words_by_prefix(node, used_letters, rest_of_prefix, searched_words):
            if rest_of_prefix:
                letter = rest_of_prefix[0]
                if letter in node.children:
                    word = used_letters + letter
                    
                    if (
                        len(rest_of_prefix) == 1
                        and node.children[letter].is_end_of_word
                    ):
                        searched_words.append(word)
                        
                    get_words_by_prefix(
                        node.children[letter], word, rest_of_prefix[1:], searched_words
                    )
            else:
                for letter in node.children:
                    word = used_letters + letter
                    if node.children[letter].is_end_of_word:
                        searched_words.append(word)
                    get_words_by_prefix(node.children[letter], word, "", searched_words)

        suggested_products = []
        for i in range(len(search_word)):
            searched_products = []
            get_words_by_prefix(letter_trie.root, "", search_word[: i + 1], searched_products)
            if len(searched_products) > 3:
                searched_products = heapq.nsmallest(3, searched_products)
            elif len(searched_products) > 1:
                searched_products.sort()
            suggested_products.append(searched_products)

        return suggested_products