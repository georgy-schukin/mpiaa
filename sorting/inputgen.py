#!/usr/bin/env python

import sys
import random


months = ["Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Sept", "Oct", "Nov", "Dec"]
days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def read_file(file):
    data = []
    with open(file, "r") as f:
        data = f.read().splitlines()
    return data

	
def write_file(file, data):
    with open(file, "w") as f:
        for line in data:
            f.write(str(line) + "\n")
			

def generate_date():
	year = 1900 + random.randint(0, 100)
	month = random.randint(1, len(months) - 1)
	day = random.randint(1, days_in_month[month])
	return "{0} {1} {2}".format(year, months[month], day)
	

def generate_record(names, surnames):
	name = names[random.randint(0, len(names) - 1)]
	surname = surnames[random.randint(0, len(surnames) - 1)]
	date = generate_date()
	return "{0} {1} {2}".format(name, surname, date)
			
			
def generate_records(names, surnames, num):
	random.seed()
	return [generate_record(names, surnames) for i in range(num)]
	
	
def main():
	start = int(sys.argv[1]) if len(sys.argv) > 1 else 3
	end = int(sys.argv[2]) if len(sys.argv) > 2 else 6
	names = read_file("names.txt")
	surnames = read_file("surnames.txt")	
	for p in range(start, end + 1):
		num = 10**p
		output_file = "input_1e{0}.txt".format(p)
		print("Generating {0} records into {1}...".format(num, output_file))
		records = generate_records(names, surnames, num)
		write_file(output_file, records)		


if __name__ == "__main__":
	main()
