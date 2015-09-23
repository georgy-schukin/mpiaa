#!/usr/bin/env python

import sys
import random


def gen_seq(num, output, func):
	with open(output, "w") as f:
		for i in range(num):
			f.write(str(func(i, num)) + "\n")


def gen_linear_seq(num, output):
	gen_seq(num, output, lambda i,n: n - i)


def gen_rnd_seq(num, output):
	gen_seq(num, output, lambda i,n: random.randint(0, n))


def main():
	start = int(sys.argv[1]) if len(sys.argv) > 1 else 3
	end = int(sys.argv[2]) if len(sys.argv) > 2 else 6
	for p in range(start, end + 1):
		num = 10**p
		print("Generating {0} elements...".format(num))
		gen_linear_seq(num, "input_1e{0}.txt".format(p))
		gen_rnd_seq(num, "input_rnd_1e{0}.txt".format(p))


if __name__ == "__main__":
	main()
