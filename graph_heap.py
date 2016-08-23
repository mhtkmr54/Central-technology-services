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

def l2i(l):
    r = 0
    for x in l: r += 1<<(x-1)
    print "R IS TO BE RETIRNED FOR L21 for ",r , " FOR llllllllll ---> ",l
    return r

def check(r,f,g):
    if f == g: return True
    for x in r:
        if x | f == g: return True
    return False

def solve(n,m,k,ds,graph):
    r = set()
    g = 2 ** k - 1
    A = [None] * (n+1)
    queue = [(0, 1, ds[1])]
    while queue:
        path_len, v, f = heappop(queue)
        if A[v] is None:
            if v == n:
                if check(r,f,g): return path_len
                r.add(f)
            A[v] = {f:path_len}
            for w, edge_len in graph[v].items():
                nf = f | ds[w]
                if A[w] is None or nf not in A[w]:
                    heappush(queue, (path_len + edge_len, w, nf))
        elif f not in A[v]:
            if v == n:
                if check(r,f,g): return path_len
                r.add(f)
            A[v][f] = path_len
            for w, edge_len in graph[v].items():
                nf = f | ds[w]
                if A[w] is None or nf not in A[w]:
                    heappush(queue, (path_len + edge_len, w, nf))

n,m,k = map(int,raw_input().strip().split())
dsl = {}
ds = {}

for i in xrange(n):
    l = map(int,raw_input().strip().split())[1:]
    print "l types of fish"
    print l
    dsl[i+1] = set(l)
    ds[i+1] = l2i(l)

print "Set OF FISH FOR EACH CENTER AS A dict", dsl





graph = {i:{} for i in xrange(1,n+1)}
print "B4 graph",graph
for i in xrange(m):
    x,y,z = map(int,raw_input().strip().split())
    graph[x][y] = z
    graph[y][x] = z
print "populated graph"
print graph
print solve(n,m,k,ds,graph)
