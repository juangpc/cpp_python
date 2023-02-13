from time import time, ctime
import parsing

print("Time now: ", ctime(time()))


A = {'keyA': 32,
     'keyB': "juan"}

parsing.dict_parser(A)
