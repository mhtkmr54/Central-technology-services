from heapq import heappush, heappop

def Dijkstra(graph, start, n):
    print "Entering Dijkstra"
    A = [None] * (n+1)
    queue = [(0, start)]
    while queue:
        print queue;
        print "queue at beginning of while"
        path_len, v = heappop(queue)
        if A[v] is None:
            A[v] = path_len
            for w, edge_len in graph[v].items():
                if A[w] is None:
                    heappush(queue, (path_len + edge_len, w))
    print "to be retuened", A
    return A

graph = {1: {8: 994, 2: 732, 6: 851}, 2: {9: 839, 3: 468, 4: 652, 5: 227, 1: 732}, 3: {2: 468}, 4: {8: 653, 2: 652, 7: 209}, 5: {8: 910, 2: 227}, 6: {1: 851}, 7: {4: 209}, 8: {1: 994, 4: 653, 5: 910}, 9: {2: 839}}
Dijkstra(graph, 1, 9)
