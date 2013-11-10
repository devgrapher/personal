import unittest
from tree import Tree

class Node:
	left = None
	right = None
	value = None
	level = 0
	def __init__(self, value, level = 0):
		self.value = value
		self.level = level

class AvlTree:
	"""docstring for AvlTree"""
	def __init__(self, headValue = -1):
		self.head = Node(headValue)
		self.upperLv = 0
		self.lowerLv = 0

	def insert(self, value):
		node, parent = self.__find(value)
		if node is not None:
			return False
		newNode = Node(value, parent.level + 1)
		if parent.value > value:
			parent.left = newNode
		else:
			parent.right = newNode
		self.updateLevel(newNode.level)
		return True

	def updateLevel(self, node):
		pass

	def find(self, value):
		node, parent = self.__find(value)
		return node

	def __find(self, value):
		node = self.head
		prev = node
		while True:
			if node == None:
				return node, prev
			if node.value == value:
				return node, prev
			elif node.value > value:
				prev = node
				node = node.left
			else:
				prev = node
				node = node.right



class TestTree(unittest.TestCase):
	"""TestTree"""
	def testMakeTree(self):
		tree = AvlTree()

	def testInsert(self):
		tree = AvlTree()
		self.assertTrue(tree.insert(1))
		self.assertTrue(tree.insert(2))
		self.assertTrue(tree.insert(11))
		self.assertFalse(tree.insert(2))

	def testFind(self):
		tree = AvlTree()
		tree.insert(1)
		tree.insert(2)
		self.assertTrue(tree.find(1))
		self.assertTrue(tree.find(2))
		tree.insert(15)
		self.assertTrue(tree.find(15))
		self.assertFalse(tree.find(20))

	def testCalcLevels(self):
		tree = AvlTree()

	def testLevel(self):
		tree = AvlTree()
		tree.insert(10)
		tree.insert(20)
		self.assertEqual(tree.find(10).level, 1)
		self.assertEqual(tree.find(20).level, 2)

	def testLevelBounds(self):
		tree = AvlTree()
		tree.insert(10)
		tree.insert(20)
		self.assertEqual(tree.upperLv, 1)
		self.assertEqual(tree.lowerLv, 2)
		


if __name__ == "__main__":
	unittest.main()		