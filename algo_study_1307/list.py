class List():
	def __init__(self, data = None, next = None):
		self.data_ = data
		self.next_ = next

	def __iter__(self):
		return ListIter(self)

	def next(self):
		return self.next_

	def data(self):
		return self.data_

	def insert(self, index, data):
		# TODO: check length
		if self.data_ is None:
			self.data_ = data
			return
		elif index is 0:
			next = List(self.data_, self.next_)
			self.__init__(data, next)
			return 

		begin = List(None, self)
		it = begin
		for i in range(index):
			it = it.next()

		it.next_ = List(data, it.next_)
		return

	def find(self, data):
		t = self
		while t is not None:
			if t.data() == data:
				return t
			t = t.next()
		return None

class ListIter():
	def __init__(self, target):
		self.target = target
	def __next__(self):
		if self.target is None:
			raise StopIteration
		else:
			data = self.target.data()
			self.target = self.target.next()
			return data
	def next_iter(self):
		return self.target.next_.__iter__()


begin = List()
for i in range(10, 0, -1):
	begin.insert(0, i)

t = begin
while t is not None:
	print(t.data())
	t = t.next()
begin.insert(3,111)
t = begin
for i in t:
	print(i)

print(begin.find(5).data())