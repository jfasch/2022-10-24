def debug(f):
    def wrapper(*args, **kwargs):
        print(f.__name__, args, kwargs)
        f(*args, **kwargs)

    return wrapper

@debug
def do_something(msg):
    print(msg)

@debug
def add(l, r):
    return l+r

do_something('hello')    
add(1,2)
add(l=1,r=2)
