import threading
import time


def example_callback1():
    with open("test.txt", "w", encoding="utf-8") as file:
        file.write("appending from example_callback1\n")


def example_callback2():
    with open("test.txt", "w", encoding="utf-8") as file:
        file.write("appending from example_callback2\n")


def example_callback3(arg1):
    with open("test.txt", "w", encoding="utf-8") as file:
        file.write("appending from example_callback2" + str(arg1) + "\n")


callback = example_callback1
callback_lock = threading.Lock()
worker_continue = True
worker_continue_lock = threading.Lock()

def get_callback():
    global callback
    callback_lock.acquire()
    local_cpy = callback
    callback_lock.release()
    return local_cpy

def set_callback(call):
    global callback
    callback_lock.acquire()
    callback = call
    callback_lock.release()


def thread_continue(*args):
    global worker_continue
    if len(args) == 0:
        worker_continue_lock.acquire()
        local_copy_worker_continue = worker_continue
        worker_continue_lock.release()
        return local_copy_worker_continue
    if len(args) == 1:
        worker_continue_lock.acquire()
        worker_continue = args[0]
        worker_continue_lock.release()
        return args[0]

def thread_work():
    while thread_continue():
        # print("hello!")
        calling = get_callback()
        calling()
        time.sleep(1)


def start_thread():
    worker_thread = threading.Thread(target=thread_work)
    worker_thread.start()
    # worker_thread.join()


thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
