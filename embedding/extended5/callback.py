import time
import threading

time_to_sleep = 0.5


# default callback function that prints its name
def default_callback():
    print("... default_callback")


# variable to hold the current callback function
callback = default_callback


# function to set the callback
def set_callback(new_callback):
    global callback
    callback = new_callback


# flag to control the loop in call_callback
keep_running = True

def start():
    t = threading.Thread(target=run)
    t.start()


# function to call the callback every second
def run():
    global keep_running
    global time_to_sleep
    while keep_running:
        callback()
        time.sleep(time_to_sleep)


# function to stop the callback loop
def stop():
    global keep_running
    keep_running = False


# if __name__ == '__main__':
#     pass
#
