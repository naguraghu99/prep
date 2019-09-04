class BST:
    RootNode = None
    
    def Insert(self, rootNode, newNode):
        newNode.Level = rootNode.Level + 1
        level = newNode.Level
        if newNode.Value > rootNode.Value:
            if rootNode.Right == None:
                # print ('Inserting Node with value ',newNode.Value,'at level',newNode.Level)
                rootNode.Right = newNode
                
            else:
                level = self.Insert(rootNode.Right, newNode)
        elif newNode.Value < rootNode.Value or newNode.Value == rootNode.Value:
            if rootNode.Left == None:
                # print ('Inserting Node with value ',newNode.Value,'at level',newNode.Level)
                rootNode.Left = newNode
            else:
                level = self.Insert(rootNode.Left, newNode)
        return level
    
class Node:
    Left = None
    Right = None
    Value = 0
    Level = 0
    
def solve (A,N):
    # Return a list of N elements, ith element representing level of A[i]
    # Write your code here
        
    bst = BST()
    rootNode = Node()
    rootNode.Value = A[0]
    rootNode.Level = 1
    levels = [1]
    for element in A[1:]:
        newNode = Node()
        newNode.Value = element
        level = bst.Insert(rootNode, newNode)
        levels.append(level)
    #print (levels)
    return levels
    
    

    

# N = int(input())
# A = list(map(int, input().split()))
N = 7
A = [15,9,7,8,2,19,10]


out_ = solve(A,N)
print (' '.join(map(str, out_)))
