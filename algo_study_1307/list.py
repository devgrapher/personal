import unittest

class List():
	def __init__(self, data = None, next = None):
		self.data = data # data가 None이면 Head로 취급
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
		if index is 0:
			current = self.next
			self.next = List(data, self.next)
		else:
			prev = self.iter(index - 1)
			prev.pointee.next = List(data, prev.pointee.next)

		self.length += 1

	def erase(self, index):
		if index is 0:
			if self.next is None:
				self.data = None #비어있는 HEAD로 만듬.
			else:
				self.next = self.next.next
		else:
			prev = self.iter(index - 1)
			prev.pointee.next = prev.pointee.next.next

		self.length -= 1

	def find(self, data):
		it = self
		while it is not None:
			if it.data == data:
				return it
			it = it.next
		return None

	def iter(self, index):
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

	def __iter__(self):
		"pointee.data를 문자열로 출력할 수 있는 iter를 만든다. "
		return ListStrIter(self.pointee)

	def next(self):
		if self.pointee.next is None:
			return None
		else:
			return iter(self.pointee.next)

	def data(self):
		return self.pointee.data


class ListStrIter():
	def __init__(self, pointee):
		self.pointee = pointee

	def __next__(self):
		if self.pointee is None:
			raise StopIteration
		else:
			data = self.pointee.data
			self.pointee = self.pointee.next
			return str(data)


class TestList(unittest.TestCase):
	def setUp(self):
		self.testee = List()
		for i in range(10, 0, -1):
			self.testee.insert(0, i)

		print(" ".join(self.testee))

	def test_while_roop(self):
		it = iter(self.testee)
		while it.next() is not None:
			print(it.data())
			it = it.next()
		print(it.data())

	def test_for_roop(self):
		for i in self.testee:
			print(i)

	def test_find(self):
		for i in [1,2,3,4,5,6,7,8,9,10]:
			found = self.testee.find(i)
			self.assertIsNotNone(found)
			self.assertEqual(found.data, i)

		for i in [0,11,-1,"wrong"]:
			found = self.testee.find(i)
			self.assertIsNone(found)

	def test_insert(self):
		self.testee.insert(0, -1)
		self.assertTrue(equal_with_builtin(self.testee, [-1,1,2,3,4,5,6,7,8,9,10]))

		self.testee.insert(5, -2)
		self.assertTrue(equal_with_builtin(self.testee, [-1,1,2,3,4,-2,5,6,7,8,9,10]))

		self.testee.insert(12, -3)
		self.assertTrue(equal_with_builtin(self.testee, [-1,1,2,3,4,-2,5,6,7,8,9,10,-3]))

	def test_erase(self):
		self.testee.erase(0)
		self.assertTrue(equal_with_builtin(self.testee, [2,3,4,5,6,7,8,9,10]))

		self.testee.erase(0)
		self.assertTrue(equal_with_builtin(self.testee, [3,4,5,6,7,8,9,10]))

		self.testee.erase(1)
		self.assertTrue(equal_with_builtin(self.testee, [3,5,6,7,8,9,10]))

		self.testee.erase(6)
		self.assertTrue(equal_with_builtin(self.testee, [3,5,6,7,8,9]))

		while len(self.testee):
			self.testee.erase(0)
		self.assertTrue(equal_with_builtin(self.testee, []))
		self.assertEqual(self.testee.data, None)


class TestSampleData(unittest.TestCase):
	def test_sample1(self):
		self.testee = List()
		sample = ["google","naver","daum","nate","zum"]
		for i in sample:
			self.testee.insert(0, i)

		sample.reverse()
		for i in range(len(sample)):
			self.assertEqual(self.testee.iter(i).data(), sample[i])

		print(" ".join(sample))


def equal_with_builtin(testee, builtin):
	'''빌트인 리스트와 내용이 같은지 비교'''
	if len(testee) is not len(builtin):
		return False

	for i in range(len(builtin)):
		if testee.iter(i).data() != builtin[i]:
			return False

	return True


if __name__ == "__main__":	
	unittest.main()
