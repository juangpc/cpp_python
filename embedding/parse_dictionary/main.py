import time
import parsing
from data import data

# print("Time now: ", time.ctime(time.process_time_ns()))

A = {'keyA': 32,
     'keyB': "juan",
     'keyC': {"bla": 33}
     }
# print(type(A))

# print(data)

def parse_python(data_in):
    d_parsed = []
    for k in data_in['data_frames']:
        label = data_in['data_frames'][k]['sensor']
        value = data_in['data_frames'][k]['data']
        d_parsed.append({'label': label, 'value': value})
        # print(d_parsed[-1])


st1 = time.process_time_ns()
parsing.dict_parser(data)
et1 = time.process_time_ns()
print("Execution time varargs: ", et1 - st1)


st2 = time.process_time_ns()
parse_python(data)
et2 = time.process_time_ns()
print("Execution time python:", et2 - st2)


# st1 = time.process_time_ns()
# print(st1)
# parsing.dict_parser_varargs(22, A)
# et1 = time.process_time_ns()
# print("Execution time varargs: ", et1 - st1)
#
# st2 = time.process_time_ns()
# parsing.dict_parser_fastcall(22, A)
# et2 = time.process_time_ns()
# print("Execution time fastcall:", et2 - st2)
