# Da rivedere dopo aver seguito la lezione

from module_two import g

def f(x, y=10):
    return x + y

if __name__ == "__main__":
    print(f(2))
    print(f(g(2)))