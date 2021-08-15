import sys


OFFSET = 0x1E8


def main():
	if len(sys.argv) != 4:
		print(f'Usage: {sys.argv[0]} <base> <add> <out>')
		return -1
	base_filename = sys.argv[1]
	add_filename = sys.argv[2]
	out_filename = sys.argv[3]
	with open(base_filename, 'rb') as f:
		base_data = f.read()
	with open(add_filename, 'rb') as f:
		add_data = f.read()
	
	tmp = list(base_data)
	for i in range(len(add_data)):
		tmp[i + OFFSET] = add_data[i]
	
	with open(out_filename, 'wb') as f:
		f.write(bytes(tmp))
	
	return 0


if __name__ == '__main__':
	main()
