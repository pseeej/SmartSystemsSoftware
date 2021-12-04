global INF 
INF = float('inf')

class myTree:
    def __init__(self):
        self.tree = {}

    def addInfo(self, parent, children):
        self.tree[parent] = children

    
    def postorder(self, root):
        # Fill up with your own codes
        orderList = []

        if self.tree[root][0] != '.':
            leftList = self.postorder(self.tree[root][0])
            orderList += leftList
        
        if self.tree[root][1] != '.':
            rightList = self.postorder(self.tree[root][1])
            orderList += rightList

        orderList.append(root)

        return orderList
        
class myGraph:
    def __init__(self, vertex, matrix):
        self.vertex = vertex
        self.matrix = matrix
    
    def MST(self):
        # Fill up with your own codes
        v_list = []
        first_index = 0
        second_index = 0

        for i in range(len(self.vertex)):
            for j in range(len(self.vertex)):
                v_list.append((i+1, j+1, self.matrix[i][j]))
        
        # 가중치 작은 것부터 순서대로 정렬
        v_list = sorted(v_list, key = lambda vertex:vertex[2])

        # 각 vertex와 이어진 다른 vertex 기록 위함
        sets = []
        for i in range(len(self.vertex)):
            sets.append([i+1])

        mincost = 0
        for vertex in v_list:
            first, second, dist = vertex
            flag = True
            for s in range(len(sets)):
                # 사이클 발생 여부 확인
                if first in sets[s] and second in sets[s]:
                    flag = False
                    continue

                if first in sets[s]:
                    first_index = s
                if second in sets[s]:
                    second_index = s

            if flag == True:
                # 두 개의 vertex 연결
                sets[first_index] += sets[second_index]
                sets.pop(second_index)
                mincost += dist

            if len(sets[0]) == len(self.vertex):
                break

        return mincost