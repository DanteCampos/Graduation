# Generating graphs
# n vertices
# p probability to connect each pair of vertices
from networkx.generators.random_graphs import erdos_renyi_graph
from networkx import write_edgelist
import os
from datetime import datetime as dt

print("Generating...\n")
now = dt.now()
for p in [0.25, 0.5, 0.75]:
  if not os.path.exists(str(p)):
    os.makedirs(str(p))
  for n in range(50, 701, 50):
    g = erdos_renyi_graph(n, p)
    write_edgelist(g, str(p)+"/"+str(n)+"."+str(len(g.edges))+".graph", data=False)
after = dt.now()

print("Generating time:")
print (after-now)