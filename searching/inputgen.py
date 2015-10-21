#!/usr/bin/env python

import sys
import random
from common import *

			
def generate_record(names, surnames):
	name = rand_item(names)
	surname = rand_item(surnames)
	age = random.randint(1, 100)	
	return "{0} {1} {2}".format(name, surname, age)
			
			
def generate_records(names, surnames, num):
	random.seed()
	return [generate_record(names, surnames) for i in range(num)]
		
	
def main():
	start = int(sys.argv[1]) if len(sys.argv) > 1 else 3
	end = int(sys.argv[2]) if len(sys.argv) > 2 else 6
	names = read_file("../common/names.txt")
	surnames = read_file("../common/surnames.txt")	
	for p in range(start, end + 1):
		num = 10**p
		output_file = "input_1e{0}.txt".format(p)
		print("Generating {0} records into {1}...".format(num, output_file))
		write_file(output_file, generate_records(names, surnames, num))	


if __name__ == "__main__":
	main()
