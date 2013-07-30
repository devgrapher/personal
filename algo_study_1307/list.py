class List():
	def __init__(self, data):
		self.data_ = data
		self.next_ = None
	def __init__(self, data, next):
		self.data_ = data
		self.next_ = next
	def __iter__(self):
		return ListIter(self)
	def next(self):
		return self.next_
	def data(self):
		return self.data_
	def append(self, next):
		self.next_ = next
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


begin = None
for i in range(10, 0, -1):
	begin = List(i, begin)

t = begin
while t is not None:
	print(t.data())
	t = t.next()

t = begin
for i in t:
	print(i)

print(begin.find(5).data())