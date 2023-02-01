from threading import Thread
from time import sleep


def noop():
    pass


callback = noop
stop = False


def set_callback(fcn):
    global callback
    callback = fcn


def callback_caller(time_between_calls):
    while not stop:
        callback()
        sleep(time_between_calls)


thread = Thread(target=callback_caller, args=(1,))


def start_calls():
    global thread
    thread.start()


def stop_calls():
    global thread
    global stop
    # thread.join()
    stop = True
