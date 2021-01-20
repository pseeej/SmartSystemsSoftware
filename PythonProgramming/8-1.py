class Counter:
    def reset(self):
        self.count = 0
    def increment(self):
        self.count += 1
    def get(self):
        return self.count

a = Counter()
a.reset()
a.increment()
print("카운터 a의 값은", a.get())
