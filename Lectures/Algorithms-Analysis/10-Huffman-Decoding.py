import heapq

class node:
    def __init__(self, freq, symbol, left=None, right=None, huff=''):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = huff
    def __lt__(self, x):
        return x.freq > self.freq

def print_nodes(node, codes, val = ''):
    new_val = val + str(node.huff)
    if (node.left):
        print_nodes(node.left, codes, new_val)
    if (node.right):
        print_nodes(node.right, codes, new_val)
    if (not node.left and not node.right):
        print(node.symbol, "->", new_val)
        codes[node.symbol] = new_val

def huffman_codes(chars, freq):
    nodes = []
    for i in range(len(chars)):
        nodes.append(node(freq[i], chars[i]))
    heapq.heapify(nodes)
    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        left.huff = 0
        right.huff = 1
        new_node = node(left.freq+right.freq, 
                        left.symbol+right.symbol, 
                        left, 
                        right)
        heapq.heappush(nodes, new_node)
    root = heapq.heappop(nodes)
    return root

def encoding(s, codes):
    encoded_string = ''
    for i in s: encoded_string += codes[i]
    return encoded_string

def decoding(root, encoded_string):
    decoded_string = ''
    curr = root
    for i in range(len(encoded_string)):
        curr = curr.left if encoded_string[i] == '0' else curr.right
        if curr.left == None and curr.right == None:
            decoded_string += curr.symbol
            curr = root
    return decoded_string

s = "aafffafffcccaffffbeeefffffbbcccfffffccceeeefffdddeeeeeffccffddfffbbbbbbdddafffffddddeeeeffffcdffffff"
chars = list(set(s))
freq  = [s.count(i) for i in chars]
root = huffman_codes(chars, freq)
codes = {}
print_nodes(root, codes)
encoded_string = encoding(s, codes)
print('Encoded huffman data:\n' + encoded_string)
decoded_string = decoding(root, encoded_string)
print('Decoded huffman data:\n' + decoded_string)
