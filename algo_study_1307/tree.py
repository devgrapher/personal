import unittest

class Tree:
	"""array based tree"""
	def __init__(self):
		self.nodes = [None] * 1000

	def add(self, value):
		exist, idx = self.findIndex(value)
		if exist:
			return False
		self.nodes[idx] = value
		return True

	def erase(self, value):
		exist, idx = self.findIndex(value)
		if not exist:
			return False
		self.nodes[idx] = None
		return True

	def find(self, value):
		return self.findIndex(value)[0]

	def findIndex(self, value):
		idx = 1
		while True:
			if self.nodes[idx] == None: 
				return False, idx
				break
			if self.nodes[idx] == value:
				return True, idx

			if self.nodes[idx] > value:
				idx = idx * 2 # left child
			else:
				idx = idx * 2 + 1 # right child

	def values(self):
		valueList = []
		self.__valuesDfs(1, valueList)
		return valueList

	def __valuesDfs(self, idx, valueList):
		if self.nodes[idx] == None: 
			return

		self.__valuesDfs(idx * 2, valueList)
		valueList.append(self.nodes[idx])
		self.__valuesDfs(idx * 2 + 1, valueList)


class TestTree(unittest.TestCase):
	"""TestTree"""
	def testMakeTree(self):
		tree = Tree()

	def testAdd(self):
		tree = Tree()
		self.assertTrue(tree.add(1))
		self.assertTrue(tree.add(2))
		self.assertTrue(tree.add(11))
		self.assertFalse(tree.add(2))

	def testFind(self):
		tree = Tree()
		tree.add(1)
		tree.add(2)
		self.assertTrue(tree.find(1))
		self.assertTrue(tree.find(2))
		tree.add(15)
		self.assertTrue(tree.find(15))
		self.assertFalse(tree.find(20))

	def testErase(self):
		tree = Tree()
		tree.add(100)
		tree.add(1)
		tree.add(10)
		self.assertTrue(tree.find(10))
		self.assertTrue(tree.erase(10))
		self.assertFalse(tree.find(10))
		self.assertFalse(tree.erase(10))

	def testValues(self):
		tree = Tree()
		sample = [10,20,1,2,3,5,8,22,99,98,6,97,1000]
		for n in sample:
			tree.add(n)
		sample.sort()
		self.assertEqual(sample, tree.values())


if __name__ == "__main__":
	unittest.main()		