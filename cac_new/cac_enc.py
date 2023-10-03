import random
import datetime
import string

def list_xor(*lists):
    f = lists[0]
    length = range(len(f))
    for item in lists[1:]:
        f = [f[i] ^ item[i] for i in length]
    return f


class CACEncCore:
    def __init__(
        self,
        gen_size=8,
        seed=datetime.datetime.utcnow().timestamp(),
        alphabet=string.ascii_letters + string.digits,
        status_graph={0: {3: 1}, 1: {0: 0, 1: 0, 4: 0, 5: 0, 6: 0, 7: 0}},
        out_string_map=string.ascii_letters + string.digits,
    ):
        self.gen_size = gen_size
        self.seed = seed
        self.alphabet = alphabet
        self.alphabet_size = len(alphabet)
        self.status_graph = status_graph
        self.out_string_map = out_string_map
        self.out_string_map_size = len(out_string_map)
        self.alphabet_ref = [
            [0 for _ in range(gen_size)] for __ in range(len(alphabet))
        ]
        for i, char in enumerate(alphabet):
            random.seed(str(seed) + char)
            self.alphabet_ref[i] = random.choices([0, 1], k=gen_size)

    def next_state(self, curr, cnt):
        return self.status_graph.get(curr,{}).get(cnt, curr)

    def iterate(self, s, times=1):
        graph = [
            [0 for _ in range(self.gen_size + 2)] for __ in range(self.gen_size + 2)
        ]
        for i, char in enumerate(s):
            graph[(i % self.gen_size) + 1] = list_xor(
                graph[(i % self.gen_size) + 1],
                [0, *self.alphabet_ref[ord(char) % self.alphabet_size], 0],
            )
        return self.iterate_map(graph, times)

    def iterate_map(self, current_map, times=1):
        graph_prev = current_map
        graph_curr = [
            [0 for _ in range(self.gen_size + 2)] for __ in range(self.gen_size + 2)
        ]
        for _ in range(times):
            for li_i in range(1, self.gen_size + 1):
                for li_j in range(1, self.gen_size + 1):
                    cnt = (
                        graph_prev[li_i - 1][li_j - 1]
                        + graph_prev[li_i - 1][li_j]
                        + graph_prev[li_i - 1][li_j + 1]
                        + graph_prev[li_i][li_j - 1]
                        + graph_prev[li_i][li_j + 1]
                        + graph_prev[li_i + 1][li_j - 1]
                        + graph_prev[li_i + 1][li_j]
                        + graph_prev[li_i + 1][li_j + 1]
                    )
                    graph_curr[li_i][li_j] = self.next_state(
                        graph_prev[li_i][li_j], cnt
                    )
            graph_prev = graph_curr
        ret_str = ''
        for line in graph_prev[1:-1]:
            decimal = int(''.join([str(i) for i in line[1:-1]]),2)
            char = self.out_string_map[decimal % self.out_string_map_size]
            ret_str += char
        return ret_str
