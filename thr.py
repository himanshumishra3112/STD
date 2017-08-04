#!/usr/bin/python

import thread
import time
import sys

def thread1(a,b):
    print "thread1"
    print a+b

def thread2(a,b):
    print "thread2"
    print a-b


def main():
    a=10
    b=20

    try:
        thread.start_new_thread(thread1,(a,b))
	time.sleep(2)
        thread.start_new_thread(thread2,(a,b))
	time.sleep(2)
    except:
	print "Error"


if __name__ == '__main__':
    main()
