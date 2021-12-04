import treeGraph as tg


t = tg.myTree()
t.addInfo('A', ['B', 'C'])
t.addInfo('B', ['D', '.'])
t.addInfo('C', ['E', 'F'])
t.addInfo('E', ['.', '.'])
t.addInfo('F', ['.', 'G'])
t.addInfo('D', ['.', '.'])
t.addInfo('G', ['.', '.'])
treeResult = t.postorder('A')
print(treeResult)



myVertex = [1, 2, 3, 4]
myMatrix = [[tg.INF, 3, 2, 5], 
            [3, tg.INF, 4, 2], 
            [2, 4, tg.INF, 7], 
            [5, 2, 7, tg.INF]]

g = tg.myGraph(myVertex, myMatrix)

graphResult = g.MST()
print(graphResult)
