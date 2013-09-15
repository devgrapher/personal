import unittest
from tree import Tree

class AvlTree(Tree):
	"""docstring for AvlTree"""
	def __init__(self):
		super(AvlTree, self).__init__()


class TestTree(unittest.TestCase):
	"""TestTree"""
	def testMakeTree(self):
		tree = AvlTree()

	def testAdd(self):
		tree = AvlTree()
		self.assertTrue(tree.add(1))
		self.assertTrue(tree.add(2))
		self.assertTrue(tree.add(11))
		self.assertFalse(tree.add(2))

	def testFind(self):
		tree = AvlTree()
		tree.add(1)
		tree.add(2)
		self.assertTrue(tree.find(1))
		self.assertTrue(tree.find(2))
		tree.add(15)
		self.assertTrue(tree.find(15))
		self.assertFalse(tree.find(20))



if __name__ == "__main__":
	unittest.main()		