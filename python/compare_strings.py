import networkx as nx
import random

g=nx.read_gml ("dolphins.gml")

sub_track_list = ['iphone 6', 'iphone 5', 'moto x2', 'galaxy s6']
tweets_data = ['Eu queria um iphone 6 seriao', 'nao gostei do moto x2', 'iphone 5 e coisa do passado', 'abc123']

for text in tweets_data:
    for text2 in sub_track_list:
        if text2 in text:
            print(text2)

a=g.nodes()
b=random.choice(a)          
for text3 in a:
    for text4 in b:
        if text4 in text3:
          print(text4)
          print(text3)
          
          
