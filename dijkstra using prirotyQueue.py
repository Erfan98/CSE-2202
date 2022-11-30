# Input Test Cases
# 6
# 8
# 1 2 2
# 1 3 4
# 2 4 7
# 2 3 1
# 3 5 3
# 5 4 2
# 5 6 5
# 4 6 1
# 1

from queue import PriorityQueue
from math import inf
def dijkstra(graph,source,nodes):
    distances =[inf for i in range(nodes+1)]
    visited = []
    pq = PriorityQueue()
    pq.put((0,source))
    distances[source] = 0
    while(not pq.empty()):
        distance,vertex = pq.get()
        if vertex in visited: continue
        else:
            visited.append(vertex)
            for child in range(len(graph[vertex])):
                child_vertex,child_weight = graph[vertex][child]
                if(distances[vertex]+child_weight<distances[child_vertex]):
                    distances[child_vertex] = distances[vertex]+child_weight
                    pq.put((distances[child_vertex],child_vertex))

    return distances

total_nodes = int(input())
total_edges = int(input())
graph ={i:[] for i in range(total_nodes+1)}
for i in range(total_edges):
    firstNode,second_node,weight = map(int,input().split())
    if firstNode not in graph:
        graph[firstNode] = [(second_node,weight)]
    else:
        graph[firstNode].append((second_node,weight))
source = int(input())
distance_arr = dijkstra(graph,source ,total_nodes)

for i in range(1,len(distance_arr)):
    print("From vertex 1 to {} minimum distance is {}".format(i,distance_arr[i]))
