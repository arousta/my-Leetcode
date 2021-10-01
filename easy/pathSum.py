import sys

sys.path.append('..')
from make_binaryTree_BFS import make_binaryTree


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if root is None: return False
        
        sub_target = targetSum - root.val
        
        if not (root.left or root.right):
            # leaf node, check if the target sum found
            return sub_target==0
        
        found_left  = self.hasPathSum(root.left , sub_target) if root.left  else False
        found_right = self.hasPathSum(root.right, sub_target) if root.right else False
            
        return found_left or found_right
 

if __name__=="__main__":
    l = [5,4,8,11,'null',13,4,7,2,'null','null','null',1]
    root = make_binaryTree(TreeNode,l)
    S = Solution()
    path_found = S.hasPathSum(root,22)
