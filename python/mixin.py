
class MappingMixin:
    def __getitem__(self, key):
        return self.__dict__.get(key)
    
    def __setitem__(self, key, value):
        return self.__dict__.set(key, value)

class ReprMixin:

    def __repr__(self):
        s = self.__class__.__name__ + '('
        for k, v in self.__dict__.items():
            if not k.startswith('_'):
                s += '{}={},'.format(k, v)
        s = s.rstrip(',') + ')'
        return s

class Person(MappingMixin):
    def __init__(self, name, gender, age):
        self.name = name
        self.gender = gender
        self.age = age
    
p = Person("小陈", "男", 18)
print(p.name)
