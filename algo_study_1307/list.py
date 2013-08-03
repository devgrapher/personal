import unittest

class List():
	def __init__(self, data = None, next = None):
		self.data = data
		self.next = next
		self.length = 0

	def __iter__(self):
		if self.data is None:
			return ListIter(self.next)
		else:
			return ListIter(self)

	def __len__(self):
		return self.length

	def insert(self, index, data):
		if index > len(self): 
			raise IndexError

		it = self
		for i in range(index):
			it = it.next

		it.next = List(data, it.next)
		self.length += 1
		return iter(it.next)

	def erase(self, index):
		if index > len(self): 
			raise IndexError

		if index is 0:
			if self.next is None:
				self.data = None #비어있는 HEAD로 만듬.
			else:
				self.next = self.next.next
		else:
			prev_it = self.index(index - 1)
			prev_it.pointee.next = prev_it.pointee.next.next

		self.length -= 1

	def find(self, data):
		it = self
		while it is not None:
			if it.data == data:
				return it
			it = it.next
		return None

	def index(self, index):
		if index > len(self): 
			raise IndexError

		it = iter(self)
		for i in range(index):
			it = it.next()
		return it


class ListIter():
	def __init__(self, pointee):
		self.pointee = pointee

	def __next__(self):
		if self.pointee is None:
			raise StopIteration
		else:
			data = self.pointee.data
			self.pointee = self.pointee.next
			return data

	def next(self):
		if self.pointee.next is None:
			return None
		else:
			return iter(self.pointee.next)

	def data(self):
		return self.pointee.data


class TestList(unittest.TestCase):
	def setUp(self):
		self.list = List()
		for i in range(10, 0, -1):
			self.list.insert(0, i)

	def test_while_roop(self):
		it = iter(self.list)
		while it.next() is not None:
			print(it.data())
			it = it.next()
		print(it.data())

	def test_for_roop(self):
		for i in self.list:
			print(i)

	def test_find(self):
		for i in [1,2,3,4,5,6,7,8,9,10]:
			found = self.list.find(i)
			self.assertIsNotNone(found)
			self.assertEqual(found.data, i)

		for i in [0,11,-1,"wrong"]:
			found = self.list.find(i)
			self.assertIsNone(found)

	def test_insert(self):
		self.list.insert(0, -1)
		self.assertTrue(equal_with_builtin(self.list, [-1,1,2,3,4,5,6,7,8,9,10]))

		self.list.insert(5, -2)
		self.assertTrue(equal_with_builtin(self.list, [-1,1,2,3,4,-2,5,6,7,8,9,10]))

		self.list.insert(12, -3)
		self.assertTrue(equal_with_builtin(self.list, [-1,1,2,3,4,-2,5,6,7,8,9,10,-3]))

	def test_erase(self):
		self.list.erase(0)
		self.assertTrue(equal_with_builtin(self.list, [2,3,4,5,6,7,8,9,10]))

		self.list.erase(0)
		self.assertTrue(equal_with_builtin(self.list, [3,4,5,6,7,8,9,10]))

		self.list.erase(1)
		self.assertTrue(equal_with_builtin(self.list, [3,5,6,7,8,9,10]))

		self.list.erase(6)
		self.assertTrue(equal_with_builtin(self.list, [3,5,6,7,8,9]))

		while len(self.list):
			self.list.erase(0)
		self.assertTrue(equal_with_builtin(self.list, []))
		self.assertEqual(self.list.data, None)


class TestSampleData(unittest.TestCase):
	def test_sample1(self):
		self.list = List()
		sample = ["google","naver","daum","nate","zum"]
		for i in sample:
			self.list.insert(0, i)

		sample.reverse()
		for i in range(len(sample)):
			self.assertEqual(self.list.index(i).data(), sample[i])

		print(" ".join(sample))


def equal_with_builtin(testee, builtin):
	'''빌트인 리스트와 내용이 같은지 비교'''
	if len(testee) is not len(builtin):
		return False

	for i in range(len(builtin)):
		if testee.index(i).data() != builtin[i]:
			return False

	return True


if __name__ == "__main__":	
	unittest.main()
