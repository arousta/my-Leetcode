from collections import deque

def make_binaryTree(TreeNode,valList):
    """
    Convert leetcode compact tree representation
    into a real binary tree. For example:
      [5,4,8,11,null,13,4,7,2,null,null,null,1]
      TreeNode: The type of nodes. Assumes node class
      has .left,.right,.val attributes and can be
      initialized by node val like TreeNode(10)
    """
    valList.reverse()
    root = TreeNode(valList.pop())
    NodeQue = deque([root])

    while valList:
        Node = NodeQue.popleft()

        left_val = valList.pop()
        if isinstance(left_val,int):
            Node.left = TreeNode(left_val)
            NodeQue.append(Node.left)

        right_val = valList.pop()
        if isinstance(right_val,int):
            Node.right = TreeNode(right_val)
            NodeQue.append(Node.right)
    
    return root