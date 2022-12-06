from math import inf
def bellmanford(edges,nodes,source):
    distances =[inf for i in range(nodes)]
    distances[source] = 0
    for _ in range(nodes-1):
        for i in edges:
            if distances[i[0]] != inf and distances[i[0]]+i[2]< distances[i[1]]:
                distances[i[1]]=distances[i[0]]+i[2]
    return distances

total_nodes = int(input())
total_edges = int(input())
edges = []
for _ in range(total_edges):
    edges.append(tuple(map(int,input().split())))
source = int(input())
dist = bellmanford(edges,total_nodes,source)

for i in range(len(dist)):
    print("From vertex {} to {} minimum distance is {}".format(source,i,dist[i]))

# 6
# 7
# 3 2 6
# 5 3 1
# 0 1 5
# 1 5 -3
# 1 2 -2
# 3 4 -2
# 2 4 3
# 0

# 5
# 4
# 0 1 1
# 1 2 1
# 2 3 1
# 3 4 1
# 0

# 5
# 8
# 0 1 -1
# 0 2 4
# 1 2 3
# 1 3 2
# 1 4 2
# 3 2 5
# 3 1 1
# 4 3 -3
# 0




