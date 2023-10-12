# Python3 program to implement optimized delete in BST.
 
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
 
# A utility function to do inorder traversal of BST
def inorder(root):
    if root is not None:
        inorder(root.left)
        print(root.key, end=' ')
        inorder(root.right)
 
# A utility function to insert a new node with given key in BST
def insert(node, key):
    # If the tree is empty, return a new node
    if node is None:
        return Node(key)
 
    # Otherwise, recur down the tree
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
 
    # return the (unchanged) node pointer
    return node
 
# Given a binary search tree and a key, this function
# deletes the key and returns the new root
def deleteNode(root, k):
    # Base case
    if root is None:
        return root
 
    # Recursive calls for ancestors of
    # node to be deleted
    if root.key > k:
        root.left = deleteNode(root.left, k)
        return root
    elif root.key < k:
        root.right = deleteNode(root.right, k)
        return root
 
    # We reach here when root is the node
    # to be deleted.
 
    # If one of the children is empty
    if root.left is None:
        temp = root.right
        del root
        return temp
    elif root.right is None:
        temp = root.left
        del root
        return temp
 
    # If both children exist
    else:
 
        succParent = root
 
        # Find successor
        succ = root.right
        while succ.left is not None:
            succParent = succ
            succ = succ.left
 
        # Delete successor.  Since successor
        # is always left child of its parent
        # we can safely make successor's right
        # right child as left of its parent.
        # If there is no succ, then assign
        # succ.right to succParent.right
        if succParent != root:
            succParent.left = succ.right
        else:
            succParent.right = succ.right
 
        # Copy Successor Data to root
        root.key = succ.key
 
        # Delete Successor and return root
        del succ
        return root
 
# Driver Code
if __name__ == '__main__':
    # Let us create following BST
    #          50
    #       /     \
    #      30      70
    #     /  \    /  \
    #   20   40  60   80
    root = None
    root = insert(root, 50)
    root = insert(root, 30)
    root = insert(root, 20)
    root = insert(root, 40)
    root = insert(root, 70)
    root = insert(root, 60)
 
    print("Original BST: ", end='')
    inorder(root)
 
    print("\n\nDelete a Leaf Node: 20")
    root = deleteNode(root, 20)
    print("Modified BST tree after deleting Leaf Node:")
    inorder(root)
 
    print("\n\nDelete Node with single child: 70")
    root = deleteNode(root, 70)
    print("Modified BST tree after deleting single child Node:")
    inorder(root)
 
    print("\n\nDelete Node with both child: 50")
    root = deleteNode(root, 50)
    print("Modified BST tree after deleting both child Node:")
    inorder(root)
