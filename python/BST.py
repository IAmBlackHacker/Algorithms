from collections import namedtuple
Node=namedtuple('Node','value left right')
class BST():
	def __init__(self):
		self.root=None
	def createNode(self,value):
		n=Node(value,None,None)
		return n
	def addNode(self,node,root):
		if root[0]==None:
			root[0]=node
		elif node.value>root[0].value:
			self.addNode(node,[root[0].right])
		else:
			self.addNode(node,[root[0].left])
	def add(self):
		value=input('Enter Value of Node : ')
		self.addNode(self.createNode(value),[self.root])
	def printBST(self,root):
		if not root:
			return
		print(root.value)
		self.printBST(root.right)
		self.printBST(root.left)
b=BST()
b.add()
b.add()
b.printBST(b.root)