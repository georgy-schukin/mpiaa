#!/usr/bin/env python

import random


def read_file(file):
    data = []
    with open(file, "r") as f:
        data = f.read().splitlines()
    return data

	
def write_file(file, data):
    with open(file, "w") as f:
        for line in data:
            f.write(str(line) + "\n")	

def rand_item(items):
	return items[random.randint(0, len(items) - 1)]

			
if __name__ == "__main__":
	pass
