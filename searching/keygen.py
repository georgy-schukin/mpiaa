#!/usr/bin/env python

import sys
import random
from common import *


def random_char():
	return chr(random.randint(ord('a'), ord('z')))
	
	
def generate_key(surnames):
	surname = rand_item(surnames)
	addition = random_char() if not random.randint(0, 2) else ""
	return surname + addition		
	
	
def generate_keys(surnames, num):
	random.seed()
	return [generate_key(surnames) for i in range(num)]
	
	
def main():
	end = int(sys.argv[1]) if len(sys.argv) > 1 else 6
	surnames = read_file("../common/surnames.txt")	
	num_of_keys = 10**end
	keys_file = "keys.txt"
	print("Generating {0} keys into {1}...".format(num_of_keys, keys_file))
	write_file(keys_file, generate_keys(surnames, num_of_keys))


if __name__ == "__main__":
	main()
