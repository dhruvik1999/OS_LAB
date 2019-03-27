from threading import Thread
from threading import Lock
import time

lock = Lock()
counter = 0
itr = 0

class WriterA(Thread):
  def run(self):
    while True:
        global lock
        global resource
        global counter
        global itr
        if counter == 0:
            lock.acquire()
            itr+=1
            print (itr,"              Writer ")
            
            time.sleep(0.5)
            lock.release()

class Reader(Thread):
        def run(self):
            while True:
                global resource
                global counter
                global lock
                global itr
                if counter >= 0:
                    itr+=1
                    print (itr,"Reader ")
                    counter += 1
                    time.sleep(0.2)
                    counter -=1
                              

writerA = WriterA()
reader1 = Reader()


writerA.start()
reader1.start()
